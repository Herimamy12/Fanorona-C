/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:50:57 by nirirako@         #+#    #+#             */
/*   Updated: 2024/06/25 14:50:59 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

void	start_pvp(t_data *data)
{
	destroy_data (data);
	data = new_data (500, 500, "fanorona");
	game_restart (data, &handle_mouse);
}

void	start_pvc(t_data *data)
{
	destroy_data (data);
	data = new_data (500, 500, "fanorona");
	game_restart (data, &handle_mouse_computer);
}

int handle_mouse_fst(int button, int x, int y, t_data *data)
{
	if (button != 1)
		return 0;
	if (x > 150 && x < 380)
	{
		if (y > 200 && y < 280)
			start_pvc(data);
		else if (y > 330 && y < 402)
			start_pvp(data);
	}
	return 1;
}

int	handle_key_press(int keysym, t_data *data)
{
	if (keysym == 65433 || keysym == 50)
		start_pvp(data);
	else if (keysym == 65436 || keysym == 49)
		start_pvc(data);
	if (keysym == XK_Escape || keysym == XK_q)
		quit(data);
	return (1);
}

void	first_window(t_data *data)
{
	mlx_put_image_to_window (data->win->mlx_ptr,
		data->win->win_ptr, data->img->win0, 0, 0);
	mlx_key_hook(data->win->win_ptr, &handle_key_press, data);
	mlx_mouse_hook(data->win->win_ptr, &handle_mouse_fst, data);
	mlx_hook(data->win->win_ptr, 17, 1L << 2, &quit, data);
	mlx_loop (data->win->mlx_ptr);
}
