/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_discrimant_cyl.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 23:08:07 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/09 15:26:03 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vector	ft_rotation_cylinder(t_objects *obj)
{
	t_vector	ret;

	ret.x = -obj->rotation.z;
	ret.y = -obj->rotation.x;
	ret.z = -obj->rotation.y;
	return (ret);
}

static void		ft_cyl_inters(t_tmp_obj *ctmp, float t, t_objects *obj)
{
	t_vector	tmp;
	t_vector	tmp2;
	t_vector	tmp3;

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

static int		ft_calc_cyl_intersect(t_tmp_obj *ctmp, t_objects *obj)
{
	float		t1;
	float		t2;
	float		t;
	t_vector	limit_rot;

	t1 = (-ctmp->b + sqrt(ctmp->delta)) / (2 * ctmp->a);
	t2 = (-ctmp->b - sqrt(ctmp->delta)) / (2 * ctmp->a);
	if (t1 < 0.1 || t2 < 0.1)
		return (0);
	else if (t1 < t2)
		t = t1;
	else
		t = t2;
	ft_cyl_inters(ctmp, t, obj);
	limit_rot = ctmp->hit->inter;
	ft_rotation(&limit_rot, ((t_vector){obj->rotation.z, obj->rotation.x,
	obj->rotation.y}));
	ft_rotation(&limit_rot, ((t_vector){-90, 0, 0}));
	if (obj->limit_pos > 0 || obj->limit_neg > 0)
	{
		if (limit_rot.z > obj->limit_pos || limit_rot.z < -obj->limit_neg)
			return (0);
	}
	return (1);
}

static float	ft_discri(t_ray *ray, t_tmp_obj *ctmp, t_objects *obj)
{
	t_vector		pos;
	t_vector		ray_dir;
	t_vector		rotation;

	ray_dir = ray->dir;
	ft_moins_vector(&pos, &ray->start_pos, &obj->pos);
	rotation = ft_rotation_cylinder_init();
	ft_rotation(&pos, rotation);
	ft_rotation(&ray_dir, rotation);
	rotation = ft_rotation_cylinder(obj);
	ft_rotation(&pos, rotation);
	ft_rotation(&ray_dir, rotation);
	ctmp->a = ray_dir.x * ray_dir.x + ray_dir.y * ray_dir.y;
	ctmp->b = 2 * (ray_dir.x * pos.x + ray_dir.y * pos.y);
	ctmp->c = (pos.x * pos.x + pos.y * pos.y) - obj->radius * obj->radius;
	return (ctmp->b * ctmp->b - 4 * ctmp->a * ctmp->c);
}

int				ft_calc_discri_cyl(t_objects *obj, t_ray *ray, t_hit *tmp)
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
		return (ft_calc_cyl_intersect(&ctmp, obj));
	}
}
