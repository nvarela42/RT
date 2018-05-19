/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontagn <vmontagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 15:24:41 by vmontagn          #+#    #+#             */
/*   Updated: 2018/05/14 12:17:46 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		bump_normal(t_thread *th)
{
	t_color		c;

	c = ft_get_pixel_texture(th, th->hit.material->normal);
	th->hit.normal = (t_vector){th->hit.normal.x + (2 * (c.r) - 1),
		th->hit.normal.y + (2 * (c.g) - 1),
		th->hit.normal.z - 2 * (c.b - 0.5)};
	(void)th;
}

void			ft_bump_mapping(t_thread *th)
{
	t_vector	pos;
	t_vector	tmp;
	float		bump;

	pos = th->hit.inter;
	bump = th->hit.material->bump;
	if (bump > 0)
	{
		tmp = (t_vector){
			ft_noise(th, (t_vector){0.1 * pos.x,
				0.1 * pos.y, 0.1 * pos.z}),
			ft_noise(th, (t_vector){0.1 * pos.y,
				0.1 * pos.z, 0.1 * pos.x}),
			ft_noise(th, (t_vector){0.1 * pos.z,
				0.1 * pos.x, 0.1 * pos.y})};
		th->hit.normal.x = (1.0 - bump) * th->hit.normal.x + bump * tmp.x;
		th->hit.normal.y = (1.0 - bump) * th->hit.normal.y + bump * tmp.y;
		th->hit.normal.z = (1.0 - bump) * th->hit.normal.z + bump * tmp.z;
	}
	if (th->hit.material->normal && th->hit.material->normal->data)
		bump_normal(th);
}
