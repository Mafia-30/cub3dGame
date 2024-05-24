
#include "../cub3d_bonus.h"

void init_map(t_game *game)
{
    game->we_pixels = load_texture(game, game->we_texture, game->tile_size, game->tile_size);
    game->ea_pixels = load_texture(game, game->ea_texture, game->tile_size, game->tile_size);
    game->no_pixels = load_texture(game, game->no_texture, game->tile_size, game->tile_size);
    game->so_pixels = load_texture(game, game->so_texture, game->tile_size, game->tile_size);
    game->door_pixels = load_texture(game, game->door_texture, game->tile_size, game->tile_size);
}
