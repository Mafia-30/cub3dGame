#include "../cub3d.h"

void missing_elem(t_game *game)
{
    if (!game->no_texture || !game->so_texture || !game->we_texture || !game->ea_texture)
        error_exit("Error\nMissing texture");
    if (!game->floor_color_set || !game->ciel_color_set)
    {
        error_exit("Error\nMissing color");
    }
}

bool is_valid_ele(char c)
{
    return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == ' ');
}

int is_map_line(t_game *game, char *line)
{
    int i;

    missing_elem(game);
    if (game->map.empty_line_in_map > 0 && line)
        error_exit("Error\n emplty line in map");
    i = 0;
    while (line[i])
    {
        if (is_valid_ele(line[i]))
            i++;
        else
            error_exit("Error\nInvalid map content");
    }
    if (game->map.map_x < (int)ft_strlen(line))
    {
        game->map.map_x = ft_strlen(line);
    }
    return (1);
}
