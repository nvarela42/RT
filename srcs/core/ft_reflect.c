/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reflect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 14:37:33 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/07 11:37:36 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector		ft_refl_for_refract(t_thread *th, t_ray *ray)
{
	t_vector	ret;
	float		dot;

	dot = ft_vector_dot_mult(&th->hit.normal, &ray->dir);
	ret.x = ray->dir.x - 2 * dot * th->hit.normal.x;
	ret.y = ray->dir.y - 2 * dot * th->hit.normal.y;
	ret.z = ray->dir.z - 2 * dot * th->hit.normal.z;
	return (ret);
}

void			ft_reflect(t_thread *th, t_ray *ray, t_color *col, int x)
{
	t_ray		reflect_r;
	float		dot;
	float		reflect;

	reflect = th->hit.material->reflect;
	reflect_r.start_pos = th->hit.inter;
	dot = ft_vector_dot_mult(&th->hit.normal, &ray->dir);
	reflect_r.dir.x = ray->dir.x - 2 * dot * th->hit.normal.x;
	reflect_r.dir.y = ray->dir.y - 2 * dot * th->hit.normal.y;
	reflect_r.dir.z = ray->dir.z - 2 * dot * th->hit.normal.z;
	reflect_r.dist = DEFAULT_DISTANCE;
	ft_vector_normalize(&reflect_r.dir);
	th->iter++;
	ft_raytrace(th, x, &reflect_r, col);
	col->r = col->r * reflect > 1 ? 1 : col->r * reflect;
	col->g = col->g * reflect > 1 ? 1 : col->g * reflect;
	col->b = col->b * reflect > 1 ? 1 : col->b * reflect;
}
