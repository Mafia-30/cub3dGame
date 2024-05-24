/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:17:19 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/06 14:14:18 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (lit[0] == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		if (big[i] == lit[0])
		{
			j = 0;
			while (big[i + j] == lit[j] && i + j < len)
			{
				j++;
				if (!lit[j])
					return ((char *)(big + i));
			}
			i++;
		}
		else
			i++;
	}
	return (NULL);
}
