/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 08:35:54 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/02 18:50:51 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*des, const void	*src, size_t len)
{
	char		*d;
	const char	*s;

	d = des;
	s = src;
	if (d == s)
		return (des);
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
		return (des);
	}
	else
		return (ft_memcpy(des, src, len));
}
