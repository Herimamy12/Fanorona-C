/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:27:55 by nirirako@         #+#    #+#             */
/*   Updated: 2024/02/20 14:27:57 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				index;
	unsigned char		*ptr1;
	unsigned char		*ptr2;

	index = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (index < n)
	{
		if (*(ptr1 + index) != *(ptr2 + index))
			return (*(ptr1 + index) - *(ptr2 + index));
		index++;
	}
	return (0);
}
