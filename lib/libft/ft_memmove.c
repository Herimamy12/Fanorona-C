/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:39:23 by nirirako@         #+#    #+#             */
/*   Updated: 2024/02/20 10:39:24 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (dest == NULL || src == NULL)
		return (NULL);
	d = (char *) dest;
	s = (char *) src;
	if (d < s)
	{
		while (n-- > 0)
			*(d++) = *(s++);
		return (dest);
	}
	else
	{
		d += (n - 1);
		s += (n - 1);
		while (n-- > 0)
		{
			*(d--) = *(s--);
		}
		return (dest);
	}
}
