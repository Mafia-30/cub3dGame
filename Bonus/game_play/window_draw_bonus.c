

#include "../cub3d_bonus.h"


static void reset_view(t_game *game, double *ray_angle, int *idx)
{
    mlx_delete_image(game->mlx, game->map.win_image);
    game->map.win_image = mlx_new_image(game->mlx, game->win_width, game->win_height);
	if (!game->map.win_image)
		error_exit ("Error!\nImage creation failure!");
    *ray_angle = game->map.player.rotation_angle - (game->map.player.FOV / 2);
    *idx = 0;
}

static void calculate_distances(t_game *game, double *rayDistance, double ray_angle)
{
	*rayDistance = 0;
    draw_intersect(game, ray_angle, rayDistance);
    *rayDistance = *rayDistance * cos(ray_angle - game->map.player.rotation_angle); // fix fisheye effect1
}

static void    clear_doors_lst(t_drawable_doors *doors)
{
    t_drawable_doors *d;

    while (doors)
    {
        d = doors;
        doors = doors->next;
        free (d);
    }
}

static void draw_found_doors(t_game *game, t_drawable_doors *doors, double rayDistance, int idx)
{
    t_drawable_doors *d;
    int wallHeight;

    d = doors;
    while (d->next)
        d = d->next;
    while (d)
    {
        game->hitten_door_index = d->hitten_door_index;
        game->intersection_type_door = d->inter_type;
        game->inter_door = d->inter_door;
        if (d->ray_distance < rayDistance) //because it might have
        {
            game->allow_door_drawing = true;
            wallHeight = game->tile_size / d->ray_distance * game->dpp;
            draw_strip ((t_point){.x = idx * (game->win_width / game->map.player.rays_num), .y = (game->win_height / 2) - (wallHeight / 2)},
               wallHeight,
               game); // idx * (game->win_width / game->map.player.rays_num) is the same as idx since win_width is also rays_num
            game->allow_door_drawing = false;
        }
        d = d->prev;
    }
    clear_doors_lst(doors);
}

void display_all(t_game *game)
{
    int					idx;
    double 				wallHeight;
    double 				rayDistance;
    double 				ray_angle;
    t_drawable_doors 	*d_lst;

    d_lst = NULL;
    reset_view(game, &ray_angle, &idx);
    while (idx < game->map.player.rays_num)
    {
        calculate_distances(game, &rayDistance, ray_angle);
        d_lst = get_drawable_doors(game, ray_angle);
        wallHeight = game->tile_size / rayDistance * game->dpp;
        draw_strip((t_point){.x = idx * (game->win_width / game->map.player.rays_num), .y = (game->win_height / 2) - (wallHeight / 2)},
                   wallHeight,
                   game);
        if (d_lst)
            draw_found_doors (game, d_lst, rayDistance, idx);
        ray_angle += game->map.player.FOV / game->map.player.rays_num;
        idx++;
    }
    draw_player(game);
    mlx_image_to_window(game->mlx, game->map.win_image, 0, 0); //
}
