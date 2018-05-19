/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:35:44 by agoomany          #+#    #+#             */
/*   Updated: 2018/02/21 13:35:07 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double			ft_atof_three(char *str, int i, double val)
{
	int					esign;
	double				exp;

	if (str[i] == 'e' || str[i] == 'E')
	{
		esign = (str[++i] == '-') ? -1 : 1;
		if (str[i] == '+' || str[i] == '-')
			i++;
		exp = 0.0;
		while (str[i] >= 48 && str[i] <= 57)
		{
			exp = 10.0 * exp + (str[i] - '0');
			i++;
		}
		val *= pow(10, esign * exp);
	}
	return (val);
}

static double			ft_atof_two(char *str, int i, double val, int sign)
{
	double				power;

	power = 1.0;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= 48 && str[i] <= 57)
		{
			val = 10.0 * val + (str[i] - '0');
			power *= 10.0;
			i++;
		}
	}
	val *= sign / power;
	return (ft_atof_three(str, i, val));
}

float					ft_atof(char *str)
{
	double				val;
	int					i;
	int					sign;

	i = 0;
	val = 0.0;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		val = 10.0 * val + (str[i] - '0');
		i++;
	}
	return (ft_atof_two(str, i, val, sign));
}
