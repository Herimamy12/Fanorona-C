/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:55:02 by nirirako@         #+#    #+#             */
/*   Updated: 2024/02/21 12:55:04 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	l;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	l = ft_strlen(s + start);
	if (l > len)
		l = len;
	str = (char *)malloc((l + 1) * sizeof(char));
	if (!str)
		return (str);
	ft_strlcpy(str, s + start, l + 1);
	return (str);
}
