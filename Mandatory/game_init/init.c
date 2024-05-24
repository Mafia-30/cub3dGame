
#include "../cub3d.h"

static void init_player(t_player *player)
{
    player->x = -1;
    player->y = -1;
    player->turn_dir = 0;
    player->walk_dir = 0;
    player->walk_sid = 0;
    player->rotation_angle = M_PI_2;
    player->move_speed = .2;
    player->rotation_speed = 3 * (M_PI / 180);
    player->FOV = 60 * (M_PI / 180);
}

static void set_map_info(t_game *game)
{
    game->map.map = NULL;
    game->no_texture = NULL;
    game->so_texture = NULL;
    game->we_texture = NULL;
    game->ea_texture = NULL;
    game->floor_color_set = false;
    game->ciel_color_set = false;
    game->map.map_x = 0;
    game->map.map_y = 0;
    game->win_width = 2000;
    game->win_height = 1000;
    game->tile_size = 400;
    game->mlx = NULL;
    game->map.empty_line_in_map = 0;
    game->map.win_image = NULL;
    game->dpp = (game->win_width / 2) / tan(game->map.player.FOV / 2);
    game->map.player.rays_num = game->win_width;
}

void init_game(t_game *game)
{
    init_player(&game->map.player);
    set_map_info(game);
}