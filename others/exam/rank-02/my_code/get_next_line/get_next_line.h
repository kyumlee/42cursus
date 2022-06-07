#ifndef _GET_NEXT_LINE_H_
# define _GET_NEXT_LINE_H_
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 1

int		ft_strlen(char *s);
char	*ft_strncpy(char *dst, char *src, int n);
char	*ft_strncat(char *dst, char *src, int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_split(char **line, char *s_buf);
int		get_next_line(char **line);

#endif
