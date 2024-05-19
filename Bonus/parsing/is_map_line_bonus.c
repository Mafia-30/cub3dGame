#include "../cub3d_bonus.h"

void missing_elem(t_game *game)
{
    if (!game->no_texture || !game->so_texture || !game->we_texture || !game->ea_texture)
        error_exit("Error\nMissing texture");
    if (game->floor_color == -1 || game->ceiling_color == -1)
        error_exit("Error\nMissing color");
}

bool is_valid_ele(char c)
{
    return (c == '0' || c == '1' || c == 'D' || c == 'N' || c == 'S' || c == 'W' || c == 'E' || ft_isspace(c));
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
