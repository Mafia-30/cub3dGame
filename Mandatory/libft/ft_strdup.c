/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:42:47 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/02 23:02:27 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	s;
	char	*dup;

	s = ft_strlen(str) + 1;
	dup = (char *)malloc(s);
	if (dup)
		ft_strlcpy(dup, str, s);
	return (dup);
}
