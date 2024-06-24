/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:12:39 by nirirako@         #+#    #+#             */
/*   Updated: 2024/02/22 12:36:07 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count(long int num)
{
	int	n;

	n = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		n++;
	}
	return (n);
}

static char	*iter_itoa(long int nb, int b, int s, char *str)
{
	int	end;

	end = 0;
	if (s)
		end = 1;
	b = b + s;
	while (b > end)
	{
		*(str + b - 1) = nb % 10 + '0';
		nb = nb / 10;
		b--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			b;
	int			s;
	long int	nb;

	s = 0;
	nb = n;
	if (nb < 0)
	{
		s = 1;
		nb = -nb;
	}
	b = count(nb);
	str = (char *)malloc((b + s + 1) * sizeof(char));
	if (str == NULL)
		return (str);
	str[b] = '\0';
	if (s)
		str[0] = '-';
	return (iter_itoa(nb, b, s, str));
}
