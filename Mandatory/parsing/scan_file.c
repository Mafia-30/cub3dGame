#include "../cub3d.h"

void	check_ext(char *file)
{
	int	i;

	i = 0;
	while (file && file[i])
		i++;
	if (i < 4 || file[i - 1] != 'b' || file[i - 2] != 'u' || file[i - 3] != 'c'
		|| file[i - 4] != '.')
		error_exit("Error\nFile extension is not valid");
}

void	read_file(t_game *game, char *file)
{
	int		fd;
	char	*line;

	(void)game;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("Error\nFile not found");
	line = get_next_line(fd);
	while (line)
	{
		parse_line(game, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	scan_file(t_game *game, char *file)
{
	check_ext(file);
	read_file(game, file);
	adjust_matrix(&game->map);
	is_surrounded(&game->map);
	game->map.player.x = game->map.player.x + 0.5;
	game->map.player.y = game->map.player.y + 0.5;
}
