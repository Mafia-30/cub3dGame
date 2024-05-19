
#include "../cub3d_bonus.h"

int get_texture_y(int y, double height, t_game *game)
{
    int index_y;
    index_y = (y * (game->tile_size / height));
    return (index_y);
}

int get_texture_x(t_game *game)
{
    int index_x;
    if (game->allow_door_drawing)
    {
        if (game->intersection_type_door == 't' || game->intersection_type_door == 'b')
            index_x = (int)(game->inter_door.x * game->tile_size) % game->tile_size; // the first part wich is the multiplication because the inter_door x is not in pixels and the other one tho get the exact offsett of the the x because it might be bigger than tile size it self
        else
            index_x = (int)(game->inter_door.y * game->tile_size) % game->tile_size; // sinse the image is ts * ts then we can get the idex x by the y offsett and also all the rays that are gonna hit that wall like that are gonna have the same x so we better use the y since it is the one whose gonna be changing

        if (game->intersection_type_door == 'b' || game->intersection_type_door == 'l')
            index_x = game->tile_size - index_x; // because the wall in this cases is gonna start being drawn from left to right and in the other case it s gonna start be drawing from right to left
        if (index_x == game->tile_size)
            index_x--;
        return (index_x);
    }
    if (game->intersection_type == 't' || game->intersection_type == 'b')
        index_x = (int)(game->inter.x * game->tile_size) % game->tile_size;
    else
        index_x = (int)(game->inter.y * game->tile_size) % game->tile_size;

    if (game->intersection_type == 'b' || game->intersection_type == 'l')
        index_x = game->tile_size - index_x;
    if (index_x == game->tile_size)
        index_x--;
    return (index_x);
}
