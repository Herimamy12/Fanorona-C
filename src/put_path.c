
#include "structure.h"

int	check_path_valide(int xx, int yy, t_data *data);

void	ft_put_path_valide (int xx, int yy, t_data *data)
{
	if (xx > 0)
	{
		if (data->map->map[data->mouse.y][data->mouse.x - 1] == VIDE)
			mlx_put_image_to_window (data->win->mlx_ptr,
				data->win->win_ptr, data->img->vide,
				((xx - 1) * 250) - ((xx - 1) * 25), (yy * 250) - (yy * 25));
	}
	if (xx < 2)
	{
		if (data->map->map[data->mouse.y][data->mouse.x + 1] == VIDE)
			mlx_put_image_to_window (data->win->mlx_ptr,
				data->win->win_ptr, data->img->vide,
				((xx + 1) * 250) - ((xx + 1) * 25), (yy * 250) - (yy * 25));
	}
	if (yy > 0)
	{
		if (data->map->map[data->mouse.y - 1][data->mouse.x] == VIDE)
			mlx_put_image_to_window (data->win->mlx_ptr,
				data->win->win_ptr, data->img->vide,
				(xx * 250) - (xx * 25), ((yy - 1) * 250) - ((yy - 1) * 25));
	}
	if (yy < 2)
	{
		if (data->map->map[data->mouse.y + 1][data->mouse.x] == VIDE)
			mlx_put_image_to_window (data->win->mlx_ptr,
				data->win->win_ptr, data->img->vide,
				(xx * 250) - (xx * 25), ((yy + 1) * 250) - ((yy + 1) * 25));
	}
	if (xx > 0 && yy > 0)
	{
		if (check_path_valide (xx - 1, yy - 1, data))
		{
			if (data->map->map[data->mouse.y - 1][data->mouse.x - 1] == VIDE)
				mlx_put_image_to_window (data->win->mlx_ptr,
					data->win->win_ptr, data->img->vide,
					((xx - 1) * 250) - ((xx - 1) * 25), ((yy - 1) * 250) - ((yy - 1) * 25));
		}
	}
	else if (xx < 3 && yy < 3)
	{
		if (check_path_valide (xx + 1, yy + 1, data))
		{
			if (data->map->map[data->mouse.y + 1][data->mouse.x + 1] == VIDE)
				mlx_put_image_to_window (data->win->mlx_ptr,
					data->win->win_ptr, data->img->vide,
					((xx + 1) * 250) - ((xx + 1) * 25), ((yy + 1) * 250) - ((yy + 1) * 25));
		}
	}
}