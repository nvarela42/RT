/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontagn <vmontagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 11:30:10 by vmontagn          #+#    #+#             */
/*   Updated: 2018/05/15 11:19:10 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_color		ft_get_pixel_color(t_texture *t, float u, float v)
{
	int				rowstride;
	guchar			*pixels;
	guchar			*p;
	int				x;
	int				y;

	rowstride = gdk_pixbuf_get_rowstride(t->data);
	pixels = gdk_pixbuf_get_pixels(t->data);
	x = (int)fmod(((u * (t->w - 1) * t->sw) + t->ow), t->w - 1);
	y = (int)fmod(((v * (t->h - 1) * t->sh) + t->oh), t->h - 1);
	p = pixels + y * rowstride + x * gdk_pixbuf_get_n_channels(t->data);
	return ((t_color){p[0] / 255.0, p[1] / 255.0, p[2] / 255.0});
}

static t_color		ft_get_pixel_plane(t_thread *th, t_texture *t)
{
	float			u;
	float			v;
	t_vector		normal;

	normal = (t_vector){(th->hit.inter.x - th->hit.object->pos.x),
		(th->hit.inter.y - th->hit.object->pos.y),
		(th->hit.inter.z - th->hit.object->pos.z)};
	if (fabs(th->hit.normal.x) == 1)
	{
		u = (normal.z * 100);
		v = (normal.y * 100);
	}
	else if (fabs(th->hit.normal.y) == 1)
	{
		u = (normal.x * 100);
		v = (normal.z * 100);
	}
	else
	{
		u = (normal.x * 100);
		v = (normal.y * 100);
	}
	u = fmod(t->w + fmod((t->w + u), t->w), t->w) / t->w;
	v = fmod(t->h + fmod((t->h / 2 - v), t->h), t->h) / t->h;
	return (ft_get_pixel_color(t, u, v));
}

t_color				ft_get_pixel_texture(t_thread *th, t_texture *t)
{
	float			u;
	float			v;
	t_vector		normal;

	if (th->hit.object->type == 2)
		return (ft_get_pixel_plane(th, t));
	normal = (t_vector){
				(th->hit.inter.x - th->hit.object->pos.x),
				(th->hit.inter.y - th->hit.object->pos.y),
				(th->hit.inter.z - th->hit.object->pos.z)
			};
	ft_vector_normalize(&normal);
	if (th->hit.object->type == 3)
		ft_rotation(&normal, ft_rotation_cylinder_init());
	ft_rotation(&normal, th->hit.object->rotation);
	u = (0.5 + atan2(normal.z, normal.x) / (2 * M_PI));
	v = (0.5 - asin(normal.y) / M_PI);
	return (ft_get_pixel_color(t, u, v));
}
