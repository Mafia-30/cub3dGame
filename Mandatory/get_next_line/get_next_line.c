/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:00:15 by ymahni            #+#    #+#             */
/*   Updated: 2024/04/17 07:03:02 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_end_line(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_fill_cache(int fd, char **cache, int *bytes_read)
{
	char	*temp;
	char	*buffer;

	while (find_end_line(*cache) == -1)
	{
		buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (!buffer)
		{
			free(*cache);
			*cache = NULL;
			return ;
		}
		*bytes_read = (int) read(fd, buffer, BUFFER_SIZE);
		if (*bytes_read <= 0)
		{
			free(buffer);
			buffer = NULL;
			return ;
		}
		buffer[*bytes_read] = '\0';
		temp = gnl_strjoin(*cache, buffer);
		free(*cache);
		*cache = temp;
		free(buffer);
	}
}

static char	*remove_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		i++;
	}
	return (line);
}

char	*clean_cache(char **cache, char *line)
{
	char	*temp;
	int		i;
	int		end;

	i = find_end_line(*cache);
	end = ft_strlen(*cache) - 1;
	if (i == -1 || i == end)
	{
		free(*cache);
		*cache = NULL;
	}
	else
	{
		temp = ft_substr(*cache, i + 1, end);
		free(*cache);
		*cache = temp;
		if (!temp)
		{
			free(line);
			return (NULL);
		}
	}
	return (remove_newline(line));
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*line;
	int			bytes_read;

	line = NULL;
	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_fill_cache(fd, &cache, &bytes_read);
	if (cache == NULL || bytes_read == -1)
	{
		free(cache);
		cache = NULL;
		return (NULL);
	}
	line = ft_substr(cache, 0, find_end_line(cache));
	if (!line)
	{
		free(cache);
		cache = NULL;
		return (NULL);
	}
	return (clean_cache(&cache, line));
}
