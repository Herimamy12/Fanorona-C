/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:43:50 by nirirako@         #+#    #+#             */
/*   Updated: 2024/06/24 09:44:08 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

t_victory	new_victory(void)
{
	t_victory	victory;

	victory.win1 = 0;
	victory.win2 = 0;
	return (victory);
}

t_player	new_player(void)
{
	t_player	player;

	player.state = 0;
	return (player);
}

t_mouse	new_mouse(void)
{
	t_mouse	mouse;

	mouse.state = 0;
	mouse.x = 0;
	mouse.y = 0;
	return (mouse);
}

t_window	*new_window(int w, int h, char *title)
{
	t_window	*win;

	win = (t_window *)malloc(sizeof(t_window));
	if (!win)
		return (NULL);
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, w, h, title);
	win->w = w;
	win->h = h;
	return (win);
}

void	destroy_window(t_window *win)
{
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_display(win->mlx_ptr);
	free(win->mlx_ptr);
	free(win);
}

t_data	*new_data(int w, int h, char *title)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->win = new_window(w, h, title);
	data->map = new_map(3, 3);
	data->img = new_image(data->win);
	data->mouse = new_mouse();
	data->player = new_player();
	data->victory = new_victory();
	data->state = init_state(data);
	return (data);
}

void	destroy_data(t_data *data)
{
	for (int i = 0; i < data->map->h; i++)
		free(data->state[i]);
	free(data->state);
	destroy_map(data->map);
	destroy_image(data->img);
	destroy_window(data->win);
	free(data);
}