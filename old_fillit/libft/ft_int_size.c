/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 16:43:26 by mrychkov          #+#    #+#             */
/*   Updated: 2017/05/08 19:42:24 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_int_size(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n < 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
