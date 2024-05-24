
#include "../cub3d_bonus.h"

static void	store_pixels(uint32_t *pixels, mlx_image_t *img, int w, int h)
{
	int		i;
	int		j;
	t_color	c;

	i = 0;
	j = 0;
	while (i < w * h * 4)
	{
		c.r = img->pixels[i];
		c.g = img->pixels[i + 1];
		c.b = img->pixels[i + 2];
		c.a = img->pixels[i + 3];
		pixels[j++] = (c.r << 24) + (c.g << 16) + (c.b << 8) + c.a;
		i += 4;
	}
}

uint32_t	*load_texture(t_game *game, char *path, int w, int h)
{
	uint32_t		*pixels;
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	pixels = malloc(w * h * sizeof(uint32_t));
	if (!pixels)
		error_exit("Error\nAllocation failed!");
	texture = mlx_load_png(path);
	if (!texture)
		error_exit("Error\nTexture openning error!");
	img = mlx_texture_to_image(game->mlx, texture);
	if (!mlx_resize_image(img, w, h))
		error_exit("Error\nImage resizing failure!");
	mlx_delete_texture(texture);
	store_pixels(pixels, img, w, h);
	return (pixels);
}

void	init_arm(t_game *game, char *gun[5])
{
	static int	gun_id;
	int			i;

	i = 0;
	while (i < 5)
	{
		game->map.player.guns[gun_id].gun_pixels[i] = load_texture(game, gun[i],
				game->win_height * 0.6, game->win_height * 0.6);
		i++;
	}
	gun_id++;
}
