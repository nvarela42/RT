/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_plane_hit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:35:13 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/08 15:22:24 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_search_plane_hit(t_thread *th, t_objects *obj, t_ray *ray)
{
	float			dist_tmp;
	t_hit			obj_tmp;
	t_vector		vec_tmp;

	if (obj->type == 2)
	{
		if (ft_calc_discri_plane(obj, ray, &obj_tmp))
		{
			ft_moins_vector(&vec_tmp, &obj_tmp.inter, &ray->start_pos);
			dist_tmp = ft_vector_square_len(&vec_tmp);
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

void	ft_lum_hit_plane(t_thread *th, t_objects *obj, t_ray *ray, int *block)
{
	float			dist_tmp;
	t_hit			obj_tmp;
	t_vector		vec_tmp;

	if (obj != th->hit.object)
	{
		if (obj->type == 2)
		{
			if (ft_calc_discri_plane(obj, ray, &obj_tmp))
			{
				ft_moins_vector(&vec_tmp, &obj_tmp.inter, &ray->start_pos);
				dist_tmp = ft_vector_magnitude(&vec_tmp);
				if (dist_tmp < ray->dist)
					*block = 1;
			}
		}
	}
}
