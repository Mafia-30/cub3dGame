
#include "../cub3d_bonus.h"


static void draw_mini_player(t_game *game)
{
    int i;
    int j;
    int dx;
    int dy;

    i = -4;
    j = 0;
	dx = game->map.mini_map_size / 2 + 20;
	dy = 20;
	if (game->map.mini_map_size == game->win_height)
	{
		dx = game->win_width / 2;
		dy = 0;
	}
    while (++i < 3)
    {
        j = -4;
        while (++j < 3)
            mlx_put_pixel(game->map.win_image, (dx + j),(game->map.mini_map_size / 2 + i + dy), 0xff0000ff);
    }
    draw_line(game->map.win_image, dx, game->map.mini_map_size / 2 + dy,
	dx + cos(game->map.player.rotation_angle) * 20,dy + game->map.mini_map_size
	/ 2 + sin(game->map.player.rotation_angle) * 20);
}

static bool inside_mini_map(t_game *game, int i, int j)
{
    int player_x;
    int player_y;
    int zoom;

    zoom = (int)game->map.mini_map_size * 0.06;
    player_x = game->map.player.x * (game->tile_size);
    player_y = game->map.player.y * (game->tile_size);
    return (((player_y - ((zoom / 2) * (game->tile_size)) + 
	(i * (zoom * (game->tile_size)) / game->map.mini_map_size)) 
	/ (game->tile_size)) >= 0 && ((player_y - ((zoom / 2) * (game->tile_size)) 
	+ (i * (zoom * (game->tile_size)) / game->map.mini_map_size)) / (game->tile_size))
	 < game->map.map_y && ((player_x - ((zoom / 2) * (game->tile_size)) + 
	 (j * (zoom * (game->tile_size)) / game->map.mini_map_size)) / 
	 (game->tile_size)) >= 0 && ((player_x - ((zoom / 2) * (game->tile_size)) 
	 + (j * (zoom * (game->tile_size)) / game->map.mini_map_size)) / 
	 (game->tile_size)) < game->map.map_x);
}

static char get_map_char(t_game *game, int zoom, int i, int j)
{
    return (game->map.map
        [(int)(((game->map.player.y * game->tile_size) - 
		((zoom / 2) * game->tile_size) + (i * (zoom * game->tile_size) 
		/ game->map.mini_map_size)) / game->tile_size)]
        [(int)(((game->map.player.x * game->tile_size) - 
		((zoom / 2) * game->tile_size) + (j * (zoom * game->tile_size)
		/ game->map.mini_map_size)) / game->tile_size)]);
}

static void draw_maze(t_game *game, int i, int j)
{
    int zoom;
    int dx;
    int dy;

	dx = 20;
	dy = 20;
	if (game->map.mini_map_size == game->win_height)
	{
		dx = game->win_width / 2 - game->win_height / 2;
		dy = 0;
	}
    zoom = (int)game->map.mini_map_size * 0.06;
    if (inside_mini_map(game, i, j))
    {
        if (get_map_char(game, zoom, i, j) == '1')
            mlx_put_pixel(game->map.win_image, j + dx, i + dy, 0xdee2e6ff);
        else if (get_map_char(game, zoom, i, j) == 'D')
            mlx_put_pixel(game->map.win_image, j + dx, i + dy, 0x008200ff);
        else if (get_map_char(game, zoom, i, j) == 'd')
            mlx_put_pixel(game->map.win_image, j + dx, i + dy, 0x0000ffff);
        else
            mlx_put_pixel(game->map.win_image, j + dx, i + dy, 0x000000ff);
    }
    else
        mlx_put_pixel(game->map.win_image, j + dx, i + dy, 0x000000ff);
}

void draw_mini_map(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (i < game->map.mini_map_size)
    {
        j = 0;
        while (j < game->map.mini_map_size)
        {
            draw_maze(game, i, j);
            j++;
        }
        i++;
    }
    draw_mini_player(game);
}
