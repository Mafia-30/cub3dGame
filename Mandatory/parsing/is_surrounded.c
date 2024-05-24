#include "../cub3d.h"

inline static int	is_open_space(char **map, int x, int y)
{
	if (map[y][x + 1] == '\0' || map[y + 1][x] == '\0' || map[y - 1][x] == '\0'
		|| (map[y][x + 1]) == ' ' || (map[y][x - 1]) == ' ' || (map[y
			+ 1][x]) == ' ' || (map[y - 1][x]) == ' ')
		return (1);
	return (0);
}

static void	set_player_info(t_map *map, char c, int i, int j)
{
	if (map->player.x != -1 || map->player.y != -1)
		error_exit("Error\nDuplicate player position");
	map->player.y = i;
	map->player.x = j;
	if (c == 'N')
		map->player.rotation_angle = 3 * M_PI / 2;
	else if (c == 'S')
		map->player.rotation_angle = M_PI / 2;
	else if (c == 'W')
		map->player.rotation_angle = M_PI;
	else if (c == 'E')
		map->player.rotation_angle = 0;
}

void	is_surrounded(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_y)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] != '1' && !ft_isspace(map->map[i][j]))
			{
				if ((i == 0) || (i == map->map_y - 1) || is_open_space(map->map,
						j, i))
					error_exit("Error\nMap is open");
				if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
					|| map->map[i][j] == 'W' || map->map[i][j] == 'E')
					set_player_info(map, map->map[i][j], i, j);
			}
			j++;
		}
		i++;
	}
	if (map->player.x == -1 || map->player.y == -1)
		error_exit("Error\nPlayer position not found");
}
