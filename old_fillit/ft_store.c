/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mk_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:20:40 by qugonzal          #+#    #+#             */
/*   Updated: 2017/05/29 19:35:47 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libfil.h"

void		save_tetri(t_tetri *tetri, char *s, int i)
{
	int		nb;
	int		x_first;
	int		y_first;

	nb = 0;
	x_first = i % 5;
	y_first = i / 5;
	while (nb < 3)
	{
		i++;
		if (s[i] == '#')
		{
			tetri->x[nb] = i % 5 - x_first;
			tetri->y[nb] = i / 5 - y_first;
			nb++;
		}
	}
}

void		find_1st_block(char *s, t_tetri *tetri)
{
	int i;

	i = 0;
	while (s[i] != '#' && s[i])
		i++;
	save_tetri(tetri, &s[0], i);
}

int			find_dimension(int *tab)
{
	int i;
	int dim;

	i = 0;
	dim = 0;
	if ((tab[0] == -1 && tab[2] == 1) || (tab[0] == 1 && tab[1] == -1))
		return (dim = 5);
	while (i != 3)
	{
		if (tab[i] < 0)
		{
			if (tab[i] < dim)
				dim = tab[i];
		}
		if (tab[i] > dim && dim >= 0)
			dim = tab[i];
		i++;
	}
	return (dim);
}

t_tetri		*ft_mk_tetri(char **tab, int elem_nbr)
{
	t_tetri		*elem;
	t_tetri		tetri;
	char		name;
	int			n;

	if (!(elem = malloc(sizeof(t_tetri) * elem_nbr + 1)))
		return (NULL);
	name = 'A';
	n = 0;
	while (n < elem_nbr)
	{
		tetri.name = name;
		find_1st_block(tab[n], &tetri);
		tetri.dim_x = find_dimension(tetri.x);
		tetri.dim_y = find_dimension(tetri.y);
		elem[n] = tetri;
		name++;
		n++;
	}
	elem[n].name = 0;
	return (elem);
}