/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse_computer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafaram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 08:55:02 by arafaram          #+#    #+#             */
/*   Updated: 2024/06/25 08:55:03 by arafaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include "ia_struct.h"

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			printf("%c ", map[j][i++]);
		}
		printf("\n");
		j++;
	}
}

int	ft_manage_movement_2(int xx, int yy, t_data *data)
{
	int	r;

	r = 0;
	if (check_path_valide(xx, yy, data))
	{
		r_move (xx, yy, data);
		fill_window (data);
		r = 1;
	}
	data->mouse.state = 0;
	return (r);
}

int handle_mouse_computer(int button, int x, int y, t_data *data)
{
	int xx;
	int yy;

	if (button == 1)
	{
		xx = x;
		yy = y;
		map_mouse(&xx, &yy);
		if (data->mouse.state == 0)
		{
			data->mouse.x = xx;
			data->mouse.y = yy;
			if (data->player.state == 0 &&
				data->map->map[data->mouse.y][data->mouse.x] == ROUGE)
			{
				data->mouse.state = 1;
			}
		}
		else
		{
			if (data->player.state == 0 &&
				data->map->map[data->mouse.y][data->mouse.x] == ROUGE)
			{	
				if (ft_manage_movement_2 (xx, yy, data) == 1)
				{
					think(data->map, data);
					fill_window(data);
				}
				data->player.state = 0;
			}
			data->mouse.state = 0;
		}
	}
	if (check_state1(data->state) && verif_win1(data))
	{
		data->victory.win1 = 1;
		fill_last_window (data);
	}
	else if (check_state2(data->state) && verif_win2(data))
	{
		data->victory.win2 = 1;
		fill_last_window (data);
	}
	return (1);
}
