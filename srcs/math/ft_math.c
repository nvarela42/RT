/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:38:59 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/07 13:34:47 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float		ft_max(float v1, float v2)
{
	if (v1 > v2)
		return (v1);
	return (v2);
}

float		ft_clamp(float min, float max, float value)
{
	if (value > max)
		return (max);
	if (value < min)
		return (min);
	return (value);
}

void		ft_swap(float *t1, float *t2)
{
	float	tmp;

	tmp = *t1;
	*t1 = *t2;
	*t2 = tmp;
}
