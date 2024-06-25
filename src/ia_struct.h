#ifndef IA_STRUCT
# define IA_STRUCT
# include "structure.h"
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

typedef enum e_diagonal
{
	D_1 = 0,
	D_2 = 1,
	D_3 = 2,
	D_4 = 3
}		t_diagonal;

typedef struct s_coups
{
	int	coup[4];
	int	coup_d[4];
	int	x;
	int	y;
}		t_coups;

void	init_coup(t_map *map, t_coups *coup);
void	set_coup(t_map *map, t_coups *coup, int x, int y);
void	think(t_map *map, t_data *data);
int		handle_mouse_computer(int button, int x, int y, t_data *data);
void	map_mouse(int *x, int *y);
void	ft_manage_movement(int xx, int yy, t_data *data);
void	r_move(int xx, int yy, t_data *data);
int		check_path_valide(int xx, int yy, t_data *data);
void	print_map(char **map);
int		handle_key(int keysym, t_data *data);
void	move_d(int *xx, int *yy, t_coups coup);
void	move(int *xx, int *yy, t_coups coup);
void	set_coup_diagonal(t_map *map, t_coups *coup, int x, int y);
void	set_coup(t_map *map, t_coups *coup, int x, int y);
void	init_coup(t_map *map, t_coups *coup);

#endif