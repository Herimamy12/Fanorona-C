#include "structure.h"

void	fill_last_window(t_data *data)
{
	int color = 255;

	if (data->victory.win1)
		mlx_put_image_to_window (data->win->mlx_ptr,
			data->win->win_ptr, data->img->win1, 0, 0);
	else
		mlx_put_image_to_window (data->win->mlx_ptr,
			data->win->win_ptr, data->img->win2, 0, 0);
	mlx_string_put (data->win->mlx_ptr, data->win->win_ptr,
		204, 245, color, "GAME FINISHED");
	mlx_string_put (data->win->mlx_ptr, data->win->win_ptr,
		184, 264, color, "PRESS SPACE TO REPLAY");
	mlx_string_put (data->win->mlx_ptr, data->win->win_ptr,
		186, 280, color, "PRESS ESCAPE TO QUIT");
	mlx_string_put (data->win->mlx_ptr, data->win->win_ptr,
		288, 494, color, "nherimam-arafaram-nirirako-hrahajan");
}