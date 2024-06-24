/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:35:07 by nirirako@         #+#    #+#             */
/*   Updated: 2024/02/20 08:35:10 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	index;

	if (s == NULL)
		return (s);
	index = 0;
	while (index < n)
	{
		*((char *) s + index) = (char) c;
		index++;
	}
	return ((void *) s);
}
