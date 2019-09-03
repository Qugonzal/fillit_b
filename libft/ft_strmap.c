/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:21:12 by quegonza          #+#    #+#             */
/*   Updated: 2019/09/03 17:21:30 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ptr;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (!(ptr = malloc(i + 1)))
		return (NULL);
	i = 0;
	while (f != NULL && s[i])
	{
		ptr[i] = f(s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
