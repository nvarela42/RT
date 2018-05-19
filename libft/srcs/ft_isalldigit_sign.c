/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalldigit_sign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 15:45:23 by agoomany          #+#    #+#             */
/*   Updated: 2018/04/08 21:37:53 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_compare(char *str)
{
	int			i;
	int			flag;

	i = 0;
	flag = 0;
	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] != '.')
				return (1);
			if (str[i] == '.' && flag == 1)
				return (1);
			if (str[i] == '.')
				flag = 1;
		}
		i++;
	}
	return (0);
}

int				ft_isalldigit_sign(char *str)
{
	if (str != NULL)
		return (ft_compare(str));
	else
		return (1);
	return (0);
}
