/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillwindow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:28:19 by nherimam          #+#    #+#             */
/*   Updated: 2024/06/24 12:28:23 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

void	fill_window(t_data *data)
{
	int	i;
	int	j;
	int color = 255;

	mlx_put_image_to_window (data->win->mlx_ptr,
		data->win->win_ptr, data->img->fond, 0, 0);
	i = 0;
	while (i < data->map->h)
	{
		j = 0;
		while (j < data->map->w)
		{
			if (data->map->map[j][i] == '1')
			{
				mlx_put_image_to_window (data->win->mlx_ptr,
					data->win->win_ptr, data->img->red,
					(i * 250) - ( i * 25), (j * 250) - ( j  * 25));
			}
			else if (data->map->map[j][i] == '2')
			{
				mlx_put_image_to_window (data->win->mlx_ptr,
					data->win->win_ptr, data->img->black,
					(i * 250) - ( i * 25), (j * 250) - (j * 25));
			}
			j++;
		}
		i++;
	}
	mlx_string_put (data->win->mlx_ptr, data->win->win_ptr,
		288, 494, color, "press R to reset the game");
	mlx_string_put (data->win->mlx_ptr, data->win->win_ptr,
		56, 494, color, "press space to go to menu");
}
