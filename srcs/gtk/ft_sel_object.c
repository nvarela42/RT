/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sel_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:53:35 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 19:52:33 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

gboolean	ft_sel_object(GtkWidget *ev_box, GdkEventButton *ev, gpointer data)
{
	t_scene		*scn;
	t_thread	th;
	t_ray		ray;

	(void)ev_box;
	scn = (t_scene*)data;
	th.scn = scn;
	th.hit.touch = 0;
	th.keep_hit = 0;
	ray.start_pos = scn->camera->pos;
	ft_init_ray(scn, &ray, ev->x, ev->y);
	ft_search_hit(&th, &ray);
	if (th.hit.touch == 1)
		scn->sel_obj = th.hit.object;
	else
		scn->sel_obj = NULL;
	return (FALSE);
}
