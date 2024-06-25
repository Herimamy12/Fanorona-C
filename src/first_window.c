#include "structure.h"

int	quit(t_data *data);
int	handle_key(int keysym, t_data *data);
void	game_restart(t_data *data);

int	handle_key_press(int keysym, t_data *data)
{
	if (keysym == 65433 || keysym == 50)
	{
		destroy_data (data);
		data = new_data (500, 500, "fanorona");
		game_restart (data);
	}
	// else if (keysym == 65436 || keysym == 49)
	// {
	// 	ato le iantso ia
	// }
	if (keysym == XK_Escape || keysym == XK_q)
		quit(data);
	return (1);
}

void	first_window(t_data *data)
{
	mlx_put_image_to_window (data->win->mlx_ptr,
		data->win->win_ptr, data->img->win0, 0, 0);
	mlx_key_hook(data->win->win_ptr, &handle_key_press, data);
	mlx_mouse_hook(data->win->win_ptr, &handle_mouse, data);
	mlx_hook(data->win->win_ptr, 17, 1L << 2, &quit, data);
	mlx_loop (data->win->mlx_ptr);
}