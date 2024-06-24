/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:56:29 by nirirako@         #+#    #+#             */
/*   Updated: 2024/02/29 12:56:30 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next;

	temp = *lst;
	next = temp -> next;
	while (next != NULL)
	{
		ft_lstdelone(temp, del);
		temp = next;
		next = temp -> next;
	}
	ft_lstdelone(temp, del);
	*lst = NULL;
}
