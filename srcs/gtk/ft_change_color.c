/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstroh <cstroh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 12:29:55 by cstroh            #+#    #+#             */
/*   Updated: 2018/05/13 18:41:33 by cstroh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				ft_change_color(gpointer data)
{
	t_scene			*scn;
	GtkWidget		*dialog;
	GdkRGBA			rgba;
	int				bowl;

	scn = (t_scene*)data;
	bowl = 0;
	if (scn->sel_obj == NULL)
		return ;
	dialog = gtk_color_chooser_dialog_new("", GTK_WINDOW(scn->scene->win));
	if ((gtk_dialog_run(GTK_DIALOG(dialog))) == GTK_RESPONSE_OK)
	{
		gtk_color_chooser_get_rgba(GTK_COLOR_CHOOSER(dialog), &rgba);
		bowl = 1;
		scn->sel_obj->material->material_color.r = rgba.red;
		scn->sel_obj->material->material_color.g = rgba.green;
		scn->sel_obj->material->material_color.b = rgba.blue;
	}
	gtk_widget_destroy(dialog);
	if (!bowl)
		return ;
	scn->scene->recalc = 1;
	ft_calc_scene((gpointer)scn);
	gtk_image_set_from_pixbuf(GTK_IMAGE(scn->scene->view), scn->scene->pixbuf);
}
