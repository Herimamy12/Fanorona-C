/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:48:17 by nirirako@         #+#    #+#             */
/*   Updated: 2024/02/20 09:48:22 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	index;

	index = 0;
	if (s == NULL)
		return ;
	while (index < n)
	{
		*((char *) s + index) = 0;
		index++;
	}
}
