/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:28:32 by ymahni            #+#    #+#             */
/*   Updated: 2024/05/19 13:18:03 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char *ft_realloc(char *str, size_t size)
{
    char *new_str;

    new_str = malloc(size);
    if (!new_str)
        error_exit("Error\nMalloc failed");
    ft_memcpy(new_str, str, ft_strlen(str));
    free(str);
    return (new_str);
}
