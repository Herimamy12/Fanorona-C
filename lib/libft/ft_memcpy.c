/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:09:30 by nirirako@         #+#    #+#             */
/*   Updated: 2024/02/20 10:09:31 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		index;
	char		*ptr;

	ptr = (char *)src;
	index = 0;
	if (n == 0 || src == NULL)
		return (dest);
	if (dest == NULL)
		return (NULL);
	while (index < n)
	{
		*((char *)dest + index) = *(ptr + index);
		index++;
	}
	return ((void *)dest);
}
