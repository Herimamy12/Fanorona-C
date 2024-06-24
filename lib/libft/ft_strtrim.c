/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:00:48 by nirirako@         #+#    #+#             */
/*   Updated: 2024/02/27 14:55:34 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_in_set(char const c, char const *s)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	n;
	size_t	l;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	l = ft_strlen(s1);
	n = 0;
	while (is_in_set(*s1, set))
	{
		n++;
		s1++;
	}
	while (is_in_set(s1[l - 1 - n], set))
		l--;
	if (l < n)
		return (ft_strdup(""));
	str = (char *)malloc((l - n + 1) * sizeof(char));
	if (!str)
		return (str);
	ft_strlcpy(str, s1, l - n + 1);
	return (str);
}
