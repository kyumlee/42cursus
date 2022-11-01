#include "./microshell.h"
#include <stdio.h>

int		ft_strlen(char *s) {
	if (!s)
		return (0);
	int	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(int fd, char *s, int nl) {
	write(fd, s, ft_strlen(s));
	if (nl == 1)
		write(fd, "\n", 1);
}

int		cd_bad_args(void) {
	ft_putstr_fd(2, "error: cd: bad arguments", 1);
	return (EXIT_FAILURE);
}

int		cd_chdir_err(char *path) {
	ft_putstr_fd(2, "error: cd: cannot change directory to ", 0);
	ft_putstr_fd(2, path, 1);
	return (EXIT_FAILURE);
}

void	fatal_err(void) {
	ft_putstr_fd(2, "error: fatal", 1);
	exit(EXIT_FAILURE);
}

void	execve_err(char *path) {
	ft_putstr_fd(2, "error: cannot execute ", 0);
	ft_putstr_fd(2, path, 1);
	exit(EXIT_FAILURE);
}

char	*ft_strdup(char *s) {
	if (!s)
		return (0);

	char	*ret = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (0);
	for (int i = 0; i < ft_strlen(s); i++)
		ret[i] = s[i];
	ret[ft_strlen(s)] = 0;
	return (ret);
}

void	ft_lstadd_back(t_list **info, t_list *new) {
	if (!info || !new)
		return ;
	if (!*info) {
		*info = new;
		return ;
	}
	t_list	*node = *info;

	while (node->next != 0)
		node = node->next;
	node->next = new;
	new->prev = node;
}

void	set_len_type(char **argv, int *len, int *type) {
	int	i = 0;
	while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
		i++;

	if (!argv[i])
		*type = EOL;
	else if (!strcmp(argv[i], ";"))
		*type = BREAK;
	else if (!strcmp(argv[i], "|"))
		*type = PIPE;
	else
		*type = DEFAULT;
	*len = i;
}

int		parse_argv(t_list **info, char **argv) {
	int		len, type;
	set_len_type(argv, &len, &type);

	t_list	*new;
	if (!(new = malloc(sizeof(t_list))))
		fatal_err();
	if (!(new->argv = malloc(sizeof(char *) * (len + 1))))
		fatal_err();

	new->size = len;
	new->type = type;
	new->argv[len] = 0;
	new->prev = 0;
	new->next = 0;

	for (int i = 0; i < len; i++)
		new->argv[i] = ft_strdup(argv[i]);

	ft_lstadd_back(info, new);

	return (len);
}

void	execute_cd(t_list *info) {
	if (info->size < 2)
		cd_bad_args();
	else if (chdir(info->argv[1]))
		cd_chdir_err(info->argv[1]);
}

void	execute_rest(t_list *info, char **envp) {
	int		pipe_open = 0;

	if (info->type == PIPE || (info->prev && info->prev->type == PIPE)) {
		pipe_open = 1;
		if (pipe(info->fd))
			fatal_err();
	}

	int		status;
	pid_t	pid = fork();
	if (pid == -1)
		fatal_err();
	else if (!pid) {
		if (info->type == PIPE && dup2(info->fd[1], 1) == -1)
			fatal_err();
		if (info->prev && info->prev->type == PIPE && dup2(info->prev->fd[0], 0) == -1)
			fatal_err();
		if (execve(info->argv[0], info->argv, envp) == -1)
			execve_err(info->argv[0]);
		exit(EXIT_SUCCESS);
	}
	else {
		waitpid(pid, &status, 0);
		if (pipe_open) {
			close(info->fd[1]);
			if (!info->next || info->type == BREAK)
				close(info->fd[0]);
		}
		if (info->prev && info->prev->type == PIPE)
			close(info->prev->fd[0]);
	}
}

void	execute(t_list *info, char **envp) {
	t_list	*tmp = info;

	while (tmp) {
		if (!strcmp("cd", tmp->argv[0]))
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
	info = 0;
}

int		main(int argc, char **argv, char **envp) {
	if (argc < 2)
		return (0);

	t_list	*info = 0;

	for (int i = 1; i < argc; i++) {
		if (!strcmp(argv[i], ";"))
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
