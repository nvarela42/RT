/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_triangle_hit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:35:13 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/07 14:28:46 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_search_triangle_hit(t_thread *th, t_objects *obj, t_ray *ray)
{
	float			dist_tmp;
	t_hit			obj_tmp;
	t_vector		vect_tmp;

	if (obj->type == 5)
	{
		if (ft_calc_discri_tri(obj, ray, &obj_tmp))
		{
			ft_moins_vector(&vect_tmp, &obj_tmp.inter, &ray->start_pos);
			dist_tmp = ft_vector_square_len(&vect_tmp);
			if (dist_tmp < ray->dist)
			{
				if (!(th->hit.object == obj_tmp.object && th->keep_hit == 1))
				{
					ray->dist = dist_tmp;
					ft_copy_hit(th, obj_tmp);
				}
			}
		}
	}
}

void	ft_lum_hit_tri(t_thread *th, t_objects *obj, t_ray *ray, int *block)
{
	float			dist_tmp;
	t_hit			obj_tmp;
	t_vector		vect_tmp;

	while (obj)
	{
		if (obj != th->hit.object)
		{
			if (obj->type == 5)
			{
				ft_vector_init(&obj_tmp.inter);
				if (ft_calc_discri_tri(obj, ray, &obj_tmp))
				{
					ft_moins_vector(&vect_tmp, &obj_tmp.inter, &ray->start_pos);
					dist_tmp = ft_vector_magnitude(&vect_tmp);
					if (dist_tmp < ray->dist)
						*block = 1;
				}
			}
		}
		obj = obj->next;
	}
}
