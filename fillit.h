/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 18:06:02 by quegonza          #+#    #+#             */
/*   Updated: 2019/08/26 18:24:18 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <sys/types.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_tetrimino
{
	int				name;
	int				x[3];
	int				y[3];
	int				dim_x;
	int				dim_y;
}					t_tetri;

typedef struct		s_map
{
	int				x_last;
	int				y_last;
	int				dim;
	int				nb_tetri;
	char			**tab;
}					t_map;

char				**ft_reader(char *file);
void				ft_display_error(int message);
void				ft_display_map(char **tab);
int					ft_square(int block_nb);
int					ft_place(int x, int y, t_map *map, t_tetri *tetri);
int					main(int ac, char **av);
void				ft_erase(int x, int y, char **tab, t_tetri *tetri);
int					ft_checker(char **tab);
char				**ft_map_creation(int dim);
t_tetri				*ft_mk_tetri(char **tab, int elem_nbr);
int					ft_block_count(char **tab);
int					ft_check_fill(int x, int y, t_map *map, t_tetri *tetri);
int					ft_find_place(t_map *map, t_tetri *tetri);
#endif