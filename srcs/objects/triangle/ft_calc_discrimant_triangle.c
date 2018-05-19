/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_discrimant_triangle.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 23:13:54 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/15 14:08:40 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		ft_calc_inter_tri(t_tmp_obj *ttmp, t_objects *obj, float t)
{
	t_vector	tmp_inter;

	tmp_inter.x = ttmp->ray->start_pos.x + ttmp->ray->dir.x * t;
	tmp_inter.y = ttmp->ray->start_pos.y + ttmp->ray->dir.y * t;
	tmp_inter.z = ttmp->ray->start_pos.z + ttmp->ray->dir.z * t;
	ttmp->hit->touch = 1;
	ttmp->hit->object = obj;
	ttmp->hit->inter = tmp_inter;
	ttmp->hit->normal = ttmp->normal;
	ttmp->hit->material = obj->material;
	return (1);
}

static int		ft_discri(t_tmp_obj *ttmp, t_ray *ray, t_objects *obj)
{
	float		f;
	float		t;

	f = 1 / ttmp->dot_dir;
	ft_moins_vector(&ttmp->dir, &ray->start_pos, &obj->pos_edge1);
	ttmp->u = f * (ft_vector_dot_mult(&ttmp->dir, &ttmp->normal));
	if (ttmp->u < 0.0 || ttmp->u > 1.0)
		return (0);
	ft_mult_vector(&ttmp->cross, &ttmp->dir, &ttmp->ab);
	ttmp->v = f * (ft_vector_dot_mult(&ray->dir, &ttmp->cross));
	if (ttmp->v < 0.0 || ttmp->u + ttmp->v > 1.0)
		return (0);
	t = f * ft_vector_dot_mult(&ttmp->ac, &ttmp->cross);
	if (t > 0.0001)
		return (ft_calc_inter_tri(ttmp, obj, t));
	return (0);
}

int				ft_calc_discri_tri(t_objects *obj, t_ray *ray, t_hit *tmp)
{
	t_tmp_obj	ttmp;

	ft_moins_vector(&ttmp.ab, &obj->pos_edge2, &obj->pos_edge1);
	ft_moins_vector(&ttmp.ac, &obj->pos_edge3, &obj->pos_edge1);
	ft_mult_vector(&ttmp.normal, &ray->dir, &ttmp.ac);
	ttmp.dot_dir = ft_vector_dot_mult(&ttmp.ab, &ttmp.normal);
	if (ttmp.dot_dir > -0.1 && ttmp.dot_dir < 0.1)
		return (0);
	ttmp.obj = obj;
	ttmp.ray = ray;
	ttmp.hit = tmp;
	return (ft_discri(&ttmp, ray, obj));
}
