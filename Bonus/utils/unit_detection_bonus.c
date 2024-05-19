

#include "../cub3d_bonus.h"

static int get_hitten_door_index(t_game *game, int x, int y)
{
    int i = 0;

    while (i < game->map.doors_num)
    {
        if ((int) game->map.doors[i].pos.x == x && (int) game->map.doors[i].pos.y == y)
            return (i);
        i++;
    }
    return (-1);
}

int hasDoorAt(t_game *game, double x, double y)
{
    if (x <= 0 || x >= game->map.map_x || y <= 0 || y >= game->map.map_y)
        return true;
    int mapGridIndexX = floor(x);
    int mapGridIndexY = floor(y);
    if (game->map.map[mapGridIndexY][mapGridIndexX] == 'D' || game->map.map[mapGridIndexY][mapGridIndexX] == 'd')
    {
        game->hitten_door_index = get_hitten_door_index(game, mapGridIndexX, mapGridIndexY); // maby the hitten door index is changed between the verical intersection and the horizontal one
        return (1);
    }
    return (0);
}

int hasWallAt(t_game *game, double x, double y)
{
    if (x <= 0 || x >= game->map.map_x || y <= 0 || y >= game->map.map_y)
        return true;
    int mapGridIndexX = floor(x);
    int mapGridIndexY = floor(y);
    return (game->map.map[mapGridIndexY][mapGridIndexX] == '1');
}

