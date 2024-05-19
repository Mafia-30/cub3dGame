#include "../cub3d_bonus.h"

int cub_atoi(const char *str, char c)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (str[i] && ft_isspace(str[i]))
        i++;
    if (str[i] == '+')
        i++;
    if (str[i] == '-' )
        error_exit("Error\nInvalid file content (negative color)");
    if (str[i] < '0' || str[i] > '9')
        error_exit("Error\nInvalid file content (color value)");
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        i++;
    }
    if (str[i] != '\0' && str[i] != ',' && !ft_isspace(str[i]))
        error_exit("Error\nInvalid file content (color value)");
    if (c == 'l')
        while (str[i])
             if (str[i] != '\0' && !ft_isspace(str[i++]))
                error_exit("Error\nInvalid file content (color value)");
    return (res);
}
