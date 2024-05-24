
#include "../cub3d_bonus.h"

static void	draw_mini_player(t_game *game)
{
	int	i;
	int	j;
	int	dx;
	int	dy;

	i = -4;
	j = 0;
	dx = game->map.mini_map_size / 2 + 20;
	dy = game->map.mini_map_size / 2 + 20;
	if (game->map.mini_map_size == game->win_height)
	{
		dx = game->win_width / 2;
		dy = game->win_height / 2;
	}
	while (++i < 3)
	{
		j = -4;
		while (++j < 3)
			mlx_put_pixel(game->map.win_image, (j + dx), (i + dy), 0xff0000ff);
	}
	draw_line(game->map.win_image, dx, dy, dx + 20
		* cos(game->map.player.rotation_angle), 20
		* sin(game->map.player.rotation_angle) + dy);
}

static char	get_map_char2(t_game *game, double x, double y)
{
	x /= game->tile_size;
	y /= game->tile_size;
	if (y >= 0 && y < game->map.map_y && x >= 0 && x < game->map.map_x)
	{
		return (game->map.map[(int)y][(int)x]);
	}
	else
	{
		return ('0');
	}
}

static void	get_mini_map_info(t_game *game, int *dx, int *dy, double *factor)
{
	*dx = 20;
	*dy = 20;
	*factor = game->tile_size * 12 / game->map.mini_map_size;
	if (game->map.mini_map_size == game->win_height)
	{
		*dx = (game->win_width / 2) - (game->win_height / 2);
		*dy = 0;
		*factor = game->tile_size * 24 / game->map.mini_map_size;
	}
}

static void	draw_maze2(t_game *game, int i, int j)
{
	double	factor;
	int		dx;
	int		dy;
	char	unit;
	t_point	sp;

	get_mini_map_info(game, &dx, &dy, &factor);
	sp.x = (game->map.player.x * game->tile_size) - (factor
			* game->map.mini_map_size / 2);
	sp.y = (game->map.player.y * game->tile_size) - (factor
			* game->map.mini_map_size / 2);
	unit = get_map_char2(game, sp.x + j * factor, sp.y + i * factor);
	if (unit == '1')
		mlx_put_pixel(game->map.win_image, j + dx, i + dy, 0xdee2e6ff);
	else if (unit == 'D')
		mlx_put_pixel(game->map.win_image, j + dx, i + dy, 0x008200ff);
	else if (unit == 'd')
		mlx_put_pixel(game->map.win_image, j + dx, i + dy, 0x0000ffff);
	else
		mlx_put_pixel(game->map.win_image, j + dx, i + dy, 0x000000ff);
}

void	draw_mini_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.mini_map_size)
	{
		j = 0;
		while (j < game->map.mini_map_size)
		{
			draw_maze2(game, i, j);
			j++;
		}
		i++;
	}
	draw_mini_player(game);
}
