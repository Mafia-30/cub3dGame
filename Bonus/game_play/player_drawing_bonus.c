
#include "../cub3d_bonus.h"

void draw_player(t_game *game)
{
    uint32_t *pixels;
    int i;
    int j;
    int x;
    int y;

	pixels = game->map.player.guns[game->map.player.gun_id].gun_pixels[game->map.player.gun_image_id];
	i = 0;
	y = game->win_height - (game->win_height * 0.6);
    while (i < (game->win_height * 0.6))
    {
        j = 0;
        x = game->win_width / 2;
        while (j < (game->win_height * 0.6))
        {
            if (pixels[(int)(i * (game->win_height * 0.6)) + j] << 24)
                mlx_put_pixel(game->map.win_image, x, y, pixels[(int)(i * (game->win_height * 0.6)) + j]);
            j++;
            x++;
        }
        i++;
        y++;
    }
}
