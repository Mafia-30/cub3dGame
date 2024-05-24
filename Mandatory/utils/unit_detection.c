

#include "../cub3d.h"

int hasWallAt(t_game *game, double x, double y)
{
    if (x <= 0 || x >= game->map.map_x || y <= 0 || y >= game->map.map_y)
        return true;
    int mapGridIndexX = floor(x);
    int mapGridIndexY = floor(y);
    return (game->map.map[mapGridIndexY][mapGridIndexX] == '1');
}
