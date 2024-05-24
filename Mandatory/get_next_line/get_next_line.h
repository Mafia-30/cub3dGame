/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:30:34 by ymahni            #+#    #+#             */
/*   Updated: 2024/05/24 18:04:10 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include "../cub3d.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

char *get_next_line(int fd);
char *clean_cache(char **cache, char *line);
void ft_fill_cache(int fd, char **cache, int *bytes_read);
int find_end_line(char *s);
// char	*ft_substr(char const *s, unsigned int start, unsigned int end);
// char	*ft_strdup(const char *str);
char *gnl_strjoin(char *s1, char const *s2);
// void	ft_strlcpy(char *dst, const char *src, size_t dstsize);
// int		ft_strlen(const char *s);

#endif
