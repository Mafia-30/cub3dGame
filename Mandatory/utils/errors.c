#include "../cub3d.h"

void free_game(t_game *game)
{
    int i;

    i = 0;
    while (i < game->map.map_y)
    {
        free(game->map.map[i]);
        i++;
    }
    free(game->map.map);
    free(game->no_pixels);
    free(game->so_pixels);
    free(game->we_pixels);
    free(game->ea_pixels);
    free(game->no_texture);
    free(game->so_texture);
    free(game->we_texture);
    free(game->ea_texture);
}

void error_exit(char *message)
{
    ft_putstr_fd(message, 2);
    write(2, "\n", 1);
    exit(1);
}
