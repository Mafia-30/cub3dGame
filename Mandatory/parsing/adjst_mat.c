/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjst_mat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:35:53 by ymahni            #+#    #+#             */
/*   Updated: 2024/05/24 18:04:10 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	adjust_matrix(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_y)
	{
		j = ft_strlen(map->map[i]);
		if (j < map->map_x)
		{
			map->map[i] = ft_realloc(map->map[i], map->map_x + 1);
			while (j < map->map_x)
			{
				map->map[i][j] = ' ';
				j++;
			}
			map->map[i][j] = '\0';
		}
		i++;
	}
}
