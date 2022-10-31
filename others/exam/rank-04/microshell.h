#ifndef __MICRO_SHELL_H__
# define __MICRO_SHELL_H__

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <string.h>

# define TYPE_DEFAULT	0
# define TYPE_EOL		1
# define TYPE_BREAK		2
# define TYPE_PIPE		3

typedef struct	s_list {
	char			**argv;
	int				size;
	int				type;
	int				fd[2];
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

// string-related functions
int		ft_strlen(char *s);
char	*ft_strdup(char *s);

// write functions
void	ft_putstr_fd(int fd, char *s);
void	ft_putendl_fd(int fd, char *s);

// error functions
int		cd_bad_args(void);
int		cd_chdir_err(char *path);
void	fata_err(void);
void	execve_err(char *path);

// list add back
void	ft_lstadd_back(t_list **info, t_list *new_node);

// t_list-related functions
int		get_argv_len(char **argv);
int		get_arg_type(char *arg);
int		parse_argv(t_list **info, char **argv);

// execute functions
void	execute_cd(t_list *info);
void	execute_rest(t_list *info, char **envp);
void	execute(t_list *info, char **envp);

// free list
void	free_all(t_list *info);

#endif
