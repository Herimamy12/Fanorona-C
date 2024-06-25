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

void	ft_put_path_valide (int xx, int yy, t_data *data);

void	map_mouse(int *x, int *y)
{
	*x = (int)*x / BLOC_WIDTH_3;
	*y = (int)*y / BLOC_HEIGHT_3;
}

int	check_path_valide(int xx, int yy, t_data *data)
{
	int r;

	r = 0;
	if (data->map->map[yy][xx] == VIDE)
	{
		if (data->mouse.x == 1 && data->mouse.y == 1)
		{
			if (abs (xx - data->mouse.x) <= 1 &&
				abs (yy - data->mouse.y) <= 1)
			{
				if (data->player.state == 0)
					data->player.state = 1;
				else
					data->player.state = 0;
				r = 1;
			}
		}
		else if (data->mouse.x == 1 || data->mouse.y == 1)
		{
			if (xx == data->mouse.x || yy == data->mouse.y)
			{
				if (abs (xx - data->mouse.x) <= 1 &&
					abs (yy - data->mouse.y) <= 1)
				{
					if (data->player.state == 0)
						data->player.state = 1;
					else
						data->player.state = 0;
					r = 1;
				}
			}
		}
		else if (abs (xx - data->mouse.x) <= 1 &&
			abs (yy - data->mouse.y) <= 1)
		{
			if (data->player.state == 0)
				data->player.state = 1;
			else
				data->player.state = 0;
			r = 1;
		}
	}
	if (r)
		data->state[data->mouse.y][data->mouse.x] = 1;
	return (r);
}

void	r_move(int xx, int yy, t_data *data)
{
	if (data->player.state == 0)
	{
		data->map->map[yy][xx] = NOIR;
		data->map->map[data->mouse.y][data->mouse.x] = VIDE;
	}
	else
	{
		data->map->map[yy][xx] = ROUGE;
		data->map->map[data->mouse.y][data->mouse.x] = VIDE;
	}
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
			data->mouse.x = xx;
			data->mouse.y = yy;
			if ((data->player.state == 0 &&
				data->map->map[data->mouse.y][data->mouse.x] == ROUGE)
				||
				(data->player.state == 1 &&
				data->map->map[data->mouse.y][data->mouse.x] == NOIR))
			{
				fill_window (data);
				if (data->player.state == 1 &&
				data->map->map[data->mouse.y][data->mouse.x] == NOIR)
					mlx_put_image_to_window (data->win->mlx_ptr,
						data->win->win_ptr, data->img->black01,
						(xx * 250) - (xx * 25), (yy * 250) - (yy * 25));
				else
					mlx_put_image_to_window (data->win->mlx_ptr,
						data->win->win_ptr, data->img->red01,
						(xx * 250) - (xx * 25), (yy * 250) - (yy * 25));
//				ft_put_path_valide (xx, yy, data);
				data->mouse.state = 1;
			}
		}
		else
		{
			fill_window (data);
			if (data->player.state == 0 &&
				data->map->map[data->mouse.y][data->mouse.x] == ROUGE)
				ft_manage_movement (xx, yy, data);
			else if (data->player.state == 1 &&
				data->map->map[data->mouse.y][data->mouse.x] == NOIR)
				ft_manage_movement (xx, yy, data);
			else
				data->mouse.state = 0;
		}
	}
	if (check_state1(data->state) && verif_win1(data))
	{
		data->victory.win1 = 1;
		fill_last_window (data);
	}
	else if (check_state2(data->state) && verif_win2(data))
	{
		data->victory.win2 = 1;
		fill_last_window (data);
	}
	return (1);
}