/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:21:13 by quegonza          #+#    #+#             */
/*   Updated: 2019/09/03 17:21:30 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*list;
	t_list	*start;

	list = NULL;
	while (lst)
	{
		temp = (*f)(lst);
		if (!list)
		{
			if (!(list = ft_lstnew(temp->content, temp->content_size)))
				return (NULL);
			start = list;
		}
		else
		{
			if (!(list->next = ft_lstnew(temp->content, temp->content_size)))
				return (NULL);
			list = list->next;
		}
		lst = lst->next;
	}
	return (start);
}
