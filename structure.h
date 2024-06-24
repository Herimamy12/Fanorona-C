/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:05:29 by nirirako@         #+#    #+#             */
/*   Updated: 2024/06/24 09:05:31 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef	STRUCTURE_H
# define STRUCTURE_H
# include "mlx.h"
# include <stdlib.h>
# include "get_next_line.h"
# include <stdio.h>
# define BLOC_WIDTH_3 100
# define BLOC_HEIGHT_3 100
# define ROUGE '1'
# define NOIR '2'
# define VIDE '0'

typedef struct s_map
{
	char	**map;
	int		w;
	int		h;
}	t_map;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		w;
	int		h;
}	t_window;

typedef struct s_image
{
	void	*red;
	void	*black;
	void	*vide;
}	t_image;

typedef struct s_data
{
	t_window	*win;
	t_map		*map;
	t_image		*img;
}	t_data;

t_map	*new_map(int w, int h);
t_window	*new_window(int w, int h, char *title);
t_image	*new_image(t_window *win);
t_data	*new_data(int w, int h, char *title);
void	destroy_map(t_map *map);
void	destroy_window(t_window *win);
void	destroy_image(t_image *img);
void	destroy_data(t_data *data);
#endif


/*######################################*/
/*######################################*/
/*######################################*/
/*######################################*/
/*######################################*/
/*######################################*/

/*
typedef struct s_case
{
	int x;
	int y;
	int num;
	int item;
}	t_case;

typedef struct s_map
{
	t_case	*m;
	int		w;
	int		h;
	char	**map;
}*/