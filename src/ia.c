#include "ia_struct.h"

void	set_coup_diagonal(t_map *map, t_coups *coup, int x, int y)
{
	int	w;
	int	h;

	w = map->w;
	h = map->h;
	if ((x == 1 && (y == 0 || y == 2)) || (y == 1 && (x == 0 || x == 2)))
	{
		coup->coup_d[D_1] = 0;
		coup->coup_d[D_2] = 0;
		coup->coup_d[D_3] = 0;
		coup->coup_d[D_4] = 0;
		return ;
	}
	if ((x - 1 >= 0 && y - 1 >= 0) && (map->map[y - 1][x - 1] == VIDE))
		coup->coup_d[D_1] = 1;
	else
		coup->coup_d[D_1] = 0;
	if ((x + 1 < w && y - 1 >= 0) && (map->map[y - 1][x + 1] == VIDE))
		coup->coup_d[D_2] = 1;
	else
		coup->coup_d[D_2] = 0;
	if ((x - 1 >= 0 && y + 1 < h) && (map->map[y + 1][x - 1] == VIDE))
		coup->coup_d[D_3] = 1;
	else
		coup->coup_d[D_3] = 0;
	if ((x + 1 < w && y + 1 < h) && (map->map[y + 1][x + 1] == VIDE))
		coup->coup_d[D_4] = 1;
	else
		coup->coup_d[D_4] = 0;
}

void	set_coup(t_map *map, t_coups *coup, int x, int y)
{
	if (x + 1 < map->w && map->map[y][x + 1] == VIDE)
		coup->coup[RIGHT] = 1;
	else
		coup->coup[RIGHT] = 0;
	if (x - 1 >= 0 && map->map[y][x - 1] == VIDE)
		coup->coup[LEFT] = 1;
	else
		coup->coup[LEFT] = 0;
	if (y - 1 >= 0 && map->map[y - 1][x] == VIDE)
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
	int	i;

	i = 0;
	for (int j = 0; j < map->h; j++)
	{
		for (int k = 0; k < map->w; k++)
		{
			if (map->map[j][k] == NOIR)
			{
				set_coup(map, coup + i, k, j);
				set_coup_diagonal(map, coup + i, k, j);
				i++;
			}
		}
	}
}

int	coup_valide(t_coups *coup, int *a)
{
	int	n;

	n = rand() % 3;
	for (int j = 0; j < 4; j++)
	{
		if (coup[n].coup_d[j])
		{	
			*a = 0;
			return (n);
		}
		if (coup[n].coup[j])
		{
			*a = 1;
			return (n); 
		}
	}
	return (-1);
}

void	move_d(int *xx, int *yy, t_coups coup)
{
	int x;
	int y;
	int i;

	x = coup.x;
	y = coup.y;
	for (i = 0; i < 4; i++)
	{
		if (coup.coup_d[i])
			break;
	}
	switch (i)
	{
		case D_1:
		{	
			y = y - 1;
			x = x - 1;
		}
		break;
		case D_2:
		{	
			y = y - 1;
			x = x + 1;
		}
		break;
		case D_3:
		{	
			y = y + 1;
			x = x - 1;
		}
		break;
		case D_4:
		{	
			y = y + 1;
			x = x + 1;
		}
		break;
	}
	*xx = x;
	*yy = y;
}

void	move(int *xx, int *yy, t_coups coup)
{
	int x;
	int y;
	int i;

	x = coup.x;
	y = coup.y;
	for (i = 0; i < 4; i++)
	{
		if (coup.coup[i])
			break;
	}
	switch (i)
	{
		case UP:
			y = y - 1;
		break;
		case DOWN:
			y = y + 1;
		break;
		case LEFT:
			x = x - 1;
		break;
		case RIGHT:
			x = x + 1;
		break;
	}
	*xx = x;
	*yy = y;
}

void	think(t_map *map, t_data *data)
{
	t_coups coup[3];
	int c;
	int	x;
	int	y;
	int	i;
	int	j;
	int	z;
	int	a;
	
	print_map(map->map);
	printf("\n");
	init_coup(map, coup);
	c = -1;
	z = 0;
	for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
				printf("%d ", coup[i].coup_d[j]);
			printf("\n");
		}
	while (z < 100 && c == -1)
	{	
		c = coup_valide(coup, &a);
		z++;
		if (c == -1)
			continue ;
	}
	if (c == -1)
	{
		handle_key(114, data);
		return ;
	}
	i = coup[c].x;
	j = coup[c].y;
	if (a == 0)
		move_d(&x, &y, coup[c]);
	else if (a == 1)
		move(&x, &y, coup[c]);
	map->map[y][x] = NOIR;
	map->map[j][i] = VIDE;
}