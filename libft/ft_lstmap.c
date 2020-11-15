/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:16:14 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/15 16:16:15 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_lst;
	t_list *tmp;

	new_lst = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f((*lst).content));
		if (tmp == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_front(&new_lst, tmp);
		lst = (*lst).next;
	}
	return (new_lst);
}
