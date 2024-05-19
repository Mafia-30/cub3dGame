#include "../cub3d_bonus.h"

void append_line(t_game *game, char *line)
{
    char **new_map;
    int i;

    new_map = malloc(sizeof(char *) * (game->map.map_y + 2));
    if (!new_map)
        error_exit("Error\nMalloc failed");
    i = 0;
    while (i < game->map.map_y)
    {
        new_map[i] = game->map.map[i];
        i++;
    }
    new_map[i] = line;
    new_map[i + 1] = NULL;
    free(game->map.map);
    game->map.map = new_map;
    game->map.map_y++;
}