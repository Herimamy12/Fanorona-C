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

t_window	*destroy_window(t_window *win)
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
	return (data);
}

void	destroy_data(t_data *data)
{
	destroy_map(data->map);
	destroy_image(data->img);
	destroy_window(data->win);
	free(data);
}