
#include "../cub3d_bonus.h"
int hasOpenDoorAt(t_game *game, double x, double y)
{
    if (x <= 0 || x >= game->map.map_x || y <= 0 || y >= game->map.map_y)
        return true;
    int mapGridIndexX = floor(x);
    int mapGridIndexY = floor(y);
    return (game->map.map[mapGridIndexY][mapGridIndexX] == 'd');
}
void open_closest_door(t_game *game, int px, int py)
{
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    double min_distance = INT_MAX;
    double distance = 0;
    while (i < game->map.map_y)
    {
        j = 0;
        while (j < game->map.map_x)
        {
            if (game->map.map[i][j] == 'D')
            {
                distance = distanceBetweenPoints(px, py, j, i);
                if (distance < min_distance)
                {
                    min_distance = distance;
                    x = j;
                    y = i;
                }
            }
            j++;
        }
        i++;
    }
    if (min_distance < 3)
        game->map.map[y][x] = 'd';
}

void close_closest_door(t_game *game, int px, int py)
{
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    double min_distance = INT_MAX;
    double distance = 0;
    while (i < game->map.map_y)
    {
        j = 0;
        while (j < game->map.map_x)
        {
            if (game->map.map[i][j] == 'd')
            {
                distance = distanceBetweenPoints(px, py, j, i);
                if (distance < min_distance)
                {
                    min_distance = distance;
                    x = j;
                    y = i;
                }
            }
            j++;
        }
        i++;
    }
    if (min_distance < 3)
        game->map.map[y][x] = 'D';
}

static int	door_action(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_E && keydata.action == MLX_PRESS)
	{
        open_closest_door(game, game->map.player.x, game->map.player.y); // check if door is fully closed
		return (1);
	}
    else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
    {
        if (!hasOpenDoorAt(game, game->map.player.x, game->map.player.y))
            close_closest_door(game, game->map.player.x, game->map.player.y);
		return (1);
    }
	return (0);
}

static int	mini_map_action(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
    {
        if (game->map.mini_map_size == game->win_width / 10)
            game->map.mini_map_size = game->win_height;
        else
            game->map.mini_map_size = game->win_width / 10;
		return (1);
    }
	return (0);
}

static void	gun_switch_action(mlx_key_data_t keydata, t_game *game)
{
    if (keydata.key == MLX_KEY_1 && keydata.action == MLX_PRESS)
    {
        game->map.player.gun_id = 0;
        game->map.player.move_speed = 0.4;
    }
    else if (keydata.key == MLX_KEY_2 && keydata.action == MLX_PRESS)
    {
        game->map.player.gun_id = 1;
        game->map.player.move_speed = 0.2;
    }
    else if (keydata.key == MLX_KEY_3 && keydata.action == MLX_PRESS)
    {
        game->map.player.gun_id = 2;
        game->map.player.move_speed = 0.2;
    }
    else if (keydata.key == MLX_KEY_4 && keydata.action == MLX_PRESS)
    {
        game->map.player.gun_id = 3;
        game->map.player.move_speed = 0.2;
    }
}

void actions(mlx_key_data_t keydata, void *param)
{
    t_game *game;

    game = (t_game *)param;
    
	if (door_action(keydata, game))
		return ;
	else if (mini_map_action(keydata, game))
		return ;
	else
		gun_switch_action(keydata, game);
}