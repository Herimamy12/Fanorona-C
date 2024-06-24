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

int main()
{
	t_data	*data;

	data = new_data (600, 600, "fanorona");
	mlx_put_image_to_window (data->win->mlx_ptr, data->win->win_ptr, data->img->red, 10, 10);
	mlx_loop (data->win->mlx_ptr);
	return (0);
}
