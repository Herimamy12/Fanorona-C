/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:30:30 by nirirako@         #+#    #+#             */
/*   Updated: 2024/06/24 15:30:42 by nirirako@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"


char	**init_state(t_data *data)
{
	char	**s;

	s = (char **)malloc(data->map->h * sizeof(char *));
	if (!s)
		return NULL;
	for (int i = 0; i < data->map->h; i++)
	{
		s[i] = (char *)malloc(data->map->w * sizeof(char));
		for (int j = 0; j < data->map->w; j++)
			s[i][j] = 0;
	}
	return (s);
}

int check_state(char **s)
{
	int c1;
	int c2;

	c1 = s[0][0] && s[0][1] && s[0][2];
	c2 = s[2][0] && s[2][1] && s[2][2];
	return (c1 || c2);
}