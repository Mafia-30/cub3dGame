#include "../cub3d_bonus.h"

static void put_pixel_to_window(t_game *game, t_point startPoint, int i, t_point p_index)
{
	if (game->allow_door_drawing)
	{
			if (game->door_pixels[(int) ((game->tile_size * p_index.y) + p_index.x)] << 24)
				mlx_put_pixel(game->map.win_image, startPoint.x, startPoint.y + i, game->door_pixels[(int) ((game->tile_size * p_index.y) + p_index.x)]);
	}
	else if (game->intersection_type == 'r')
		mlx_put_pixel(game->map.win_image, startPoint.x, startPoint.y + i, game->ea_pixels[(int) ((game->tile_size * p_index.y) + p_index.x)]);
	else if (game->intersection_type == 'l')
		mlx_put_pixel(game->map.win_image, startPoint.x, startPoint.y + i, game->we_pixels[(int) ((game->tile_size * p_index.y) + p_index.x)]);
	else if (game->intersection_type == 't')
		mlx_put_pixel(game->map.win_image, startPoint.x, startPoint.y + i, game->no_pixels[(int) ((game->tile_size * p_index.y) + p_index.x)]);
	else if (game->intersection_type == 'b')
		mlx_put_pixel(game->map.win_image, startPoint.x, startPoint.y + i, game->so_pixels[(int) ((game->tile_size * p_index.y) + p_index.x)]);
}

static void draw_ceil(int end_y, int x, t_game *game)
{
    int i = 0;
    while (i < end_y)
    {
        mlx_put_pixel(game->map.win_image, x, i, game->ceiling_color);
        i++;
    }
}

static void draw_floor(int start_y, int x, t_game *game)
{
    int i = start_y;
    while (i < game->win_height)
    {
        mlx_put_pixel(game->map.win_image, x, i, game->floor_color);
        i++;
    }
}

void draw_strip(t_point startPoint, double height, t_game *game)
{
	int i;
	t_point p_index;

	i = 0;
	draw_ceil(startPoint.y, startPoint.x, game);
	draw_floor(startPoint.y + height, startPoint.x, game);
	p_index.x = get_texture_x(game);
	while (i < height)
	{
		if (game->win_height > startPoint.y + i && startPoint.y + i >= 0 && game->win_width > startPoint.x && startPoint.x >= 0)
		{
			p_index.y = get_texture_y(i, height, game);
			put_pixel_to_window (game, startPoint, i, p_index);
		}
		i++;
	}
}
