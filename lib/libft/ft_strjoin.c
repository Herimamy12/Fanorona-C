/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:39:51 by nirirako@         #+#    #+#             */
/*   Updated: 2024/02/21 13:39:52 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*ptr_str;
	int		size;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(size * sizeof(char));
	ptr_str = str;
	if (str == NULL)
		return (NULL);
	while (*s1)
	{
		*str++ = *s1++;
	}
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (ptr_str);
}
