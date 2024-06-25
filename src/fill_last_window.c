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
	if (data->victory.win1)
		mlx_put_image_to_window (data->win->mlx_ptr,
			data->win->win_ptr, data->img->win1, 0, 0);
	else
		mlx_put_image_to_window (data->win->mlx_ptr,
			data->win->win_ptr, data->img->win2, 0, 0);
	mlx_string_put (data->win->mlx_ptr, data->win->win_ptr,
		204, 245, color, "GAME FINISHED");
	mlx_string_put (data->win->mlx_ptr, data->win->win_ptr,
		226, 264, color, "REPLAY");
	mlx_string_put (data->win->mlx_ptr, data->win->win_ptr,
		186, 280, color, "PRESS ESCAPE TO QUIT");
}