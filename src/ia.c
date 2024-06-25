#include "ia_struct.h"

void	set_coup(t_map *map, t_coups *coup, int x, int y)
{
	// horizontal 
	if (x + 1 < map->w && map->map[y][x + 1] == VIDE)
		coup->coup[RIGHT]= 1;
	else
		coup->coup[RIGHT] = 0;
	if (x - 1 > 0 && map->map[y][x - 1] == VIDE)
		coup->coup[LEFT] = 1;
	else
		coup->coup[LEFT] = 0;
	if (y - 1 > 0 && map->map[y - 1][x] == VIDE)
		coup->coup[UP] = 1;
	else
		coup->coup[UP] = 0;
	if (y + 1 < map->h && map->map[y + 1][x] == VIDE)
		coup->coup[DOWN] = 1;
	else
		coup->coup[DOWN] = 0;
	coup->x = x;
	coup->y = y;
}

void	init_coup(t_map *map, t_coups *coup)
{
	int i;

	i = 0;
	for (int j = 0; j < map->h; j++)
	{
		for (int k = 0; k < map->w; k++)
		{
			if (map->map[j][k] == NOIR)
			{
				set_coup(map, coup + i, k, j);
				i++;
			}
		}
	}
}

int coup_valide(t_coups *coup)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (coup[i].coup[j])
				return (i);
		}
	}
	return (-1);
}

void	think(t_map *map)
{
	t_coups coup[3];
	int c;

	init_coup(map, coup);
	c = coup_valide(coup);
	printf("dir: %d x %d y %d\n", coup[c].coup[0], coup[c].x, coup[c].y);
	printf("\n");
}