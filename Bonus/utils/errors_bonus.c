#include "../cub3d_bonus.h"

void free_game(t_game *game)
{
    int i;

    i = 0;
    while (i < game->map.map_y)
    {
        free(game->map.map[i]);
        i++;
    }
    free(game->no_texture);
    free(game->so_texture);
    free(game->we_texture);
    free(game->ea_texture);
}

void		error_exit(char *message)
{
    printf("%s\n", message);
    exit(1);
}
