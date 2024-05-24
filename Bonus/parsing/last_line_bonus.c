#include "../cub3d_bonus.h"

char	*last_line(char **map)
{
	int i;

	i = 0;
	while (map && map[i])
		i++;
	return (map[i - 1]);
}