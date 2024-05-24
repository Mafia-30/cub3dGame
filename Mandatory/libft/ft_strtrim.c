/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:46:59 by ymahni            #+#    #+#             */
/*   Updated: 2024/05/09 14:52:16 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	ft_contains(const char *str, char c)
{
	while (*str)
	{
		if (*str == (unsigned char)c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	if (end == -1)
		return (ft_strdup(s1));
	while (ft_contains(set, s1[start]) && s1[start])
		start++;
	while (ft_contains(set, s1[end]) && start < end)
		end--;
	str = malloc(end - start + 2);
	if (str)
	{
		ft_memmove(str, s1 + start, end - start + 1);
		str[end - start + 1] = '\0';
	}
	return (str);
}
