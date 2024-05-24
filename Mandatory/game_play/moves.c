
#include "../cub3d.h"

static void listen_keys(t_game *game)
{
    if (mlx_is_key_down(game->mlx, MLX_KEY_W))
        game->map.player.walk_dir = 1;
    else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
        game->map.player.walk_dir = -1;
    else
        game->map.player.walk_dir = 0;
    if (mlx_is_key_down(game->mlx, MLX_KEY_D))
        game->map.player.walk_sid = 1;
    else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
        game->map.player.walk_sid = -1;
    else
        game->map.player.walk_sid = 0;
    if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
        game->map.player.turn_dir = 1;
    else if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
        game->map.player.turn_dir = -1;
    else
        game->map.player.turn_dir = 0;
}

void my_loop_hook(void *param)
{
    t_game *game = (t_game *)param;

    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
        return (mlx_close_window(game->mlx));
    listen_keys(game);
    update_pos_dir(game);
    display_all(game);
}
