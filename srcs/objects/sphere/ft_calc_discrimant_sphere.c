/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_discrimant_sphere.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 23:02:19 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/02 11:23:05 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vector	ft_rotation_sphere(t_objects *obj)
{
	t_vector	ret;

	ret.x = obj->rotation.x;
	ret.y = obj->rotation.y;
	ret.z = obj->rotation.z;
	return (ret);
}

static void		ft_sphere_inter(t_tmp_obj *stmp, float t, t_objects *obj)
{
	t_vector		tmp;
	t_vector		tmp2;
	t_vector		tmp3;

	tmp.x = stmp->ray->start_pos.x + stmp->ray->dir.x * t;
	tmp.y = stmp->ray->start_pos.y + stmp->ray->dir.y * t;
	tmp.z = stmp->ray->start_pos.z + stmp->ray->dir.z * t;
	ft_moins_vector(&tmp2, &tmp, &stmp->obj->pos);
	ft_div_vector(&tmp3, &tmp2, stmp->obj->radius);
	stmp->hit->touch = 1;
	stmp->hit->object = obj;
	stmp->hit->normal = tmp3;
	stmp->hit->inter = tmp;
	stmp->hit->material = obj->material;
}

static int		ft_calc_sphere_inter(t_tmp_obj *stmp, t_objects *obj)
{
	float			t1;
	float			t2;
	float			t;

	t1 = (-stmp->b + sqrt(stmp->delta)) / (2 * stmp->a);
	t2 = (-stmp->b - sqrt(stmp->delta)) / (2 * stmp->a);
	if (t1 < 0.1 || t2 < 0.1)
		return (0);
	else if (t1 < t2)
		t = t1;
	else
		t = t2;
	ft_sphere_inter(stmp, t, obj);
	return (1);
}

static float	ft_discri(t_ray *ray, t_tmp_obj *stmp, t_objects *obj)
{
	t_vector		pos;
	t_vector		ray_dir;
	t_vector		rotation;

	ray_dir = ray->dir;
	rotation = ft_rotation_sphere(obj);
	ft_moins_vector(&pos, &ray->start_pos, &obj->pos);
	ft_rotation(&pos, rotation);
	ft_rotation(&ray_dir, rotation);
	stmp->a = ray_dir.x * ray_dir.x + ray_dir.y *
	ray_dir.y + ray_dir.z * ray_dir.z;
	stmp->b = 2 * (ray_dir.x * pos.x + ray_dir.y * pos.y
	+ ray_dir.z * pos.z);
	stmp->c = pos.x * pos.x + pos.y * pos.y + pos.z
	* pos.z - (obj->radius * obj->radius);
	return (stmp->b * stmp->b - 4 * stmp->a * stmp->c);
}

int				ft_calc_discri_sphere(t_objects *obj, t_ray *ray, t_hit *tmp)
{
	t_tmp_obj	stmp;

	stmp.delta = ft_discri(ray, &stmp, obj);
	if (stmp.delta < 0)
		return (0);
	else
	{
		stmp.obj = obj;
		stmp.ray = ray;
		stmp.hit = tmp;
		return (ft_calc_sphere_inter(&stmp, obj));
	}
}
