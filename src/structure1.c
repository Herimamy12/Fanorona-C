/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:35:26 by nirirako@         #+#    #+#             */
/*   Updated: 2024/06/24 10:35:27 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

t_image	*new_image(t_window *win)
{
	t_image	*img;
	int		x;
	int		y;

	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
		return (NULL);
	img->win = win;
	img->red = mlx_xpm_file_to_image(win->mlx_ptr, "./img/white.xpm", &x, &y);
	img->black = mlx_xpm_file_to_image(win->mlx_ptr, "./img/black.xpm", &x, &y);
	img->vide = mlx_xpm_file_to_image(win->mlx_ptr, "./img/vide.xpm", &x, &y);
	img->fond = mlx_xpm_file_to_image(win->mlx_ptr, "./img/fond.xpm", &x, &y);
	img->win1 = mlx_xpm_file_to_image(win->mlx_ptr, "./img/win1.xpm", &x, &y);
	img->win2 = mlx_xpm_file_to_image(win->mlx_ptr, "./img/win2.xpm", &x, &y);
	return (img);
}

void	destroy_image(t_image *img)
{
	mlx_destroy_image(img->win->mlx_ptr, img->red);
	mlx_destroy_image(img->win->mlx_ptr, img->black);
	mlx_destroy_image(img->win->mlx_ptr, img->vide);
	mlx_destroy_image(img->win->mlx_ptr, img->fond);
	mlx_destroy_image(img->win->mlx_ptr, img->win1);
	mlx_destroy_image(img->win->mlx_ptr, img->win2);
	free(img);
}

