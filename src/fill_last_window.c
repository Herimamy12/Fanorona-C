#include "structure.h"

void	fill_last_window(t_data *data)
{
	int color = 255;
	// fill_window (data);
	// usleep (1000000);
	// for (int i = 0; i < (250 * (data->map->w - 1)); i++)
	// {
	// 	for (int j = 0; j < (250 * (data->map->w - 1)); j++)
	// 		mlx_pixel_put (data->win->mlx_ptr, data->win->win_ptr,
	// 			i, j, 000000);
	// }
	mlx_string_put (data->win->mlx_ptr, data->win->win_ptr,
		200, 250, color, "Game Finished");
}