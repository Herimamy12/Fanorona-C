#ifndef IA_STRUCT
# define IA_STRUCT
# include <stdio.h>
# include <stdlib.h>
# include "structure.h"

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

typedef struct s_coups
{
	int coup[4];
	int x;
	int y;
}	t_coups;

void	init_coup(t_map *map, t_coups *coup);
void	set_coup(t_map *map, t_coups *coup, int x, int y);
void	think(t_map *map);
#endif