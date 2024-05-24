/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymahni <ymahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:55:28 by ymahni            #+#    #+#             */
/*   Updated: 2023/11/06 14:56:36 by ymahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*help;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		help = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = help;
	}
}
