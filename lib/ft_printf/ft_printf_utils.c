/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:12:10 by nirirako@         #+#    #+#             */
/*   Updated: 2024/03/08 13:12:11 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(unsigned char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *s)
{
	int		w;

	w = 0;
	if (!s)
		return (print_str("(null)"));
	while (*s)
	{
		w += print_char(*s);
		s++;
	}
	return (w);
}

int	print_int(int n, char *b)
{
	char	*num_str;
	int		digit;

	num_str = my_itoa(n, b);
	if (!num_str)
		return (0);
	digit = print_str(num_str);
	free(num_str);
	return (digit);
}

int	print_u_int(unsigned int n, char *b)
{
	unsigned int	max;
	int				lb;
	int				c;

	lb = ft_strlen(b);
	max = 0;
	c = 0;
	if (lb == 10)
		max = _INT_MAX_10;
	else if (lb == 16)
		max = INT_MAX_16;
	if (n > max)
	{
		c += print_int(n / lb, b);
		n = n % lb;
	}
	c += print_int(n, b);
	return (c);
}

int	print_u_long(unsigned long n, char *b, int lb)
{
	static int	c = 0;
	int			tmp;

	if (n / lb > 0)
		c += print_u_long(n / lb, b, lb);
	c += print_u_int(n % lb, b);
	tmp = c;
	c = 0;
	return (tmp);
}
