/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 11:08:48 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 01:44:40 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			put_pixel(t_scene *scn, int x, int y, t_color color)
{
	guchar		*p;

	p = scn->scene->pixels + y * scn->scene->rowstride + x *
	scn->scene->n_channels;
	p[0] = color.r * 255;
	p[1] = color.g * 255;
	p[2] = color.b * 255;
	p[3] = 255;
}

void			ft_create_thread(t_scene *scn)
{
	int			i;

	i = 0;
	while (i < MAXTHREAD)
	{
		scn->thread[i].scn = scn;
		scn->thread[i].y1 = i;
		i++;
	}
}

static void		ft_debug_percent(int *old_percent, int percent)
{
	if (percent != *old_percent)
	{
		*old_percent = percent;
		ft_putstr_fd("\r", 1);
		ft_putnbr_fd(percent, 1);
		ft_putstr_fd("% ", 1);
		if (percent == 100)
			ft_putstr_fd("\n", 1);
	}
}

void			ft_calc_scene(gpointer data)
{
	t_scene		*scn;
	int			i;
	int			percent;

	scn = (t_scene*)data;
	ft_create_thread(scn);
	if (scn->scene->recalc == 1)
	{
		scn->scene->recalc = 0;
		i = 0;
		while (i < MAXTHREAD)
		{
			if (pthread_create(&scn->thread[i].id, NULL, ft_run_calc_scene,
				(void*)&scn->thread[i]) != 0)
				ft_perror(NULL, TRUE);
			i++;
		}
		i = 0;
		while (i < MAXTHREAD)
		{
			pthread_join(scn->thread[i].id, NULL);
			i++;
			ft_debug_percent(&percent, (int)((i / (float)MAXTHREAD) * 100));
		}
	}
}
