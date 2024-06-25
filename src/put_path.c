
#include "structure.h"

int	check_action_valide(int xx, int yy, t_data *data)
{
	int r;

	r = 0;
	if (data->map->map[yy][xx] == VIDE)
	{
		if (data->mouse.x == 1 && data->mouse.y == 1)
		{
			if (abs (xx - data->mouse.x) <= 1 &&
				abs (yy - data->mouse.y) <= 1)
				r = 1;
		}
		else if (data->mouse.x == 0 && (data->mouse.y == 0 || data->mouse.y == 2))
		{
			if (abs (xx - data->mouse.x) <= 1 &&
				abs (yy - data->mouse.y) <= 1)
				r = 1;
		}
		else if (data->mouse.y == 0 && (data->mouse.x == 0 || data->mouse.x == 2))
		{
			if (abs (xx - data->mouse.x) <= 1 &&
				abs (yy - data->mouse.y) <= 1)
				r = 1;
		}
	}
	return (r);
}
