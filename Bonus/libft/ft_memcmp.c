/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:10:00 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/02 22:15:31 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*mys1;
	const unsigned char	*mys2;
	size_t				i;

	mys1 = (const unsigned char *)s1;
	mys2 = (const unsigned char *)s2;
	i = 0;
	if (!mys1 && !mys2)
		return (0);
	while (i < n)
	{
		if (mys1[i] != mys2[i])
			return (mys1[i] - mys2[i]);
		i++;
	}
	return (0);
}
