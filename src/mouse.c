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

int	check_path_valide(int xx, int yy, t_data *data)
{
	if (data->map->map[yy][xx] == VIDE)
	{
		if (abs (xx - data->mouse.x) <= 1 &&
			abs (yy - data->mouse.y) <= 1)
			return (1);
	}
	return (0);
}

void	r_move(int xx, int yy, t_data *data)
{
	data->map->map[yy][xx] = ROUGE;
	data->map->map[data->mouse.y][data->mouse.x] = VIDE;
}

void	ft_manage_movement(int xx, int yy, t_data *data)
{
	if (check_path_valide(xx, yy, data))
	{
		r_move (xx, yy, data);
		fill_window (data);
	}
	data->mouse.state = 0;
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
		if (data->mouse.state == 0)
		{
			data->mouse.state = 1;
			data->mouse.x = xx;
			data->mouse.y = yy;
		}
		else
			ft_manage_movement (xx, yy, data);
		ft_printf("x: %d\n y: %d\n", xx, yy);
	}
	(void)data;
	return (1);
}