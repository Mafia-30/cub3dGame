#include "../cub3d_bonus.h"

void	skip_content_name(char *line, int *i)
{
	*i = 0;
	while (ft_isspace(line[*i]) && line[*i] != '\0')
		(*i)++;
	while (!ft_isspace(line[*i]) && line[*i] != '\0')
		(*i)++;
	while (ft_isspace(line[*i]) && line[*i] != '\0')
		(*i)++;
	if (line[*i] == '\0')
		error_exit("Error\nInvalid file content");
}

void	parse_texture(char *line, char **texture)
{
	int	i;
	int	j;

	if (*texture)
		error_exit("Error\nTexture already defined");
	skip_content_name(line, &i);
	j = i;
	while (line[j] != '\0')
		j++;
	(*texture) = malloc(sizeof(char) * (j - i + 1));
	if (!(*texture))
		error_exit("Error\nMalloc failed");
	j = 0;
	while (line[i] != '\0')
		(*texture)[j++] = line[i++];
	(*texture)[j] = '\0';
}

void	parse_color(t_game *game, char *line, int *color, char type)
{
	int		i;
	t_color	rgb;

	i = 0;
	if ((type == 'f' && game->floor_color_set) || (type == 'c'
			&& game->ciel_color_set))
		error_exit("Error\nColor already defined");
	skip_content_name(line, &i);
	rgb.r = cub_atoi(&line[i], 'f');
	while (line[i] != ',' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		error_exit("Error\nInvalid file content");
	i++;
	rgb.g = cub_atoi(&line[i], 's');
	while (line[i] != ',' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		error_exit("Error\nInvalid file content");
	i++;
	rgb.b = cub_atoi(&line[i], 'l');
	*color = (rgb.r << 24) + (rgb.g << 16) + (rgb.b << 8) + 255;
	if (type == 'f')
		game->floor_color_set = true;
	else
		game->ciel_color_set = true;
}

void	parse_map(t_game *game, char *line)
{
	char	*new_line;

	new_line = ft_strdup(line);
	if (!new_line)
		error_exit("Error\nMalloc failed");
	append_line(game, new_line);
}

void	parse_line(t_game *game, char *line)
{
	if (start_with(line, 'N', 'O'))
		parse_texture(line, &game->no_texture);
	else if (start_with(line, 'S', 'O'))
		parse_texture(line, &game->so_texture);
	else if (start_with(line, 'W', 'E'))
		parse_texture(line, &game->we_texture);
	else if (start_with(line, 'E', 'A'))
		parse_texture(line, &game->ea_texture);
	else if (start_with(line, 'F', '\0'))
		parse_color(game, line, &game->floor_color, 'f');
	else if (start_with(line, 'C', '\0'))
		parse_color(game, line, &game->ceiling_color, 'c');
	else if (line[0] == '\0' && game->map.map_y == 0)
		return ;
	else if (line[0] == '\0' && game->map.map_y != 0)
		game->map.empty_line_in_map = 1;
	else if (is_map_line(game, line))
		parse_map(game, line);
	else
		error_exit("Error\nInvalid file content");
}
