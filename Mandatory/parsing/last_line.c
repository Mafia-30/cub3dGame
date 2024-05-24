#include "../cub3d.h"

char	*last_line(char **map)
{
	int i;

	i = 0;
	while (map && map[i])
		i++;
	return (map[i - 1]);
}