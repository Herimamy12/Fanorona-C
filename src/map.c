/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherimam <nherimam@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:34:35 by nherimam          #+#    #+#             */
/*   Updated: 2024/06/24 10:50:33 by nherimam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

char	**get_char_map(int fd);

t_map	*new_map(int w, int h)
{
	int 	fd;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	fd = open ("map3", O_RDONLY);
	if (fd < 0)
		return (NULL);
	map->map = NULL;
	map->map = get_char_map (fd);
	map->w = w;
	map->h = h;
	close (fd);
	return (map);
}

char	**get_char_map(int fd)
{
	int		i;
	char	*tmp;
	char	*line;
	char	**charmap;

	tmp = NULL;
	line = get_next_line (fd);
	i = 0;
	while (line)
	{
		tmp = ft_strjoin (tmp, line);
		free (line);
		line = get_next_line (fd);
		i++;
	}
	charmap = ft_split (tmp, '\n');
	if (!charmap)
		return (NULL);
	free (tmp);
	free (line);
	return (charmap);
}

void	destroy_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->h)
		free (map->map[i++]);
	free (map->map);
	free (map);
}