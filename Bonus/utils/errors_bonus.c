#include "../cub3d_bonus.h"

void    free_guns_pixel(t_gun gun)
{
    free (gun.gun_pixels[0]);
    free (gun.gun_pixels[1]);
    free (gun.gun_pixels[2]);
    free (gun.gun_pixels[3]);
    free (gun.gun_pixels[4]);
}

void free_game(t_game *game)
{
    int i;

    i = 0;
    while (i < game->map.map_y)
    {
        free(game->map.map[i]);
        i++;
    }
    free (game->map.map);
    free(game->no_pixels);
    free(game->so_pixels);
    free(game->we_pixels);
    free(game->ea_pixels);
    free (game->door_pixels);
    free(game->no_texture);
    free(game->so_texture);
    free(game->we_texture);
    free(game->ea_texture);
    free_guns_pixel (game->map.player.guns[0]);
    free_guns_pixel (game->map.player.guns[1]);
    free_guns_pixel (game->map.player.guns[2]);
    free_guns_pixel (game->map.player.guns[3]);
}

void		error_exit(char *message)
{
    ft_putstr_fd (message, 2);
    write (2, "\n", 1);
    exit(1);
}
