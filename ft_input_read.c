/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:05:21 by quegonza          #+#    #+#             */
/*   Updated: 2019/09/05 16:49:19 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_adjustment_check(char *str)
{
	int		adj_count;
	int		index;

	adj_count = 0;
	index = -1;
	while (str[++index])
	{
		if (str[index] == '#')
		{
			if (index + 1 <= 20 && str[index + 1] == '#')
				adj_count++;
			if (index - 1 >= 0 && str[index - 1] == '#')
				adj_count++;
			if (((index + 5) <= 20) && str[index + 5] == '#')
				adj_count++;
			if (((index - 5) >= 0 && str[index - 5] == '#'))
				adj_count++;
		}
	}
	return (adj_count == 6 || adj_count == 8);
}

static int		ft_char_check(char *str)
{
	size_t	index;
	int		dot;
	int		hash;
	int		nl;

	index = -1;
	dot = 0;
	hash = 0;
	nl = 0;
	while (str[++index])
	{
		if (str[index] == '\n')
			nl++;
		else if (str[index] == '.')
			dot++;
		else if (str[index] == '#')
			hash++;
	}
	return (dot == 12 && hash == 4 && nl == 4);
}

void			ft_input_checker(char **tab)
{
	size_t	i;

	i = -1;
	while (tab[++i] != NULL)
		if (!(ft_char_check(tab[i])) || !(ft_adjustment_check(tab[i])))
			ft_display_error(2);
}

t_map			ft_input_read(char *file, t_tetri **tetri)
{
	int		fd;
	int		i;
	char	buffer[BUF + 1];
	char	**tab;
	t_map	map;

	fd = open(file, O_RDONLY);
	ft_bzero(buffer, sizeof(buffer));
	if (!(i = read(fd, buffer, BUF)) || i == -1 || i > BUF || (close(fd) == -1))
		ft_display_error(2);
	i = -1;
	while (buffer[++i])
		if (buffer[i] == '\n' && buffer[i + 1] == '\n' && buffer[i + 2])
			buffer[i + 1] = '!';
	if (!(tab = ft_strsplit(buffer, '!')))
		ft_display_error(2);
	ft_input_checker(tab);
	i = 0;
	while (tab[i])
		i++;
	map.dim = ft_square(i);
	*tetri = ft_mk_tetri(tab, i);
	ft_free(tab, i);
	map.tab = ft_map_creation(map.dim);
	return (map);
}
