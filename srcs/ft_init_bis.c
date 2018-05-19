/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 11:47:13 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/15 16:59:24 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			ft_init_create(t_rt *rt)
{
	rt->object_create[0] = &ft_create_camera;
	rt->object_create[1] = &ft_create_object;
	rt->object_create[2] = &ft_create_object;
	rt->object_create[3] = &ft_create_object;
	rt->object_create[4] = &ft_create_object;
	rt->object_create[5] = &ft_create_object;
	rt->object_create[6] = &ft_create_object;
	rt->object_create[7] = &ft_create_materia;
	rt->object_create[8] = &ft_create_light;
	rt->object_create[9] = &ft_create_ambiant;
	rt->object_create[10] = &ft_create_texture;
}

void			ft_fill_object(t_rt *rt)
{
	rt->object_init[0] = &ft_init_camera;
	rt->object_init[1] = &ft_init_sphere;
	rt->object_init[2] = &ft_init_plane;
	rt->object_init[3] = &ft_init_cylinder;
	rt->object_init[4] = &ft_init_cone;
	rt->object_init[5] = &ft_init_triangle;
	rt->object_init[6] = &ft_init_cube;
	rt->object_init[7] = &ft_init_materia;
	rt->object_init[8] = &ft_init_light;
	rt->object_init[9] = &ft_init_ambiant;
	rt->object_init[10] = &ft_init_texture;
	rt->object_calc[0] = &ft_no_hit;
	rt->object_calc[1] = &ft_search_sphere_hit;
	rt->object_calc[2] = &ft_search_plane_hit;
	rt->object_calc[3] = &ft_search_cylinder_hit;
	rt->object_calc[4] = &ft_search_cone_hit;
	rt->object_calc[5] = &ft_search_triangle_hit;
	rt->object_calc[6] = &ft_no_hit;
	rt->object_calc[7] = &ft_no_hit;
	rt->object_calc[8] = &ft_no_hit;
	rt->object_calc[9] = &ft_no_hit;
	rt->object_calc[10] = &ft_no_hit;
}

void			ft_init_calc_lum(t_rt *rt)
{
	rt->object_calc_lum[0] = &ft_no_hit_lum;
	rt->object_calc_lum[1] = &ft_lum_hit_sphere;
	rt->object_calc_lum[2] = &ft_lum_hit_plane;
	rt->object_calc_lum[3] = &ft_lum_hit_cyl;
	rt->object_calc_lum[4] = &ft_lum_hit_cone;
	rt->object_calc_lum[5] = &ft_lum_hit_tri;
	rt->object_calc_lum[6] = &ft_no_hit_lum;
	rt->object_calc_lum[7] = &ft_no_hit_lum;
	rt->object_calc_lum[8] = &ft_no_hit_lum;
	rt->object_calc_lum[9] = &ft_no_hit_lum;
	rt->object_calc_lum[10] = &ft_no_hit_lum;
}
