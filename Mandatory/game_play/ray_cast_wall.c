
#include "../cub3d.h"

static void	store_vert_inter_info(t_game *game, double *ray_distance,
		t_point inter, double vertHitDistance)
{
	game->inter = inter;
	*ray_distance = vertHitDistance;
	if (game->map.player.x < inter.x)
		game->intersection_type = 'r';
	else
		game->intersection_type = 'l';
}

static void	store_horz_inter_info(t_game *game, double *ray_distance,
		t_point inter, double horzHitDistance)
{
	game->inter = inter;
	*ray_distance = horzHitDistance;
	if (game->map.player.y < inter.y)
		game->intersection_type = 'b';
	else
		game->intersection_type = 't';
}

void	draw_intersect(t_game *game, double ray_angle, double *ray_distance)
{
	bool	foundHorzHit;
	bool	foundVertHit;
	double	distances[2];
	t_point	horz_intersect;
	t_point	vert_intersect;

	foundHorzHit = false;
	foundVertHit = false;
	distances[0] = get_horz_distance(game, ray_angle, &foundHorzHit,
			&horz_intersect);
	distances[1] = get_vert_distance(game, ray_angle, &foundVertHit,
			&vert_intersect);
	if (foundHorzHit && foundVertHit)
	{
		if (distances[0] > distances[1])
			store_vert_inter_info(game, ray_distance, vert_intersect,
				distances[1]);
		else
			store_horz_inter_info(game, ray_distance, horz_intersect,
				distances[0]);
	}
	else if (foundHorzHit)
		store_horz_inter_info(game, ray_distance, horz_intersect, distances[0]);
	else if (foundVertHit)
		store_vert_inter_info(game, ray_distance, vert_intersect, distances[1]);
}
