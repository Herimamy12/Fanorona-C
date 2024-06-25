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

typedef struct s_victory
{
	int win1;
	int win2;
}	t_victory;

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
	void	*red01;
	void	*black;
	void	*black01;
	void	*vide;
	void	*fond;
	void	*win0;
	void	*win1;
	void	*win2;
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
}	t_player;

typedef struct s_data
{
	t_window	*win;
	t_map		*map;
	t_image		*img;
	t_mouse		mouse;
	t_player	player;
	t_victory	victory;
	char		**state;
}	t_data;

t_map		*new_map(int w, int h);
t_window	*new_window(int w, int h, char *title);
t_image		*new_image(t_window *win);
t_data		*new_data(int w, int h, char *title);
void		destroy_map(t_map *map);
void		destroy_window(t_window *win);
void		destroy_image(t_image *img);
void		destroy_data(t_data *data);
void		fill_window(t_data *data);
int 		handle_mouse(int button, int x, int y, t_data *data);
char		**init_state(t_data *data);
int 		check_state1(char **s);
int 		check_state2(char **s);
int			verif_win1(t_data *data);
int			verif_win2(t_data *data);
void		ft_print_map(char **map);
void		first_window(t_data *data);
void		fill_last_window(t_data *data);
int 		handle_mouse(int button, int x, int y, t_data *data);
int			quit(t_data *data);
int			handle_key(int keysym, t_data *data);
int 		handle_mouse_computer(int button, int x, int y, t_data *data);
void		game_restart(t_data *data, int (*fun)(int, int, int, t_data *));

#endif
