 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:42:12 by nirirako@         #+#    #+#             */
/*   Updated: 2024/06/24 10:42:12 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "ia_struct.h"

int	handle_key(int keysym, t_data *data);

int	quit(t_data *data)
{
	destroy_data(data);
	exit(EXIT_SUCCESS);
}

void	game_restart(t_data *data, int (*fun)(int, int, int, t_data *))
{
	fill_window (data);
	mlx_key_hook(data->win->win_ptr, &handle_key, data);
	mlx_mouse_hook(data->win->win_ptr, fun, data);
	mlx_hook(data->win->win_ptr, 17, 1L << 2, &quit, data);
	mlx_loop (data->win->mlx_ptr);
}

int	handle_key(int keysym, t_data *data)
{
	if (keysym == 114)
	{
		destroy_data (data);
		data = new_data (500, 500, "fanorona");
		game_restart (data, &handle_mouse);	
	}
	if (keysym == 32)
	{
		destroy_data (data);
		data = new_data (500, 500, "fanorona");
		first_window (data);
	}
	if (keysym == XK_Escape || keysym == XK_q)
		quit(data);
	return (1);
}

int main()
{
	t_data	*data;

	data = new_data (500, 500, "fanorona");
	first_window(data);
	return (0);
}
