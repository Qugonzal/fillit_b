/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:21:13 by quegonza          #+#    #+#             */
/*   Updated: 2019/09/03 17:21:30 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;

	current = *alst;
	while (current)
	{
		(*del)(current->content, current->content_size);
		free(current);
		current = current->next;
	}
	*alst = NULL;
}
