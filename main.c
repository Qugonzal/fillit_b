/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:00:02 by quegonza          #+#    #+#             */
/*   Updated: 2019/09/02 17:42:22 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_next_place(t_map *map, t_tetri *tetri)
{
	int x;
	int y;
	int chk;

	y = map->y_last - 1;
	while (++y < map->dim)
	{
		x = map->x_last;
		map->x_last = -1;
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

int		ft_recursive(t_map *map, t_tetri *tetri)
{
	int xt;
	int yt;

	if (((xt = map->x_last) || !xt) && tetri[1].name == 0)
		return (0);
	if (((yt = map->y_last) || !yt) && ft_find_place(map, &tetri[1]) == 1)
	{
		ft_erase(map->x_last, map->y_last, map->tab, &tetri[0]);
		if (ft_find_next_place(map, &tetri[0]) == 1)
			return (1);
		yt = map->y_last;
		if (((xt = map->x_last) || !xt) && ft_find_place(map, &tetri[1]) == 1)
			return (ft_recursive(map, &tetri[0]));
	}
	if (ft_recursive(map, &tetri[1]) == 1)
	{
		ft_erase(xt, yt, map->tab, &tetri[0]);
		map->x_last = xt;
		map->y_last = yt;
		if (ft_find_next_place(map, tetri) == 1)
			return (1);
		return (ft_recursive(map, &tetri[0]));
	}
	return (0);
}

void	ft_display_error(int message)
{
	if (message == 1)
		ft_putendl("usage: input file");
	else if (message == 2)
		ft_putendl("error");
	exit(0);
}

void	ft_free(char **ptr, int dim)
{
	int i;

	i = -1;
	while (++i < dim)
		free(ptr[i]);
	free(ptr);
}

int		main(int ac, char **av)
{
	t_tetri		*tetri;
	t_map		map;

	if (ac != 2)
		ft_display_error(1);
	map = ft_input_read(av[1], &tetri);
	while (ft_find_place(&map, tetri))
	{
		ft_free(map.tab, map.dim);
		map.tab = ft_map_creation(++map.dim);
	}
	while (ft_recursive(&map, tetri))
	{
		ft_free(map.tab, map.dim);
		map.tab = ft_map_creation(++map.dim);
		ft_find_place(&map, tetri);
	}
	ft_display_map(map.tab, &tetri);
	return (0);
}
