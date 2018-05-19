/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:03:05 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/15 03:38:27 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	ft_calc_refr(t_thread *th, t_refract *refr, t_vector *n)
{
	if (refr->r_cos < 0)
		refr->r_cos = -refr->r_cos;
	else
	{
		ft_swap(&refr->r_eta, &refr->t_eta);
		n->x = -th->hit.normal.x;
		n->y = -th->hit.normal.y;
		n->z = -th->hit.normal.z;
	}
	refr->eta = refr->r_eta / refr->t_eta;
}

t_vector	ft_refract(t_thread *th, t_ray *ray, t_refract *refr)
{
	t_vector	n;
	t_vector	ret;
	float		verif;

	refr->r_cos = ft_clamp(-1, 1, ft_vector_dot_mult(&ray->dir,
		&th->hit.normal));
	refr->r_eta = 1;
	refr->t_eta = th->hit.material->refract;
	n = th->hit.normal;
	ft_calc_refr(th, refr, &n);
	verif = 1 - refr->eta * refr->eta * (1 - refr->r_cos * refr->r_cos);
	if (verif < 0)
		return ((t_vector){0, 0, 0});
	else
	{
		ret.x = refr->eta * ray->dir.x + (refr->eta * refr->r_cos -
		sqrtf(verif)) * n.x;
		ret.y = refr->eta * ray->dir.y + (refr->eta * refr->r_cos -
		sqrtf(verif)) * n.y;
		ret.z = refr->eta * ray->dir.z + (refr->eta * refr->r_cos -
		sqrtf(verif)) * n.z;
	}
	return (ret);
}

void		ft_fresnel(t_thread *th, t_ray *ray, t_refract *refr)
{
	float	ret_s;
	float	ret_p;

	refr->r_cos = ft_clamp(-1, 1, ft_vector_dot_mult(&ray->dir,
		&th->hit.normal));
	refr->r_eta = 1;
	refr->t_eta = th->hit.material->refract;
	if (refr->r_cos > 0)
		ft_swap(&refr->r_eta, &refr->t_eta);
	refr->t_sin = refr->r_eta / refr->t_eta * sqrtf(ft_max(0, 1 -
		refr->r_cos * refr->r_cos));
	if (refr->t_sin >= 1)
		refr->ret = 1;
	else
	{
		refr->t_cos = sqrtf(ft_max(0, 1 - refr->t_sin * refr->t_sin));
		refr->r_cos = fabsf(refr->r_cos);
		ret_s = ((refr->t_eta * refr->r_cos) - (refr->r_eta * refr->t_cos)) /
		((refr->t_eta * refr->r_cos) + (refr->r_eta * refr->t_cos));
		ret_p = ((refr->r_eta * refr->r_cos) - (refr->t_eta * refr->t_cos)) /
		((refr->r_eta * refr->r_cos) + (refr->t_eta * refr->t_cos));
		refr->ret = (ret_s * ret_s + ret_p * ret_p) / 2;
	}
}

static void	ft_run_refr(t_thread *th, t_refract *refr, t_ray *ray, int x)
{
	t_ray	tmp_ray;
	int		tmp_iter;

	tmp_iter = th->iter;
	refr->ray_refr = &tmp_ray;
	th->iter = tmp_iter + 1;
	refr->ray_refr->dir = ft_refract(th, ray, refr);
	refr->ray_refr->start_pos = th->hit.inter;
	th->keep_hit = 1;
	ft_raytrace(th, x, refr->ray_refr, &refr->color);
}

void		ft_refr_and_refl(t_thread *th, t_ray *ray, t_color *col, int x)
{
	t_refract	refr;
	t_hit		reflect;

	refr.color = (t_color){col->r, col->g, col->b};
	reflect = th->hit;
	ft_fresnel(th, ray, &refr);
	refr.out = (ft_vector_dot_mult(&ray->dir, &th->hit.normal) < 0);
	refr.bias = 0;
	if (refr.ret < 1)
		ft_run_refr(th, &refr, ray, x);
	th->hit = reflect;
	if (th->hit.material->reflect > 0)
		ft_reflect(th, ray, col, x);
	col->r = refr.ret + refr.color.r * (1 - refr.ret);
	col->g = refr.ret + refr.color.g * (1 - refr.ret);
	col->b = refr.ret + refr.color.b * (1 - refr.ret);
	col->r = col->r > 1 ? 1 : col->r;
	col->g = col->g > 1 ? 1 : col->g;
	col->b = col->b > 1 ? 1 : col->b;
}
