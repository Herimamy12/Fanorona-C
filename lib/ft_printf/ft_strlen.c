/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 08:37:45 by nirirako@         #+#    #+#             */
/*   Updated: 2024/03/09 08:37:46 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	static size_t	l = 0;
	size_t			tmp;

	if (!*str)
	{
		tmp = l;
		l = 0;
		return (tmp);
	}
	l++;
	return (ft_strlen(str + 1));
}
