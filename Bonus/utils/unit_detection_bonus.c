#include "../cub3d_bonus.h"


int hasDoorAt(t_game *game, double x, double y)
{
    if (x <= 0 || x >= game->map.map_x || y <= 0 || y >= game->map.map_y)
        return true;
    int mapGridIndexX = floor(x);
    int mapGridIndexY = floor(y);
    if (game->map.map[mapGridIndexY][mapGridIndexX] == 'D')
    {
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

void open_closest_door(t_game *game, int px, int py)
{
    t_point ij;
    t_point door;
    double min_distance;
    double distance;

    ij.x = -1;
    min_distance = INT_MAX;
    distance = 0;
    while (++ij.x < game->map.map_y)
    {
        ij.y = -1;
        while (++ij.y < game->map.map_x)
            if (game->map.map[(int)ij.x][(int)ij.y] == 'D')
            {
                distance = distanceBetweenPoints(px, py, ij.y, ij.x);
                if (distance < min_distance)
                {
                    min_distance = distance;
                    door.x = ij.y;
                    door.y = ij.x;
                }
            }
    }
    if (min_distance < 3)
        game->map.map[(int)door.y][(int)door.x] = 'd';
}

void close_closest_door(t_game *game, int px, int py)
{
    t_point ij;
    t_point door;
    double min_distance;
    double distance;

    ij.x = -1;
    min_distance = INT_MAX;
    distance = 0;
    while (++ij.x < game->map.map_y)
    {
        ij.y = -1;
        while (++ij.y < game->map.map_x)
            if (game->map.map[(int)ij.x][(int)ij.y] == 'd')
            {
                distance = distanceBetweenPoints(px, py, ij.y, ij.x);
                if (distance < min_distance)
                {
                    min_distance = distance;
                    door.x = ij.y;
                    door.y = ij.x;
                }
            }
    }
    if (min_distance < 3)
        game->map.map[(int)door.y][(int)door.x] = 'D';
}
