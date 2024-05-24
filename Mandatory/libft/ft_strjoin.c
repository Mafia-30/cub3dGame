/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 00:35:39 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/03 09:45:58 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1s;
	size_t	s2s;
	char	*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
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
