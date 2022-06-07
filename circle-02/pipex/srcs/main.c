/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:07:26 by kyumlee           #+#    #+#             */
/*   Updated: 2021/07/24 19:17:19 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

void	read_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("no such file or directory", file);
	if (dup2(fd, 0) == -1)
		ft_error("dup2 failed", 0);
	close(fd);
}

void	write_file(char *file)
{
	int	fd;

	fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		ft_error("no such file or directory", file);
	if (dup2(fd, 1) == -1)
		ft_error("dup2 failed", 0);
	close(fd);
}

void	connect_pipe(int pfd[2], int io)
{
	if (dup2(pfd[io], io) == -1)
		ft_error("dup2 failed", 0);
	close(pfd[0]);
	close(pfd[1]);
}

void	exec_cmd(char **envp, char *s)
{
	int		i;
	char	**tmp;
	char	**cmd;

	i = 0;
	tmp = ft_split(s, ' ');
	cmd = get_path(envp, tmp[0]);
	while (cmd[i])
	{
		execve(cmd[i], (char *const *)tmp, envp);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		pfd[2];
	int		status;
	pid_t	pid;

	if (argc != 5 || !argv[2][0] || !argv[3][0])
		ft_error("Wrong number of arguments", 0);
	pipe(pfd);
	pid = fork();
	if (pid > 0)
	{
		waitpid(pid, &status, WNOWAIT);
		write_file(argv[4]);
		connect_pipe(pfd, 0);
		exec_cmd(envp, argv[3]);
	}
	else if (pid == 0)
	{
		read_file(argv[1]);
		connect_pipe(pfd, 1);
		exec_cmd(envp, argv[2]);
	}
	else if (pid < 0)
		ft_error("Fork falied", 0);
	return (0);
}
