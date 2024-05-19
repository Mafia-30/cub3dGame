
#include "../cub3d_bonus.h"

static int calc_doors(char **map, int map_x, int map_y)
{
    int i, j;
    int counter = 0;

    i = 0;
    j = 0;
    while (i < map_y)
    {
        j = 0;
        while (j < map_x)
        {
            if (map[i][j] == 'D')
            {
                counter++;
            }
            j++;
        }
        i++;
    }
    return (counter);
}

void    store_doors_info(t_game *game)
{
    int i;
	int	j;
    int counter;

	game->map.doors_num = calc_doors(game->map.map, game->map.map_x, game->map.map_y);
    game->map.doors = (t_door *) malloc(game->map.doors_num * sizeof(t_door));
	if (!game->map.doors)
		error_exit ("Error\nAllocation failed!");
    i = -1;
	counter = 0;
    while (++i < game->map.map_y)
    {
        j = 0;
        while (j < game->map.map_x)
        {
            if (game->map.map[i][j] == 'D')
            {
                game->map.doors[counter].pos.x = j;
                game->map.doors[counter].pos.y = i;
                game->map.doors[counter++].first_pixel_x = 0;
            }
            j++;
        }
    }
}
