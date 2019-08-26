/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:00:02 by quegonza          #+#    #+#             */
/*   Updated: 2019/08/26 18:24:18 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

int		main(int ac, char **av)
{
	t_tetri		*tetri;
	t_map		map;
	int			i;

	if (ac != 2)
		ft_display_error(1);
	map.tab = ft_reader(av[1]);
	i = ft_block_count(map.tab);
	map.dim = ft_square(i);
	tetri = ft_mk_tetri(map.tab, i);
	map.tab = ft_map_creation(map.dim);
	while (ft_find_place(&map, tetri))
	{
		free(map.tab);
		map.tab = ft_map_creation(++map.dim);
	}
	while (ft_recursive(&map, tetri))
	{
		free(map.tab);
		map.tab = ft_map_creation(++map.dim);
		ft_find_place(&map, tetri);
	}
	ft_display_map(map.tab);
	return (0);
}
