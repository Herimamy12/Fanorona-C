/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:08:05 by nirirako@         #+#    #+#             */
/*   Updated: 2024/02/20 15:08:06 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	cast(char nbre)
{
	return (nbre - '0');
}

static int	is_white_space(char car)
{
	if ((car >= 8 && car <= 13) || car == 32)
		return (1);
	return (0);
}

static int	iter_atoi(char *str, int sign)
{
	int		nbre;
	int		index;

	nbre = 0;
	index = 0;
	while (*(str + index) >= '0' && *(str + index) <= '9')
	{
		nbre = nbre * 10 + cast(str[index]);
		index++;
	}
	return (nbre * sign);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	char	*str;

	str = (char *)nptr;
	sign = 1;
	if (str == NULL)
		return (0);
	while (is_white_space(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	return (iter_atoi(str, sign));
}
