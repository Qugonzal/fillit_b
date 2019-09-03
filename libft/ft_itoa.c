/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:21:13 by quegonza          #+#    #+#             */
/*   Updated: 2019/09/03 17:21:30 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	char	str[11];
	int		neg;

	i = 0;
	ft_bzero(str, 10);
	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	while (n / 10)
	{
		str[i++] = n % 10 + '0';
		n = n / 10;
	}
	str[i++] = n + '0';
	if (neg == 1)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strdup(ft_strrev(str)));
}
