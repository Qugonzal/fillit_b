/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:05:40 by quegonza          #+#    #+#             */
/*   Updated: 2019/08/30 16:30:16 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_dots_fill(char **map, int dim)
{
	int j;
	int k;

	k = 0;
	while (k < dim)
	{
		j = 0;
		while (j < dim)
			map[k][j++] = '.';
		map[k++][j] = '\0';
	}
	map[k] = 0;
}

int				ft_square(int block_nb)
{
	int		map_size;
	int		dim;

	dim = 0;
	map_size = block_nb * 4;
	while (dim * dim < map_size)
		dim++;
	return (dim);
}

char			**ft_map_creation(int dim)
{
	char	**map;
	int		i;

	i = -1;
	if (!(map = (char **)ft_memalloc(sizeof(char*) * (dim + 1))))
		return (NULL);
	while (++i < dim)
		if (!(map[i] = (char*)ft_memalloc(sizeof(char) * (dim + 1))))
			return (NULL);
	ft_dots_fill(map, dim);
	return (map);
}

void			ft_display_map(char **tab, t_tetri **tetri)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	free(*tetri);
}
