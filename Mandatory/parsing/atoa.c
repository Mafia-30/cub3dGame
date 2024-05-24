#include "../cub3d.h"

void last_color(const char *str, char c, int i)
{
    if (c == 'l')
        while (str[i])
             if (str[i] != '\0' && !ft_isspace(str[i++]))
                error_exit("Error\nInvalid file content (color value)");
}


int cub_atoi(const char *str, char c)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (str[i] && ft_isspace(str[i]))
        i++;
    if (str[i] < '0' || str[i] > '9')
        error_exit("Error\nInvalid file content (color value)");
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        if (res > 255)
            error_exit("Error\nInvalid color value");
        i++;
    }
    if (str[i] != '\0' && str[i] != ',')
    {
        while (ft_isspace(str[i]))
            i++;
        if (str[i] != '\0' && str[i] != ',')
            error_exit("Error\nInvalid file content (color value)");
    }
    last_color(str, c, i);
    return (res);
}
