/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:21:11 by quegonza          #+#    #+#             */
/*   Updated: 2019/09/03 17:21:30 by quegonza         ###   ########.fr       */
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
