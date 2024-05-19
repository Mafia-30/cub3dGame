/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:23:30 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/01 07:41:41 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*destination, const void	*source, size_t	size)
{
	size_t	i;

	if (!destination && !source)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((unsigned char *)destination)[i] = ((unsigned char *)source)[i];
		i++;
	}
	return (destination);
}
