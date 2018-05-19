/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:08:52 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/11 11:19:32 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_shiness(t_thread *th, t_lights *light, t_color *col, float dot)
{
	col->r += light->light_color.r * 0.4 * ((dot -
	th->hit.material->shiness) / (1 - th->hit.material->shiness));
	col->g += light->light_color.g * 0.4 * ((dot -
	th->hit.material->shiness) / (1 - th->hit.material->shiness));
	col->b += light->light_color.b * 0.4 * ((dot -
	th->hit.material->shiness) / (1 - th->hit.material->shiness));
}

void	ft_diffuse_light(t_thread *th, t_lights *light, t_color *col, float dot)
{
	t_color	mat_color;

	mat_color = ft_get_object_color(th);
	col->r += light->light_color.r * (dot + light->intensity) * mat_color.r;
	col->g += light->light_color.g * (dot + light->intensity) * mat_color.g;
	col->b += light->light_color.b * (dot + light->intensity) * mat_color.b;
}

void	ft_ambiante_light(t_thread *th, t_color *col)
{
	t_color	mat_color;

	mat_color = ft_get_object_color(th);
	col->r += mat_color.r * th->scn->ambiant->color.r * 0.4;
	col->g += mat_color.g * th->scn->ambiant->color.g * 0.4;
	col->b += mat_color.b * th->scn->ambiant->color.b * 0.4;
	col->r = col->r > 1 ? 1 : col->r;
	col->g = col->g > 1 ? 1 : col->g;
	col->b = col->b > 1 ? 1 : col->b;
}
