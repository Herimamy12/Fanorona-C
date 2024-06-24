/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:15:53 by nirirako@         #+#    #+#             */
/*   Updated: 2024/03/06 10:15:55 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr1(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_left_string(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	i++;
	s = ft_substr1(str, i, ft_strlen1(str + i));
	free(str);
	str = NULL;
	if (!s)
		return (NULL);
	return (s);
}

char	*ft_read_line(int fd, int buf_size)
{
	char	*tmp;
	char	*s;
	int		read_fd;

	tmp = (char *)malloc((buf_size + 1) * sizeof(char));
	s = NULL;
	if (!tmp)
		return (NULL);
	read_fd = 1;
	while (read_fd != 0)
	{
		read_fd = read(fd, tmp, buf_size);
		if (read_fd == -1 || read_fd == 0)
			break ;
		tmp[read_fd] = 0;
		s = ft_append(s, tmp);
		if (ft_strchr1(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;
	char		*temp;

	if (!ft_strchr1(str, '\n'))
	{
		temp = ft_read_line(fd, BUFFER_SIZE);
		if (temp)
		{
			str = ft_append(str, temp);
			free(temp);
			temp = NULL;
		}
	}
	if (!str)
		return (NULL);
	if (!*str)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	line = ft_extract(str, '\n');
	str = ft_left_string(str);
	return (line);
}
