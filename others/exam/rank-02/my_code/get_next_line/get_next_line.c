#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i = 0;

	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dst, char *src, int n)
{
	int		i = 0;

	if (!dst && !src)
		return (0);
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_strncat(char *dst, char *src, int n)
{
	int		i = 0;
	int		j = ft_strlen(dst);

	if (!dst && !src)
		return (0);
	while (src[i] && i < n)
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i + j] = 0;
	return (dst);
}

char	*join(char *s1, char *s2)
{
	char	*ret;
	int		s1_len = ft_strlen(s1);
	int		s2_len = ft_strlen(s2);

	if (!s1 && !s2)
		return (0);
	ret = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!s1_len)
		ft_strncpy(ret, s2, s2_len);
	else
	{
		ft_strncpy(ret, s1, s1_len);
		ft_strncat(ret, s2, s2_len);
	}
	free(s1);
	return (ret);
}

char	*get_line(char *s)
{
	char	*ret;
	int		i = 0;

	if (!s)
		return (0);
	while (s[i] != '\n')
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (0);
	ft_strncpy(ret, s, i);
	return (ret);
}

char	*get_save(char *s)
{
	char	*ret;
	int		i = 0;
	
	if (!s)
		return (0);
	while (s[i] != '\n')
		i++;
	ret = malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!ret)
		return (0);
	if (!s[i])
	{
		free(ret);
		return (0);
	}
	ft_strncpy(ret, &s[i + 1], ft_strlen(s) - i);
	free(s);
	return (ret);
}

int	get_next_line(char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*save;
	int			size = 1;

	if (!line || BUFFER_SIZE < 1)
		return (-1);
	while (size && buf[0] != '\n')
	{
		size = read(0, buf, BUFFER_SIZE);
		if (size == -1)
			return (-1);
		buf[size] = 0;
		save = join(save, buf);
	}
	*line = get_line(save);
	save = get_save(save);
	if (!save)
		free(save);
	if (size == 0)
		return (0);
	return (1);
}
