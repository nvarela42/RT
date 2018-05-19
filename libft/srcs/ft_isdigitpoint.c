/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigitpoint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:42:48 by agoomany          #+#    #+#             */
/*   Updated: 2018/03/03 22:48:40 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_isdigitpoint(char *str)
{
	int			i;
	int			flag;

	i = 0;
	flag = 0;
	if (str != NULL)
	{
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
	}
	else
		return (1);
	return (0);
}
