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
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <X11/keysym.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# define BLOC_WIDTH_3 (500 / 3)
# define BLOC_HEIGHT_3 (500 / 3)
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
	t_window	*win;
	void	*red;
	void	*black;
	void	*vide;
	void	*fond;
}	t_image;

typedef struct s_mouse
{
	int state;
	int x;
	int y;
}	t_mouse;

typedef struct s_player
{
	int state;
	int	x;
	int	y;
}	t_player;

typedef struct s_data
{
	t_window	*win;
	t_map		*map;
	t_image		*img;
	t_mouse		mouse;
	t_player	player;
	char		**state;
}	t_data;

t_map	*new_map(int w, int h);
t_window	*new_window(int w, int h, char *title);
t_image	*new_image(t_window *win);
t_data	*new_data(int w, int h, char *title);
t_player	new_player(void);
void	destroy_map(t_map *map);
void	destroy_window(t_window *win);
void	destroy_image(t_image *img);
void	destroy_data(t_data *data);
void	fill_window(t_data *data);
int 	handle_mouse(int button, int x, int y, t_data *data);
char	**init_state(t_data *data);
int check_state(char **s);
int	verif_win(t_data *data);
void	ft_print_map(char **map);

#endif
