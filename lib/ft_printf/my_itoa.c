/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:12:53 by nirirako@         #+#    #+#             */
/*   Updated: 2024/03/08 13:12:54 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(unsigned int n, int lb)
{
	static int	count = 0;
	int			tmp;

	count++;
	if (n / lb > 0)
		return (count_digits(n / lb, lb));
	tmp = count;
	count = 0;
	return (tmp);
}

static void	recu_itoa(unsigned int n, char *str, char *b, int lb)
{
	static int	c = 0;

	if (!c)
	{
		c = 1;
		*str = '\0';
		str = str - 1;
	}
	if (n / lb > 0)
		recu_itoa(n / lb, str - 1, b, lb);
	c = 0;
	*str = b[n % lb];
}

char	*my_itoa(int n, char *b)
{
	int				digits;
	char			*num_str;
	int				lb;
	unsigned int	num;

	num = n;
	digits = 0;
	if (n < 0)
	{
		num = (unsigned int)(-1 * n);
		digits++;
	}
	lb = ft_strlen(b);
	digits += count_digits(num, lb);
	num_str = (char *)malloc((digits + 1) * sizeof(char));
	if (!num_str)
		return (NULL);
	recu_itoa(num, num_str + digits, b, lb);
	if (n < 0)
		*num_str = '-';
	return (num_str);
}
