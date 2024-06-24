/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:41:18 by nirirako@         #+#    #+#             */
/*   Updated: 2024/02/20 14:41:19 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	comparer(const char *big, const char *little, size_t len)
{
	while (*big && *little && len-- > 0)
	{
		if (*big != *little)
			return (0);
		big++;
		little++;
	}
	if (!*big && *little)
		return (0);
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	ls;

	index = 0;
	ls = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	if (len == 0 || !big || len < ls)
		return (NULL);
	while (index++ <= len - ls && *big)
	{
		if (comparer(big, little, len))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
