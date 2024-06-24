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

int	quit(t_data *data)
{
	destroy_data(data);
	exit(EXIT_SUCCESS);
}

int	handle_key(int keysym, t_data *data)
{
	if (keysym == XK_Escape || keysym == XK_q)
		quit(data);
	return (1);
}

int main()
{
	t_data	*data;

	data = new_data (500, 500, "fanorona");
	fill_window (data);
	mlx_key_hook(data->win->win_ptr, &handle_key, data);
	mlx_mouse_hook(data->win->win_ptr, &handle_mouse, data);
	mlx_hook(data->win->win_ptr, 17, 1L << 2, &quit, data);
	mlx_loop (data->win->mlx_ptr);
	return (0);
}
