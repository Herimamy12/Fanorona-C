/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:39:00 by nirirako@         #+#    #+#             */
/*   Updated: 2024/02/20 15:39:01 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cp_src;
	int		index;
	int		len_str;

	if (s == NULL)
		return (NULL);
	len_str = ft_strlen((char *)s);
	index = 0;
	cp_src = malloc(len_str + 1);
	if (cp_src == NULL)
		return (NULL);
	while (s[index])
	{
		cp_src[index] = s[index];
		index++;
	}
	cp_src[index] = '\0';
	return (cp_src);
}
