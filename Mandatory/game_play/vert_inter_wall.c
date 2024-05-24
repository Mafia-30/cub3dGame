

#include "../cub3d.h"

static void get_x_step(double *xstep, bool is_ray_left)
{
	*xstep = 1;
	if (is_ray_left)
		*xstep *= -1;
}

static void get_y_step(double *ystep, double ray_angle)
{
	bool is_ray_down;

	if (sin(ray_angle) > 0)
		is_ray_down = true;
	else
		is_ray_down = false;
	*ystep = 1 * tan(ray_angle);
	if (!is_ray_down && *ystep > 0)
		*ystep *= -1;
	if (is_ray_down && *ystep < 0)
		*ystep *= -1;
}

static void get_first_intersection(t_game *game, t_point *intersect, bool *is_ray_left, double ray_angle)
{
	if (cos(ray_angle) < 0)
		*is_ray_left = true;
	else
		*is_ray_left = false;
	intersect->x = floor(game->map.player.x);
	if (!(*is_ray_left))
		intersect->x += 1;
	intersect->y = game->map.player.y + ((intersect->x - game->map.player.x) * tan(ray_angle));
}

static t_point get_vert_intersect(t_game *game, double ray_angle, bool *foundVertHit)
{
	t_point intersect;
	double s_x;
	double xstep;
	double ystep;
	bool is_ray_left;

	get_first_intersection(game, &intersect, &is_ray_left, ray_angle);
	get_x_step(&xstep, is_ray_left);
	get_y_step(&ystep, ray_angle);
	while (intersect.x > 0 && intersect.x < game->map.map_x && intersect.y > 0 && intersect.y < game->map.map_y)
	{
		s_x = intersect.x;
		if (is_ray_left)
			s_x -= 0.1;
		if (hasWallAt(game, s_x, intersect.y))
			return (*foundVertHit = true, intersect);
		else
		{
			intersect.x += xstep;
			intersect.y += ystep;
		}
	}
	return (intersect);
}

double get_vert_distance(t_game *game, double ray_angle, bool *foundVertHit, t_point *vert_intersect)
{
	double distance;

	*vert_intersect = get_vert_intersect(game, ray_angle, foundVertHit);
	if (*foundVertHit)
		distance = distanceBetweenPoints(game->map.player.x * game->tile_size, game->map.player.y * game->tile_size, vert_intersect->x * game->tile_size, vert_intersect->y * game->tile_size);
	if (*foundVertHit)
		return (distance);
	return (LONG_MAX);
}
