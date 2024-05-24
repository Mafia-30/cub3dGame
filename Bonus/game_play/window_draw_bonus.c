
#include "../cub3d_bonus.h"


static void reset_view(t_game *game, double *ray_angle, int *idx)
{
    mlx_delete_image(game->mlx, game->map.win_image);
    game->map.win_image = mlx_new_image(game->mlx, game->win_width, game->win_height);
	if (!game->map.win_image)
		error_exit ("Error!\nImage creation failure!");
    *ray_angle = game->map.player.rotation_angle - (game->map.player.FOV / 2);
    *idx = -1;
}

static void calculate_distances(t_game *game, double *rayDistance, double ray_angle)
{
	*rayDistance = 0;
    draw_intersect(game, ray_angle, rayDistance);
    *rayDistance = *rayDistance * cos(ray_angle - game->map.player.rotation_angle);
}

void display_all(t_game *game)
{
    int					idx;
    double 				wallHeight;
    double 				rayDistance;
    double 				ray_angle;
    double              ray_distance_door;

    reset_view(game, &ray_angle, &idx);
    while (++idx < game->map.player.rays_num)
    {
        calculate_distances(game, &rayDistance, ray_angle);
        draw_intersect_door(game, ray_angle, &ray_distance_door);
        if (rayDistance < ray_distance_door)
            wallHeight = game->tile_size * game->dpp / rayDistance;
        else
        {
            game->allow_door_drawing = true;
            wallHeight = game->tile_size / ray_distance_door * game->dpp;
        }
        draw_strip ((t_point){.x = idx * (game->win_width / game->map.player.rays_num),
            .y = (game->win_height / 2) - (wallHeight / 2)}, wallHeight, game);
        game->allow_door_drawing = false;
        ray_angle += game->map.player.FOV / game->map.player.rays_num;
    }
    draw_player(game);
    mlx_image_to_window(game->mlx, game->map.win_image, 0, 0);
}
