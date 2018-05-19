/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_scene_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 11:08:48 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 15:31:12 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_color	ft_get_pos_color(t_thread *th, t_scene *scn, int x, int y)
{
	t_color		color;
	t_ray		ray;

	ray.start_pos = scn->camera->pos;
	ft_color_init(&color);
	ft_init_ray(scn, &ray, x, y);
	ft_raytrace(th, x, &ray, &color);
	ft_launch_effects(th, &color);
	return ((t_color){
		isnan(color.r) ? 0 : color.r,
		isnan(color.g) ? 0 : color.g,
		isnan(color.b) ? 0 : color.b
	});
}

static t_color	ft_calc_color_for_pixel(t_thread *th, t_scene *scn, int x)
{
	int			j;
	t_color		color;
	t_color		al_color;

	j = 0;
	ft_color_init(&al_color);
	while (j < 1 + (3 * th->has_aliasing))
	{
		th->iter = 0;
		color = ft_get_pos_color(th, scn, (x) + (j % 2), (th->y1) + (j / 2));
		al_color = (t_color){al_color.r + color.r, al_color.g + color.g,
			al_color.b + color.b};
		j++;
	}
	while (j < BLUR * scn->motionblur)
	{
		th->iter = 0;
		color = ft_get_pos_color(th, scn, x - (BLUR / 2) + j, th->y1);
		al_color = (t_color){al_color.r + color.r, al_color.g + color.g,
			al_color.b + color.b};
		j++;
	}
	return ((t_color){al_color.r / j, al_color.g / j, al_color.b / j});
}

static void		ft_run_scn_bis(t_thread *th, t_scene *scn)
{
	int			x;
	t_color		color;

	x = 0;
	th->has_aliasing = scn->antialiasing;
	while (x < 1280)
	{
		color = ft_calc_color_for_pixel(th, scn, x);
		put_pixel(th->scn, x, th->y1, color);
		x++;
	}
}

void			*ft_run_calc_scene(void *obj)
{
	t_thread	*th;
	t_scene		*scn;

	th = (t_thread *)obj;
	th->keep_hit = 0;
	th->debug = 0;
	if (th->y1 == 950)
		th->debug = 1;
	scn = th->scn;
	ft_run_scn_bis(th, scn);
	pthread_exit(NULL);
	return (NULL);
}
