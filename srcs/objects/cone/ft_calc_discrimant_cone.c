/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_discrimant_cone.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 23:21:23 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/02 10:26:28 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vector	ft_rotation_cone(t_objects *obj)
{
	t_vector	ret;

	ret.x = obj->rotation.z;
	ret.y = obj->rotation.y;
	ret.z = obj->rotation.x;
	return (ret);
}

static void		ft_cone_inters(t_tmp_obj *ctmp, float t, t_objects *obj)
{
	t_vector		tmp;
	t_vector		tmp2;
	t_vector		tmp3;

	tmp.x = ctmp->ray->start_pos.x + ctmp->ray->dir.x * t;
	tmp.y = ctmp->ray->start_pos.y + ctmp->ray->dir.y * t;
	tmp.z = ctmp->ray->start_pos.z + ctmp->ray->dir.z * t;
	ft_moins_vector(&tmp2, &tmp, &ctmp->obj->pos);
	ft_div_vector(&tmp3, &tmp2, ctmp->obj->radius);
	ctmp->hit->touch = 1;
	ctmp->hit->object = obj;
	ctmp->hit->normal = tmp3;
	ctmp->hit->inter = tmp;
	ctmp->hit->material = obj->material;
}

static int		ft_calc_cone_intersect(t_tmp_obj *ctmp, t_objects *obj)
{
	float			t1;
	float			t2;
	float			t;

	t1 = (-ctmp->b + sqrt(ctmp->delta)) / (2 * ctmp->a);
	t2 = (-ctmp->b - sqrt(ctmp->delta)) / (2 * ctmp->a);
	if (t1 < 0.01 || t2 < 0.01)
		return (0);
	else if (t1 < t2)
		t = t1;
	else
		t = t2;
	ft_cone_inters(ctmp, t, obj);
	return (1);
}

static float	ft_discri(t_ray *ray, t_tmp_obj *ctmp, t_objects *obj)
{
	t_vector	pos;
	t_vector	ray_dir;
	t_vector	rotation;
	float		rad;

	ray_dir = ray->dir;
	rotation = ft_rotation_cone(obj);
	ft_moins_vector(&pos, &ray->start_pos, &obj->pos);
	ft_rotation(&pos, rotation);
	ft_rotation(&ray_dir, rotation);
	rad = sin(ft_calc_angle(obj->radius)) * sin(ft_calc_angle(obj->radius));
	ctmp->a = ray_dir.x * ray_dir.x - ray_dir.y * ray_dir.y * rad +
	ray_dir.z * ray_dir.z;
	ctmp->b = 2 * (ray_dir.x * pos.x - ray_dir.y * pos.y * rad +
	ray_dir.z * pos.z);
	ctmp->c = pos.x * pos.x - pos.y * rad * pos.y + pos.z * pos.z;
	return (ctmp->b * ctmp->b - 4 * ctmp->a * ctmp->c);
}

int				ft_calc_discri_cone(t_objects *obj, t_ray *ray, t_hit *tmp)
{
	t_tmp_obj	ctmp;

	ctmp.delta = ft_discri(ray, &ctmp, obj);
	if (ctmp.delta < 0)
		return (0);
	else
	{
		ctmp.obj = obj;
		ctmp.ray = ray;
		ctmp.hit = tmp;
		return (ft_calc_cone_intersect(&ctmp, obj));
	}
}
