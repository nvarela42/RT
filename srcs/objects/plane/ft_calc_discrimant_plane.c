/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_discrimant_plane.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 23:13:54 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/15 11:33:41 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		ft_plane_inters(t_tmp_obj *ptmp, float t, t_objects *obj)
{
	t_vector		tmp;

	tmp.x = ptmp->ray->start_pos.x + ptmp->ray->dir.x * t;
	tmp.y = ptmp->ray->start_pos.y + ptmp->ray->dir.y * t;
	tmp.z = ptmp->ray->start_pos.z + ptmp->ray->dir.z * t;
	ptmp->hit->touch = 1;
	ptmp->hit->object = obj;
	ptmp->hit->inter = tmp;
	if (ptmp->b > 0)
	{
		ptmp->hit->normal.x = -(obj->normal.x);
		ptmp->hit->normal.y = -(obj->normal.y);
		ptmp->hit->normal.z = -(obj->normal.z);
	}
	else
		ptmp->hit->normal = obj->normal;
	ptmp->hit->material = obj->material;
}

static int		ft_calc_plane_inter(t_tmp_obj *ptmp, t_objects *obj)
{
	float			t;

	t = ptmp->delta;
	ft_plane_inters(ptmp, t, obj);
	return (t);
}

int				ft_calc_discri_plane(t_objects *obj, t_ray *ray, t_hit *tmp)
{
	t_tmp_obj		ptmp;
	t_vector		pos;

	ptmp.b = ft_vector_dot_mult(&obj->normal, &ray->dir);
	if (ptmp.b == 0)
		return (0);
	ft_moins_vector(&pos, &ray->start_pos, &obj->pos);
	ptmp.a = ft_vector_dot_mult(&obj->normal, &pos);
	ptmp.delta = -ptmp.a / ptmp.b;
	if (ptmp.delta < 0.0001)
		return (0);
	else
	{
		ptmp.obj = obj;
		ptmp.ray = ray;
		ptmp.hit = tmp;
		ft_calc_plane_inter(&ptmp, obj);
		ft_moins_vector(&pos, &obj->pos, &ptmp.hit->inter);
		if (obj->radius > 0 && ft_vector_magnitude(&pos) > obj->radius)
			return (0);
		return (1);
	}
}
