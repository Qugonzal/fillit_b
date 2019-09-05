/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 17:00:34 by quegonza          #+#    #+#             */
/*   Updated: 2019/09/05 17:16:48 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_erase(int x, int y, char **tab, t_tetri *tetri)
{
	tab[y][x] = '.';
	tab[y + tetri->y[0]][x + tetri->x[0]] = '.';
	tab[y + tetri->y[1]][x + tetri->x[1]] = '.';
	tab[y + tetri->y[2]][x + tetri->x[2]] = '.';
}

int		ft_special_dim(int x, int y, t_map *map, t_tetri *tetri)
{
	int i;

	i = 0;
	while (i != 3)
	{
		if (x + tetri->x[i] >= map->dim)
			return (1);
		if (x + tetri->x[i] < 0)
			return (3);
		i++;
	}
	if (	map->tab[y + tetri->y[0]][x + tetri->x[0]] != '.' ||
			map->tab[y + tetri->y[1]][x + tetri->x[1]] != '.' ||
			map->tab[y + tetri->y[2]][x + tetri->x[2]] != '.')
		return (3);
	return (0);
}

int		ft_check_fill(int x, int y, t_map *map, t_tetri *tetri)
{
	if (y + tetri->dim_y >= map->dim)
		return (2);
	if (tetri->dim_x == 5)
		return (ft_special_dim(x, y, map, tetri));
	else if (x + tetri->dim_x >= map->dim)
		return (1);
	if (x + tetri->dim_x < 0 ||
			map->tab[y + tetri->y[0]][x + tetri->x[0]] != '.' ||
			map->tab[y + tetri->y[1]][x + tetri->x[1]] != '.' ||
			map->tab[y + tetri->y[2]][x + tetri->x[2]] != '.')
		return (3);
	return (0);
}

int		ft_place(int x, int y, t_map *map, t_tetri *tetri)
{
	int nb;

	nb = 0;
	map->x_last = x;
	map->y_last = y;
	map->tab[y][x] = tetri->name;
	while (nb < 3)
	{
		map->tab[y + (tetri->y)[nb]][x + (tetri->x)[nb]] = tetri->name;
		nb++;
	}
	return (0);
}

int		ft_find_place(t_map *map, t_tetri *tetri)
{
	int x;
	int y;
	int chk;

	y = -1;
	while (++y < map->dim)
	{
		x = -1;
		while (++x < map->dim)
		{
			if (map->tab[y][x] == '.')
			{
				chk = ft_check_fill(x, y, map, tetri);
				if (chk == 1)
					break ;
				if (chk == 2)
					return (1);
				if (!chk)
					return (ft_place(x, y, map, tetri));
			}
		}
	}
	return (1);
}
