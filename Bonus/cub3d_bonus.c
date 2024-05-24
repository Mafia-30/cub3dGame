#include "cub3d_bonus.h"

void f()
{
    system ("leaks cub3d_bonus");
}

int	main(int ac, char **av)
{
    atexit (f);
    t_game	game;

    if (ac != 2)
        error_exit("Error\nInvalid number of arguments");
    init_game(&game);
    scan_file(&game, av[1]);
    render_map(&game);
    free_game(&game);
    return 0;
}