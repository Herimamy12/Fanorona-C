/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:15:33 by nirirako@         #+#    #+#             */
/*   Updated: 2024/03/08 13:15:34 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define _INT_MAX_10 2147483647
# define INT_MAX_16 0x7fffffff
# define BASE_10 "0123456789"
# define BASE_16_LOWER "0123456789abcdef"
# define BASE_16_UPPER "0123456789ABCDEF"

int		print_char(unsigned char c);
int		print_str(char *s);
int		print_u_int(unsigned int n, char *b);
int		print_int(int n, char *b);
int		print_u_long(unsigned long n, char *b, int lb);
int		ft_printf(const char *s, ...);
char	*my_itoa(int n, char *b);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
#endif
