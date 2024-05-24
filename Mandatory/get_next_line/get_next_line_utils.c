/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:58:52 by ymahni            #+#    #+#             */
/*   Updated: 2024/04/17 07:02:49 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// void	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	index;

// 	if (size > 0)
// 	{
// 		index = -1;
// 		while (src[++index] && index < (size))
// 			dst[index] = src[index];
// 		dst[index] = '\0';
// 	}
// }

char	*gnl_strjoin(char *s1, char const *s2)
{
	size_t	s1s;
	size_t	s2s;
	char	*join;

	if (s1 == NULL)
		s1 = "";
	s1s = ft_strlen(s1);
	s2s = ft_strlen(s2);
	join = malloc(s1s + s2s + 1);
	if (join)
	{
		ft_strlcpy(join, s1, s1s + 1);
		ft_strlcpy(join + s1s, s2, s2s + 1);
        join[s1s + s2s] = '\0';
		return (join);
	}
	return (NULL);
}

// char	*ft_strdup(char *str)
// {
// 	size_t	s;
// 	char	*dup;

// 	s = ft_strlen(str) + 1;
// 	dup = (char *)malloc(s);
// 	if (!dup)
// 		return (NULL);
// 	ft_strlcpy(dup, str, s);
// 	return (dup);
// }

// char	*ft_substr(char const *s, unsigned int start, unsigned int end)
// {
// 	unsigned int	s_len;
// 	char			*sub;

// 	if (!s)
// 		return (NULL);
// 	s_len = ft_strlen(s);
// 	if (end > s_len - start)
// 		end = s_len - start - 1;
// 	sub = (char *)malloc(end + 2);
// 	if (!sub)
// 		return (NULL);
// 	ft_strlcpy(sub, s + start, end + 1);
// 	return (sub);
// }
