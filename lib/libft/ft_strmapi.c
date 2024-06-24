/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:19:22 by nirirako@         #+#    #+#             */
/*   Updated: 2024/02/22 13:19:23 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		index;

	if (s == NULL)
		return (NULL);
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	index = 0;
	if (str == NULL)
		return (str);
	while (*s)
	{
		str[index] = (*f)(index, *s);
		s++;
		index++;
	}
	str[index] = '\0';
	return (str);
}
