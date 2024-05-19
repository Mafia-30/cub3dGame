#include "../cub3d_bonus.h"

static void    add_door(t_drawable_doors **lst, double ray_distance, t_game *game, double ray_angle)
{
    t_drawable_doors *new;
    t_drawable_doors *old;

    new = (t_drawable_doors *) malloc (sizeof(t_drawable_doors));
	if (!new)
		error_exit ("Error!\nAllocation failed!");
    ray_distance = ray_distance * cos(ray_angle - game->map.player.rotation_angle);
    new->ray_distance = ray_distance;
    new->inter_type = game->intersection_type_door;
    new->hitten_door_index = game->hitten_door_index;
    new->next = NULL;
    new->prev = NULL;
    new->inter_door = game->inter_door;
    if (!*lst)
    {
        *lst = new;
        return ;
    }
    old = *lst;
    while (old->next)
        old = old->next;
    old->next = new;
    new->prev = old;
}

t_drawable_doors *get_drawable_doors(t_game *game, double ray_angle)
{
    t_drawable_doors *d;
    double  ray_distance;

    d = NULL;
    game->found_doors = 0;
    draw_intersect_door(game, ray_angle, &ray_distance);
    while (ray_distance)
    {
        add_door(&d, ray_distance, game, ray_angle);
        game->found_doors++;
        draw_intersect_door(game, ray_angle, &ray_distance);
    }
    return (d);
}