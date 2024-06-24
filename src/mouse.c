/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:13:09 by nirirako@         #+#    #+#             */
/*   Updated: 2024/06/24 13:13:20 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"


void	map_mouse(int *x, int *y)
{
	*x = (int)*x / BLOC_WIDTH_3;
	*y = (int)*y / BLOC_HEIGHT_3;
}

int handle_mouse(int button, int x, int y, t_data *data)
{
	int xx;
	int yy;

	if (button == 1)
	{
		xx = x;
		yy = y;
		map_mouse(&xx, &yy);
		ft_printf("x: %d\n y: %d\n", xx, yy);
	}
	(void)data;
	return (1);
}