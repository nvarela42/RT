/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 19:40:19 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 20:57:41 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		ft_get_result(gpointer data)
{
	t_scene		*scn;

	scn = (t_scene*)data;
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(scn->radio1)) == TRUE)
		ft_sphere_add(scn);
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(scn->radio2)) == TRUE)
		ft_cone_add(scn);
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(scn->radio3)) == TRUE)
		ft_plane_add(scn);
	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(scn->radio4)) == TRUE)
		ft_cylinder_add(scn);
	scn->scene->recalc = 1;
	ft_calc_scene((gpointer)scn);
	gtk_widget_destroy(scn->scene->window_add);
}

static void		ft_radio_everywhere(t_scene *scn, GtkWidget *box)
{
	GSList		*grouprb;

	scn->radio1 = gtk_radio_button_new_with_label(NULL, "Sphere");
	scn->radio2 = gtk_radio_button_new_with_label(NULL, "Cone");
	gtk_radio_button_join_group((GtkRadioButton*)scn->radio1,
		(GtkRadioButton*)scn->radio2);
	grouprb = gtk_radio_button_get_group((GtkRadioButton*)scn->radio1);
	gtk_box_pack_start(GTK_BOX(box), scn->radio1, TRUE, TRUE, 5);
	gtk_box_pack_start(GTK_BOX(box), scn->radio2, TRUE, TRUE, 5);
	scn->radio3 = gtk_radio_button_new_with_label(grouprb, "Plane");
	gtk_box_pack_start(GTK_BOX(box), scn->radio3, TRUE, TRUE, 5);
	grouprb = gtk_radio_button_get_group((GtkRadioButton*)scn->radio1);
	scn->radio4 = gtk_radio_button_new_with_label(grouprb, "Cylinder");
	gtk_box_pack_start(GTK_BOX(box), scn->radio4, TRUE, TRUE, 5);
}

static void		ft_add_bis(t_scene *scn, GtkWidget *ok_button, GtkWidget *box)
{
	gtk_container_add(GTK_CONTAINER(box), ok_button);
	gtk_container_add(GTK_CONTAINER(scn->scene->window_add), box);
	gtk_widget_show_all(scn->scene->window_add);
}

void			ft_add_obj(gpointer data)
{
	t_scene		*scn;
	GtkWidget	*box;
	GtkWidget	*ok_button;
	GtkWidget	*titlebar;

	scn = (t_scene*)data;
	scn->scene->window_add = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_resizable(GTK_WINDOW(scn->scene->window_add), FALSE);
	gtk_window_set_position(GTK_WINDOW(scn->scene->window_add),
	GTK_WIN_POS_CENTER_ALWAYS);
	titlebar = gtk_header_bar_new();
	gtk_header_bar_set_title((GtkHeaderBar*)titlebar, "ADD OBJECT");
	gtk_window_set_titlebar(GTK_WINDOW(scn->scene->window_add), titlebar);
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
	ok_button = gtk_button_new_with_label("Add object");
	gtk_box_set_homogeneous(GTK_BOX(box), TRUE);
	ft_radio_everywhere(scn, box);
	g_signal_connect_swapped(ok_button, "clicked", G_CALLBACK(ft_get_result),
	scn);
	gtk_container_add(GTK_CONTAINER(box), ok_button);
	ok_button = gtk_button_new_with_label("Close");
	g_signal_connect_swapped(ok_button, "clicked",
	G_CALLBACK(gtk_widget_destroy),
	scn->scene->window_add);
	ft_add_bis(scn, ok_button, box);
}
