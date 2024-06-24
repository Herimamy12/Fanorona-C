/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:48:20 by nirirako@         #+#    #+#             */
/*   Updated: 2024/02/29 10:48:21 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		n;

	n = 0;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		n++;
		lst = lst->next;
	}
	n++;
	return (n);
}
