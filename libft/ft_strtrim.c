/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:21:12 by quegonza          #+#    #+#             */
/*   Updated: 2019/09/03 17:21:30 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	int				start;
	int				end;

	i = 0;
	start = 0;
	end = 0;
	if (!s)
		return (NULL);
	while (s[i] && (ft_isspace(s[i])))
		i++;
	if (i == ft_strlen(s))
		return (ft_strdup("\0"));
	start = i;
	i = ft_strlen(s) - 1;
	while (ft_isspace(s[i]))
		i--;
	end = i;
	return (ft_strsub(s, start, end - start + 1));
}
