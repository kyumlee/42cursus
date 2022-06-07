/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyumlee <kyumlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 22:35:29 by kyumlee           #+#    #+#             */
/*   Updated: 2021/07/24 18:36:57 by kyumlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

/* utils.c */
void			ft_error(char *s, char *name);
int				ft_strlen(char *s);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
/* ft_split.c */
char			**ft_split(char const *s, char c);
/* get_cmd_path.c */
char			*ft_strjoin(char *s1, char *s2);
char			**get_path(char **s, char *cmd);

#endif
