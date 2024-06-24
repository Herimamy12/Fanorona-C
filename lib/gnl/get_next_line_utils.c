/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:18:20 by nirirako@         #+#    #+#             */
/*   Updated: 2024/03/06 10:18:20 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen1(char const *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}

size_t	ft_strlcpy1(char *dst, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (dst == NULL || src == NULL)
		return (0);
	if (size == 0)
		return (ft_strlen1(src));
	while (index < size - 1 && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	while (src[index])
		index++;
	return (index);
}

char	*ft_append(char *str, char const *s)
{
	size_t	l1;
	size_t	l2;
	char	*string;

	if (!s)
		return (NULL);
	l1 = ft_strlen1(str);
	l2 = ft_strlen1(s);
	string = (char *)malloc((l1 + l2 + 1) * sizeof(char));
	if (!string)
		return (NULL);
	if (str != NULL)
	{
		ft_strlcpy1(string, str, l1 + 1);
		free(str);
	}
	ft_strlcpy1(string + l1, s, l2 + 1);
	return (string);
}

char	*ft_substr1(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen1(s + start);
	if (start > ft_strlen1(s))
		l = 0;
	if (l > len)
		l = len;
	str = (char *)malloc((l + 1) * sizeof(char));
	if (!str)
		return (str);
	ft_strlcpy1(str, s + start, l + 1);
	return (str);
}

char	*ft_extract(char *str, char c)
{
	char	*s;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != c)
		i++;
	s = (char *)malloc((i + 1 + 1) * sizeof(char));
	if (!s)
		return (NULL);
	ft_strlcpy1(s, str, i + 1 + 1);
	return (s);
}
