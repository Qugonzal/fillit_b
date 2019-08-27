/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrychkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 22:56:48 by mrychkov          #+#    #+#             */
/*   Updated: 2017/05/08 17:30:53 by mrychkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] < 'a' && str[i] <= 'Z' && str[i] >= 'A')
			str[i] = str[i] - 'A' + 'a';
		i++;
	}
	if (str[0] >= 'a' && str[j] <= 'z')
		str[0] = str[0] - 'a' + 'A';
	while (str[j])
	{
		if (str[j] >= 'a' && str[j] <= 'z' && str[j - 1] <= '/')
			str[j] = str[j] - 'a' + 'A';
		j++;
	}
	return (str);
}
