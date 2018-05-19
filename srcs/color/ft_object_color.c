/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontagn <vmontagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 14:29:24 by vmontagn          #+#    #+#             */
/*   Updated: 2018/05/13 17:44:01 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_color		ft_damier(t_thread *th)
{
	int				tmp_x;
	int				tmp_y;
	int				tmp_z;
	t_color			color;

	tmp_x = DEFAULT_DISTANCE / 2 + th->hit.inter.x * 1.5;
	tmp_y = DEFAULT_DISTANCE / 2 + th->hit.inter.y * 1.5;
	tmp_z = DEFAULT_DISTANCE / 2 + th->hit.inter.z * 1.5;
	color = th->hit.material->material_color;
	if ((int)(tmp_x + tmp_y + tmp_z) % 2 == 0)
		return ((t_color){color.r / 2, color.g / 2, color.b / 2});
	return (color);
}

static t_color		ft_disco(t_thread *th)
{
	t_vector	tmp_iter;

	tmp_iter = th->hit.inter;
	return ((t_color){1 - fabs(2 * (tmp_iter.x - floor(tmp_iter.x)) - 1),
		1 - fabs(2 * (tmp_iter.y - floor(tmp_iter.y)) - 1),
		1 - fabs(2 * (tmp_iter.z - floor(tmp_iter.z)) - 1)});
}

static t_color		ft_wood(t_thread *th)
{
	t_vector	tmp_iter;
	t_color		def;
	t_color		tmp;
	float		f;

	def = th->hit.material->material_color;
	tmp_iter = th->hit.inter;
	tmp = (t_color){def.r / 2, def.g / 2, def.b / 2};
	f = 10 * ft_noise(th,
		(t_vector){tmp_iter.x, tmp_iter.y, tmp_iter.z});
	f = fabs(f - exp(f));
	f = (1 - cos(f * M_PI)) * 0.5;
	return ((t_color){def.r * (1 - f) + tmp.r * f,
		def.g * (1 - f) + tmp.g * f,
		def.b * (1 - f) + tmp.b * f});
}

static t_color		ft_marbre(t_thread *th)
{
	t_vector	tmp_iter;
	t_color		def;
	t_color		tmp;
	float		f;

	def = th->hit.material->material_color;
	tmp_iter = th->hit.inter;
	tmp = (t_color){def.r / 2, def.g / 2, def.b / 2};
	f = cos(tmp_iter.x + ft_noise(th,
		(t_vector){tmp_iter.x * 5, tmp_iter.y * 5, tmp_iter.z * 5}));
	return ((t_color){def.r * (1 - f) + tmp.r * f,
		def.g * (1 - f) + tmp.g * f,
		def.b * (1 - f) + tmp.b * f});
}

t_color				ft_get_object_color(t_thread *th)
{
	t_texture		*t;

	t = th->hit.material->texture;
	if (t == NULL)
		return (th->hit.material->material_color);
	if (t->data != NULL)
		return (ft_get_pixel_texture(th, t));
	if (t->type == 1)
		return (ft_damier(th));
	if (t->type == 2)
		return (ft_disco(th));
	if (t->type == 3)
		return (ft_marbre(th));
	if (t->type == 4)
		return (ft_wood(th));
	return (th->hit.material->material_color);
}
