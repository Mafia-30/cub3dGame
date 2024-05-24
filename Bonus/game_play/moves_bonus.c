
#include "../cub3d_bonus.h"

static void	listen_keys(t_game *game)
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
	if (mlx_is_mouse_down(game->mlx, MLX_MOUSE_BUTTON_LEFT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SUPER))
		game->map.player.shooting = 1;
}

static void	mouse_rotation(t_game *game)
{
	int32_t	x;
	int32_t	y;

	mlx_get_mouse_pos(game->mlx, &x, &y);
	if ((double)x > (double)(game->win_width / 2) + 150)
		game->map.player.turn_dir = 1;
	else if ((double)x < (double)(game->win_width / 2) - 150)
		game->map.player.turn_dir = -1;
	else if (!mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		&& !mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->map.player.turn_dir = 0;
}

static void	shoot(t_game *game)
{
	static int	delay;

	if (delay == 2)
	{
		if (game->map.player.gun_image_id == 4)
		{
			game->map.player.gun_image_id = 0;
			game->map.player.shooting = 0;
		}
		else
			game->map.player.gun_image_id++;
		delay = 0;
	}
	delay++;
}

void	my_loop_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		return (mlx_close_window(game->mlx));
	if (game->map.mini_map_size != game->win_height)
	{
		listen_keys(game);
		mouse_rotation(game);
		update_pos_dir(game);
		if (game->map.player.shooting)
			shoot(game);
		display_all(game);
	}
	draw_mini_map(game);
}
