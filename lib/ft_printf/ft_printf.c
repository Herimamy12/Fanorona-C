/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:11:49 by nirirako@         #+#    #+#             */
/*   Updated: 2024/03/08 13:11:51 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_adress(void *p)
{
	int	count;

	count = 0;
	if (!p)
		return (print_str("(nil)"));
	count = print_str("0x");
	return (count + print_u_long((unsigned long) p, BASE_16_LOWER, 16));
}

static int	show_print(char c, va_list args)
{
	if (c == 'c')
		return (print_char(va_arg(args, int)));
	if (c == 's')
		return (print_str(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (print_int(va_arg(args, int), BASE_10));
	if (c == 'u')
		return (print_u_int(va_arg(args, unsigned int), BASE_10));
	if (c == 'x')
		return (print_u_int(va_arg(args, unsigned int), BASE_16_LOWER));
	if (c == 'X')
		return (print_u_int(va_arg(args, unsigned int), BASE_16_UPPER));
	if (c == 'p')
		return (print_adress(va_arg(args, void *)));
	if (c == '%')
		return (print_char('%'));
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			k;
	int			count;
	int			c;

	va_start(args, s);
	k = 0;
	count = 0;
	while (s[k])
	{
		if (s[k] == '%')
		{
			k++;
			c = show_print(s[k], args);
			count += c;
			if (c < 0)
				break ;
		}
		else
			count += print_char(s[k]);
		k++;
	}
	va_end(args);
	return (count);
}
