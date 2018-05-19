/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perlin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontagn <vmontagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 16:05:32 by vmontagn          #+#    #+#             */
/*   Updated: 2018/05/01 16:51:17 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static float	fade(float t)
{
	return (t * t * t * (t * (t * 6 - 15) + 10));
}

static float	lerp(float t, float a, float b)
{
	return (a + t * (b - a));
}

static float	grad(int hash, float x, float y, float z)
{
	int			h;
	float		u;
	float		v;
	float		res;

	h = hash & 15;
	res = 0;
	if (h < 8)
		u = x;
	else
		u = y;
	if (h < 4)
		v = y;
	else
	{
		if (h == 12 || h == 14)
			v = x;
		else
			v = z;
	}
	res += ((h & 1) == 0 ? u : -u);
	res += ((h & 2) == 0 ? v : -v);
	return (res);
}

float			ft_noise(t_thread *th, t_vector pos)
{
	t_vector	floor_p;
	t_vector	fade_p;
	t_vector	a;
	t_vector	b;
	int			*p;

	p = th->scn->perlin_permutation;
	floor_p = (t_vector){(int)floor(pos.x) & 255,
		(int)floor(pos.y) & 255, (int)floor(pos.z) & 255};
	pos = (t_vector){pos.x - floor(pos.x), pos.y - floor(pos.y),
		pos.z - floor(pos.z)};
	fade_p = (t_vector){fade(pos.x), fade(pos.y), fade(pos.z)};
	a.x = p[(int)floor_p.x] + floor_p.y;
	a = (t_vector){a.x, p[(int)a.x] + floor_p.z, p[(int)a.x + 1] + floor_p.z};
	b.x = p[(int)floor_p.x + 1] + floor_p.y;
	b = (t_vector){b.x, p[(int)b.x] + floor_p.z, p[(int)b.x + 1] + floor_p.z};
	return (lerp(fade_p.z, lerp(fade_p.y,
		lerp(fade_p.x, grad(p[(int)a.y], pos.x, pos.y, pos.z),
		grad(p[(int)b.y], pos.x - 1, pos.y, pos.z)),
		lerp(fade_p.x, grad(p[(int)a.z], pos.x, pos.y - 1, pos.z),
		grad(p[(int)b.z], pos.x - 1, pos.y - 1, pos.z))), lerp(fade_p.y,
		lerp(fade_p.x, grad(p[(int)a.y + 1], pos.x, pos.y, pos.z - 1),
		grad(p[(int)b.y + 1], pos.x - 1, pos.y, pos.z - 1)),
		lerp(fade_p.x, grad(p[(int)a.z + 1], pos.x, pos.y - 1, pos.z - 1),
		grad(p[(int)b.z + 1], pos.x - 1, pos.y - 1, pos.z - 1)))));
}
