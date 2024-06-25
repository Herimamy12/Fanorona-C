/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafaram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:27:20 by arafaram          #+#    #+#             */
/*   Updated: 2024/06/24 15:27:21 by arafaram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

int	verif_horizontal(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == c)
				count += 1;
			i++;
		}
		if (count == 3)
			return (1);
		count = 0;
		j++;
	}
	return (0);
}

int	verif_vertical(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[0][i] != '\0')
	{
		j = 0;
		while (map[j] != NULL)
		{
			if (map[j][i] == c)
				count += 1;
			j++;
		}
		if (count == 3)
			return (1);
		count = 0;
		i++;
	}
	return (0);
}

int	verif_diagonal(t_map *map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	if (map->map[0][0] == c && c != '0')
	{
		while (map->map[j] != NULL)
		{
			if (map->map[j][i] == c)
				count += 1;
			j++;
			i++;
		}
	}
	else if (map->map[0][map->w - 1] == c && c != '0')
	{
		i = map->w - 1;
		while (map->map[j] != NULL)
		{
			if (map->map[j][i] == c)
				count += 1;
			i--;
			j++;
		}
	}
	if (count == 3)
		return (1);
	return (0);
}

int	verif_player(t_map *map, char c)
{
	if (verif_horizontal(map->map, c) == 1)
		return (1);
	if (verif_vertical(map->map, c) == 1)
		return (1);
	if (verif_diagonal(map, c) == 1)
		return (1);
	return (0);
}
int	verif_win1(t_data *data)
{
	if (verif_player(data->map, '1') == 1)
		return (1);
	return (0);
}

int	verif_win2(t_data *data)
{
	if (verif_player(data->map, '2') == 1)
		return (1);
	return (0);
}