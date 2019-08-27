/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 17:34:42 by mrychkov          #+#    #+#             */
/*   Updated: 2017/05/08 19:25:36 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bubblesort(int *tab, int n)
{
	int a;
	int temp;
	int flag;

	a = 0;
	temp = 0;
	flag = 0;
	while (flag == 0)
	{
		flag = 1;
		while (a < (n - 1))
		{
			if (tab[a] > tab[a + 1])
			{
				temp = tab[a];
				tab[a] = tab[a + 1];
				tab[a + 1] = temp;
				flag = 0;
			}
			a++;
		}
		a = 0;
	}
}
