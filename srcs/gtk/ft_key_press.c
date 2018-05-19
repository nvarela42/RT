/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 16:03:25 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 21:09:42 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	ft_key_press_2(t_scene *scn, GdkEventKey *event)
{
	if (event->keyval == 65361)
	{
		scn->sel_obj->pos.x -= DEFAULTMOUV;
		scn->scene->recalc = 1;
		ft_calc_scene((gpointer)scn);
	}
	else if (event->keyval == 65362)
	{
		scn->sel_obj->pos.y += DEFAULTMOUV;
		scn->scene->recalc = 1;
		ft_calc_scene((gpointer)scn);
	}
	else if (event->keyval == 65363)
	{
		scn->sel_obj->pos.x += DEFAULTMOUV;
		scn->scene->recalc = 1;
		ft_calc_scene((gpointer)scn);
	}
	else if (event->keyval == 65364)
	{
		scn->sel_obj->pos.y -= DEFAULTMOUV;
		scn->scene->recalc = 1;
		ft_calc_scene((gpointer)scn);
	}
}

gboolean	ft_key_press(GtkWidget *ev_box, GdkEventKey *event, gpointer data)
{
	t_scene	*scn;

	scn = (t_scene*)data;
	(void)ev_box;
	if (scn->sel_obj == NULL)
		return (FALSE);
	if (scn->anaglyph)
		return (FALSE);
	if (scn->sel_obj->type == 5)
		return (FALSE);
	ft_key_press_2(scn, event);
	if (event->keyval == 122)
	{
		scn->sel_obj->pos.z += DEFAULTMOUV;
		scn->scene->recalc = 1;
		ft_calc_scene((gpointer)scn);
	}
	else if (event->keyval == 120)
	{
		scn->sel_obj->pos.z -= DEFAULTMOUV;
		scn->scene->recalc = 1;
		ft_calc_scene((gpointer)scn);
	}
	gtk_image_set_from_pixbuf(GTK_IMAGE(scn->scene->view), scn->scene->pixbuf);
	return (FALSE);
}
