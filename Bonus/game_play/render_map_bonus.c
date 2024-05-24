
#include "../cub3d_bonus.h"

void	render_map(t_game *game)
{
	game->mlx = mlx_init(game->win_width, game->win_height, "GOOD PRACTICE",
			true);
	if (!game->mlx)
		error_exit("Error\nFailed to initialize mlx");
	init_map(game);
	init_player_img(game);
	mlx_key_hook(game->mlx, &actions, game);
	mlx_loop_hook(game->mlx, &my_loop_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}