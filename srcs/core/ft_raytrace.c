/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytrace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 13:42:00 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/14 14:53:21 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				ft_raytrace(t_thread *th, int x, t_ray *ray, t_color *col)
{
	ray->dist = DEFAULT_DISTANCE;
	if (th->iter > 6)
		return ;
	ft_search_hit(th, ray);
	if (!th->hit.touch)
		return ;
	if (th->hit.is_light == 1)
	{
		col = &th->hit.material->material_color;
		return ;
	}
	ft_bump_mapping(th);
	ft_calc_lum(th, col);
	if (th->hit.material->refract >= 1 && th->hit.material->refract <= 2)
		ft_refr_and_refl(th, ray, col, x);
	else if (th->hit.material->reflect > 0 && th->hit.material->reflect <= 1)
		ft_reflect(th, ray, col, x);
}
