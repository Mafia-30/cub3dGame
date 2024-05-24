

#include "../cub3d_bonus.h"

static void	get_first_intersection(t_game *game, t_point *intersect,
		bool *is_ray_down, double ray_angle)
{
	if (sin(ray_angle) > 0)
		*is_ray_down = true;
	else
		*is_ray_down = false;
	intersect->y = floor(game->map.player.y);
	if (*is_ray_down)
		intersect->y += 1;
	intersect->x = game->map.player.x + ((intersect->y - game->map.player.y)
			/ tan(ray_angle));
}

static void	get_y_step(double *ystep, bool is_ray_down)
{
	*ystep = 1;
	if (!is_ray_down)
		*ystep *= -1;
}

static void	get_x_step(double *xstep, double ray_angle)
{
	bool	is_ray_left;

	if (cos(ray_angle) < 0)
		is_ray_left = true;
	else
		is_ray_left = false;
	*xstep = 1 / tan(ray_angle);
	if (is_ray_left && *xstep > 0)
		*xstep *= -1;
	if (!is_ray_left && *xstep < 0)
		*xstep *= -1;
}

static t_point	get_horz_intersect(t_game *game, double ray_angle,
		bool *foundHorzHit)
{
	t_point	intersect;
	double	s_y;
	double	xstep;
	double	ystep;
	bool	is_ray_down;

	get_first_intersection(game, &intersect, &is_ray_down, ray_angle);
	get_y_step(&ystep, is_ray_down);
	get_x_step(&xstep, ray_angle);
	while (intersect.x > 0 && intersect.x < game->map.map_x && intersect.y > 0
		&& intersect.y < game->map.map_y)
	{
		s_y = intersect.y;
		if (!is_ray_down)
			s_y -= 0.1;
		if (hasWallAt(game, intersect.x, s_y))
			break ;
		if (hasDoorAt(game, intersect.x, s_y))
			return (*foundHorzHit = 1, intersect);
		intersect.x += xstep;
		intersect.y += ystep;
	}
	return (intersect);
}

double	get_horz_door_distance(t_game *game, double ray_angle,
		bool *foundHorzHit, t_point *horz_intersect)
{
	double distance;

	*horz_intersect = get_horz_intersect(game, ray_angle, foundHorzHit);
	if (*foundHorzHit)
		distance = distanceBetweenPoints(game->map.player.x * game->tile_size,
				game->map.player.y * game->tile_size, horz_intersect->x
				* game->tile_size, horz_intersect->y * game->tile_size);
	if (*foundHorzHit)
		return (distance);
	return (LONG_MAX);
}