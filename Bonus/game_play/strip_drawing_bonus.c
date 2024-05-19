#include "../cub3d_bonus.h"

static void	update_doors_first_x(t_game *game)
{
	int	i;
	static int c;

	i = 0;
	if (c == 200)
	{
		c = 0;
		while (i < game->map.doors_num)
		{
			if (game->map.map[(int)game->map.doors[i].pos.y][(int)game->map.doors[i].pos.x] == 'd' && game->map.doors[i].first_pixel_x < game->tile_size)
				game->map.doors[i].first_pixel_x++;
			else if (game->map.map[(int)game->map.doors[i].pos.y][(int)game->map.doors[i].pos.x] == 'D' && game->map.doors[i].first_pixel_x == game->tile_size)
				game->map.doors[i].first_pixel_x = game->tile_size - 1;
			else if (game->map.map[(int)game->map.doors[i].pos.y][(int)game->map.doors[i].pos.x] == 'D' && game->map.doors[i].first_pixel_x > 0)
				game->map.doors[i].first_pixel_x--;
			i++;
		}
	}
	c++;
}

static void put_pixel_to_window(t_game *game, t_point startPoint, int i, t_point p_index)
{
	if (game->allow_door_drawing)
	{
		if (p_index.x >= game->map.doors[game->hitten_door_index].first_pixel_x)
		{
			printf ("%d\n",game->hitten_door_index);
			if (game->door_pixels[(int) ((game->tile_size * p_index.y) + p_index.x) - game->map.doors[game->hitten_door_index].first_pixel_x] << 24)
				mlx_put_pixel(game->map.win_image, startPoint.x, startPoint.y + i, game->door_pixels[(int) ((game->tile_size * p_index.y) + p_index.x) - game->map.doors[game->hitten_door_index].first_pixel_x]);
		}
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
	update_doors_first_x (game);
}