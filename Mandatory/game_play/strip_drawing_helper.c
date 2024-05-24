
#include "../cub3d.h"

int	get_texture_y(int y, double height, t_game *game)
{
	int	index_y;

	index_y = (y * (game->tile_size / height));
	return (index_y);
}

int	get_texture_x(t_game *game)
{
	int		index_x;
	char	inter_type;
	t_point	inter_point;

	inter_type = game->intersection_type;
	inter_point = game->inter;
	if (inter_type == 't' || inter_type == 'b')
		index_x = (int)(inter_point.x * game->tile_size) % game->tile_size;
	else
		index_x = (int)(inter_point.y * game->tile_size) % game->tile_size;
	if (inter_type == 'b' || inter_type == 'l')
		index_x = game->tile_size - index_x;
	if (index_x == game->tile_size)
		index_x--;
	return (index_x);
}
