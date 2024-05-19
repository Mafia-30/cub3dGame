#include "cub3d_bonus.h"

int	main(int ac, char **av)
{
    t_game	game;

    if (ac != 2)
        error_exit("Error\nInvalid number of arguments");
    init_game(&game);
    scan_file(&game, av[1]);
    adjust_matrix(&game.map);
    store_doors_info(&game);
    render_map(&game);
    free_game(&game);
    return 0;
}