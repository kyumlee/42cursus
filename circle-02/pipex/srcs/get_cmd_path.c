/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:46:15 by kyumlee           #+#    #+#             */
/*   Updated: 2021/07/24 18:40:09 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*ret;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (s1_len + s2_len + 2));
	if (!ret)
		ft_error("Malloc failed", 0);
	ft_strncpy(ret, s1, s1_len);
	ret[s1_len] = '/';
	ft_strncpy(&ret[s1_len + 1], s2, s2_len);
	free(s1);
	return (ret);
}

void	check_path(char **path, char *cmd)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (!access(path[i], F_OK))
			return ;
		i++;
	}
	ft_error("command not found", cmd);
}

char	**get_path(char **s, char *cmd)
{
	char	**ret;
	char	*tmp;
	int		i;

	i = 0;
	while (ft_strncmp(s[i], "PATH=", 5))
		i++;
	tmp = malloc(sizeof(char) * ft_strlen(s[i]) - 5);
	if (!tmp)
		return (0);
	ft_strncpy(tmp, &s[i][5], ft_strlen(s[i]) - 5);
	ret = ft_split(tmp, ':');
	free(tmp);
	i = 0;
	while (ret[i])
	{
		ret[i] = ft_strjoin(ret[i], cmd);
		i++;
	}
	check_path(ret, cmd);
	return (ret);
}
