
#include "../cub3d_bonus.h"

static void init_player(t_player *player)
{
    player->x = -1;
    player->y = -1;
    player->turn_dir = 0;
    player->turn_dir_mouse = 0;
    player->walk_dir = 0;
    player->walk_sid = 0;
    player->rotation_angle = M_PI_2 ;
    player->move_speed = .2;
    player->rotation_speed = 3 * (M_PI / 180);
    player->gun_id  = 0;
    player->shooting  = 0;
    player->FOV = 60 * (M_PI / 180);
    player->gun_id = 1;
    player->gun_image_id = 0;
}

static void set_map_info(t_game *game)
{
    game->map.map = NULL;
    game->no_texture = NULL;
    game->so_texture = NULL;
    game->we_texture = NULL;
    game->ea_texture = NULL;
    game->door_texture = "Bonus/assets/walls/door.png";
    game->floor_color = -1;
    game->ceiling_color = -1;
    game->map.map_x = 0;
    game->map.map_y = 0;
    game->win_width = 2000;
    game->win_height = 1000;
    game->tile_size = 400;
    game->mlx = NULL;
    game->map.empty_line_in_map = 0;
    game->map.win_image = NULL;
    game->allow_door_drawing = false;
    game->map.mini_map_size = game->win_width/10;
    game->hitten_door_index = -1;
    game->map.doors = NULL;
	game->dpp = (game->win_height) / tan(game->map.player.FOV / 2);
    game->map.player.rays_num = game->win_width;

}

void    init_game(t_game *game)
{
    init_player(&game->map.player);
    set_map_info (game);
}