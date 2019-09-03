/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:21:12 by quegonza          #+#    #+#             */
/*   Updated: 2019/09/03 17:21:30 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	int		n;
	int		a;

	i = 0;
	n = 1;
	a = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		n = (str[i] == 45 ? -1 : 1);
		i++;
	}
	while (ft_isdigit(str[i]))
		a = a * 10 + str[i++] - 48;
	return (a * n);
}
