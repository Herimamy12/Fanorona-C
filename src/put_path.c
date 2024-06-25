
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

// void	ft_put_path_valide (int xx, int yy, t_data *data)
// {
// 	if (xx >= 0)
// 	{
// 		if (check_action_valide (xx, yy, data))
// 			mlx_put_image_to_window (data->win->mlx_ptr,data->win->win_ptr,
// 				data->img->vide, (xx * 250) - (xx * 25), (yy * 250) - (yy * 25));
// 		else if (check_action_valide (xx + 1, yy, data))
// 			mlx_put_image_to_window (data->win->mlx_ptr,data->win->win_ptr,
// 				data->img->vide, ((xx + 1) * 250) - ((xx + 1) * 25), (yy * 250) - (yy * 25));
// 	}
// 	if (yy >= 0)
// 	{
// 		if (check_action_valide (xx, yy, data))
// 			mlx_put_image_to_window (data->win->mlx_ptr,data->win->win_ptr,
// 				data->img->vide, (xx * 250) - (xx * 25), (yy * 250) - (yy * 25));
// 		else if (check_action_valide (xx, yy + 1, data))
// 			mlx_put_image_to_window (data->win->mlx_ptr,data->win->win_ptr,
// 				data->img->vide, (xx * 250) - (xx * 25), ((yy + 1) * 250) - ((yy + 1) * 25));
// 	}
// }
