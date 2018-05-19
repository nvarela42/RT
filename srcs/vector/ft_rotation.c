/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 14:30:05 by agoomany          #+#    #+#             */
/*   Updated: 2018/04/28 14:30:11 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float			ft_calc_angle(float rot)
{
	return (rot * 3.14159265359 / 180);
}

void			ft_rotation(t_vector *vec, t_vector rot)
{
	t_vector	angle;
	float		tmp;

	angle.x = ft_calc_angle(rot.x);
	angle.y = ft_calc_angle(rot.y);
	angle.z = ft_calc_angle(rot.z);
	if (rot.x)
	{
		tmp = ((vec->y * cos(angle.x)) - (vec->z * sin(angle.x)));
		vec->z = ((vec->y * sin(angle.x)) + (vec->z * cos(angle.x)));
		vec->y = tmp;
	}
	if (rot.y)
	{
		tmp = ((vec->x * cos(angle.y)) + (vec->z * sin(angle.y)));
		vec->z = ((vec->z * cos(angle.y)) - (vec->x * sin(angle.y)));
		vec->x = tmp;
	}
	if (rot.z)
	{
		tmp = ((vec->x * cos(angle.z)) - (vec->y * sin(angle.z)));
		vec->y = ((vec->x * sin(angle.z)) + (vec->y * cos(angle.z)));
		vec->x = tmp;
	}
}

t_vector		ft_rotation_cylinder_init(void)
{
	t_vector	ret;

	ret.x = 90;
	ret.y = 0;
	ret.z = 0;
	return (ret);
}
