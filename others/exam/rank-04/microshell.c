#include "./microshell.h"

int		ft_strlen(char *s) {
	if (!s)
		return (0);
	int	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(int fd, char *s) {
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(int fd, char *s) {
	ft_putstr_fd(fd, s);
	ft_putstr_fd(fd, "\n");
}

int		cd_bad_args(void) {
	ft_putendl_fd(STDERR_FILENO, "error: cd: bad arguments");
	return (EXIT_FAILURE);
}

int		cd_chdir_err(char *path) {
	ft_putstr_fd(STDERR_FILENO, "error: cd: cannot change directory to ");
	ft_putendl_fd(STDERR_FILENO, path);
	return (EXIT_FAILURE);
}

void	fatal_err(void) {
	ft_putendl_fd(STDERR_FILENO, "error: fatal");
	exit(EXIT_FAILURE);
}

void	execve_err(char *path) {
	ft_putstr_fd(STDERR_FILENO, "error: cannot execute ");
	ft_putendl_fd(STDERR_FILENO, path);
	exit(EXIT_FAILURE);
}

char	*ft_strdup(char *s) {
	char	*ret = malloc(sizeof(char) * (ft_strlen(s)));
	if (!ret)
		fatal_err();

	for (int i = 0; i < ft_strlen(s); i++)
		ret[i] = s[i];
	return (ret);
}

void	ft_lstadd_back(t_list **info, t_list *new) {
	if (info == NULL || new == NULL)
		return ;
	if (*info == NULL)
		*info = new;
	else {
		t_list	*node = *info;

		while (node->next != NULL)
			node = node->next;
		node->next = new;
		new->prev = node;
	}
}

int		get_argv_len(char **argv) {
	int	i = 0;
	while (argv[i] && (strcmp(argv[i], "|") || strcmp(argv[1], ";")))
		i++;
	return (i);
}

int		get_arg_type(char *arg) {
	if (!arg)
		return (TYPE_EOL);
	if (strcmp(arg, ";") == 0)
		return (TYPE_BREAK);
	if (strcmp(arg, "|") == 0)
		return (TYPE_PIPE);
	return (TYPE_DEFAULT);
}

int		parse_argv(t_list **info, char **argv) {
	int		len = get_argv_len(argv);
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		fatal_err();

	if (!(new->argv = malloc(sizeof(char *) + (len + 1))))
		fatal_err();

	new->size = len;
	new->argv[len] = NULL;
	new->prev = NULL;
	new->next = NULL;

	for (int i = 0; i < len; i++)
		new->argv[i] = ft_strdup(argv[i]);

	new->type = get_arg_type(argv[len]);

	ft_lstadd_back(info, new);

	return (len);
}

void	execute_cd(t_list *info) {
	if (info->size != 2)
		cd_bad_args();
	else if (chdir(info->argv[1]))
		cd_chdir_err(info->argv[1]);
}

void	execute_rest(t_list *info, char **envp) {
	pid_t	pid;
	int		status;
	int		pp;

	pp = 0;
	if (info->type == TYPE_PIPE || (info->prev && info->prev->type == TYPE_PIPE)) {
		pp = 1;
		if (pipe(info->fd))
			fatal_err();
	}

	pid = fork();
	if (pid < 0)
		fatal_err();
	else if (!pid) {
		if (info->type == TYPE_PIPE && dup2(info->fd[STDOUT_FILENO], STDOUT_FILENO) < 0)
			fatal_err();
		if (info->prev && info->prev->type == TYPE_PIPE && dup2(info->prev->fd[STDIN_FILENO], STDIN_FILENO) < 0)
			fatal_err();
		if (execve(info->argv[0], info->argv, envp) < 0)
			execve_err(info->argv[0]);
		exit(EXIT_SUCCESS);
	}
	else {
		waitpid(pid, &status, 0);
		if (pp) {
			close(info->fd[STDOUT_FILENO]);
			if (!info->next || info->type == TYPE_BREAK)
				close(info->fd[STDIN_FILENO]);
		}
		if (info->prev && info->prev->type == TYPE_PIPE)
			close(info->prev->fd[STDIN_FILENO]);
	}
}

void	execute(t_list *info, char **envp) {
	t_list	*tmp = info;

	while (tmp) {
		if (strcmp("cd", tmp->argv[0]) == 0)
			execute_cd(info);
		else
			execute_rest(tmp, envp);
		tmp = tmp->next;
	}
}

void	free_all(t_list *info) {
	t_list	*tmp;

	while (info) {
		tmp = info->next;
		for (int i = 0; i < info->size; i++)
			free(info->argv[i]);
		free(info->argv);
		free(info);
		info = tmp;
	}
	info = NULL;
}

int		main(int argc, char **argv, char **envp) {
	if (argc < 2)
		return (0);

	t_list	*info = NULL;

	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], ";") == 0)
			continue ;
		i += parse_argv(&info, &argv[i]);
		if (!argv[i])
			break ;
	}
	if (info)
		execute(info, envp);

	free_all(info);

	return (0);
}
