#include "../cub3d_bonus.h"

int start_with(char *line, char c1, char c2)
{
    int i;

    i = 0;
    while (ft_isspace(line[i]))
        i++;
    if (line[i] == c1)
    {
        if (c2 && line[i + 1] == c2)
            return (1);
        else if (!c2)
            return (1);
    }
    return (0);
}
