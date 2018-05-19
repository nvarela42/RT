/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_lum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:27:11 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/13 17:45:14 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	ft_init_ray_lum(t_thread *th, t_ray *ray, t_lights *light)
{
	t_vector		pix_dir;

	ft_moins_vector(&pix_dir, &th->hit.inter, &light->pos);
	ray->dir = pix_dir;
	ray->start_pos = light->pos;
	ray->dist = ft_vector_magnitude(&ray->dir);
}

static void	ft_final_color(t_thread *th, t_color *col, t_lights *light, float d)
{
	t_color				mat_color;

	mat_color = ft_get_object_color(th);
	if (light->spot == 1)
	{
		if (d > light->rad_spot && d <= 1)
			ft_diffuse_light(th, light, col, d);
	}
	else
		ft_diffuse_light(th, light, col, d);
	if (th->hit.material->shiness > 0 && th->hit.material->shiness <= 1)
	{
		if (d > th->hit.material->shiness && d <= 1)
			ft_shiness(th, light, col, d);
	}
	col->r = col->r > 1 ? 1 : col->r;
	col->g = col->g > 1 ? 1 : col->g;
	col->b = col->b > 1 ? 1 : col->b;
	col->r = col->r < 0 ? 0 : col->r;
	col->g = col->g < 0 ? 0 : col->g;
	col->b = col->b < 0 ? 0 : col->b;
}

static void	ft_calc_color(t_thread *th, t_color *col, t_lights *light)
{
	float				dot;
	t_vector			light_vect;

	ft_moins_vector(&light_vect, &light->pos, &th->hit.inter);
	ft_vector_normalize(&light_vect);
	ft_vector_normalize(&th->hit.normal);
	dot = ft_vector_dot_mult(&th->hit.normal, &light_vect);
	if (dot < 0.0001)
		return ;
	ft_final_color(th, col, light, dot);
}

void		ft_calc_lum(t_thread *th, t_color *col)
{
	t_ray				light_ray;
	int					blocked;
	t_lights			*light;
	t_objects			*cur;

	light = th->scn->lights;
	if (th->scn->ambiant)
		ft_ambiante_light(th, col);
	while (light)
	{
		blocked = 0;
		ft_init_ray_lum(th, &light_ray, light);
		cur = th->scn->objects;
		while (cur)
		{
			if (cur != th->hit.object)
			{
				(*ft_glob()->object_calc_lum[cur->type])(th, cur, &light_ray,
					&blocked);
			}
			cur = cur->next;
		}
		blocked == 0 ? ft_calc_color(th, col, light) : 0;
		light = light->next;
	}
}
