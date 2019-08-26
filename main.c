/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:00:02 by quegonza          #+#    #+#             */
/*   Updated: 2019/08/26 19:26:05 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

char	**ft_reader(char *buf)
{
	int			fd;
	int			i;
	char		buffer[547];
	char		*buffer_copy;

	fd = open(file, O_RDONLY);
	ft_bzero(buffer, sizeof(buffer));
	if (!(i = read(fd, buffer, 546)) || i == -1 || i > 546 || (close(fd) == -1))
		ft_display_error(2);
	
}

void	ft_display_error(int message)
{
	if (message == 1)
		ft_putendl("usage: input file");
	else if (message == 2)
		ft_putendl("error");
	exit(0);
}

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
