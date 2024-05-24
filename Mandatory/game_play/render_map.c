
#include "../cub3d.h"

void render_map(t_game *game)
{
    game->mlx = mlx_init(game->win_width, game->win_height, "GOOD PRACTICE", true);
    if (!game->mlx)
        error_exit("Error\nFailed to initialize mlx");
    init_map(game);
    mlx_loop_hook(game->mlx, &my_loop_hook, game);
    mlx_loop(game->mlx);
    mlx_terminate(game->mlx);
}