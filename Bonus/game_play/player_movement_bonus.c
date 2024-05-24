
#include "../cub3d_bonus.h"

static int	collision(double x, double y, t_map *map)
{
	double	i;
	double	j;

	i = -0.1;
	while (i < 0.2)
	{
		j = -0.1;
		while (j < 0.2)
		{
			if (map->map[(int)(y + i)][(int)(x + j)] == '1' || map->map[(int)(y
					+ i)][(int)(x + j)] == 'D')
				return (1);
			j += 0.1;
		}
		i += 0.1;
	}
	return (0);
}

static void	move_side(t_game *game, double side_step)
{
	double	pseudo_x;
	double	pseudo_y;

	pseudo_x = 0;
	pseudo_y = 0;
	pseudo_x = game->map.player.x + cos(game->map.player.rotation_angle
			+ M_PI_2) * side_step;
	pseudo_y = game->map.player.y + sin(game->map.player.rotation_angle
			+ M_PI_2) * side_step;
	if (!collision(pseudo_x, pseudo_y, &game->map))
	{
		game->map.player.x = pseudo_x;
		game->map.player.y = pseudo_y;
	}
}

static void	move_front_back(t_game *game, double direct_step)
{
	double	pseudo_x;
	double	pseudo_y;

	pseudo_x = 0;
	pseudo_y = 0;
	pseudo_x = game->map.player.x + cos(game->map.player.rotation_angle)
		* direct_step;
	pseudo_y = game->map.player.y + sin(game->map.player.rotation_angle)
		* direct_step;
	if (!collision(pseudo_x, pseudo_y, &game->map))
	{
		game->map.player.x = pseudo_x;
		game->map.player.y = pseudo_y;
	}
}
void	update_pos_dir(t_game *game)
{
	double	direct_step;
	double	side_step;

	direct_step = game->map.player.move_speed * game->map.player.walk_dir;
	side_step = game->map.player.move_speed * game->map.player.walk_sid;
	game->map.player.rotation_angle += game->map.player.rotation_speed
		* game->map.player.turn_dir;
	if (side_step)
		move_side(game, side_step);
	if (direct_step)
		move_front_back(game, direct_step);
}
