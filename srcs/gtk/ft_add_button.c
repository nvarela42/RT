/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_button.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 10:58:50 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 02:38:42 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				ft_add_button_5(t_scene *scn)
{
	GtkWidget		*button_img;
	GtkToolItem		*button;

	button_img = gtk_image_new_from_file(ft_glob()->bluico);
	button = gtk_tool_button_new(button_img, "Motion blur");
	gtk_widget_set_tooltip_text(GTK_WIDGET(button), "Motion blur effect");
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, -1);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",
			G_CALLBACK(ft_motion_blur), scn);
	button_img = gtk_image_new_from_file(ft_glob()->carico);
	button = gtk_tool_button_new(button_img, "Cartoon");
	gtk_widget_set_tooltip_text(GTK_WIDGET(button), "Cartoon effect");
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, -1);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",
			G_CALLBACK(ft_cartoon), scn);
	ft_add_button_6(scn);
}

void				ft_add_button_4(t_scene *scn)
{
	GtkWidget		*button_img;
	GtkToolItem		*button;

	button_img = gtk_image_new_from_file(ft_glob()->sepico);
	button = gtk_tool_button_new(button_img, "Sepia");
	gtk_widget_set_tooltip_text(GTK_WIDGET(button), "Sepia effect");
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, -1);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",
		G_CALLBACK(ft_sepia), scn);
	button_img = gtk_image_new_from_file(ft_glob()->anaico);
	button = gtk_tool_button_new(button_img, "Anaglyph");
	gtk_widget_set_tooltip_text(GTK_WIDGET(button), "Anaglyph effect");
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, -1);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",
		G_CALLBACK(ft_anaglyph), scn);
	ft_add_button_5(scn);
}

void				ft_add_button_3(t_scene *scn)
{
	GtkWidget		*button_img;
	GtkToolItem		*button;

	button_img = gtk_image_new_from_file(ft_glob()->antico);
	button = gtk_tool_button_new(button_img, "Anti Aliasing");
	gtk_widget_set_tooltip_text(GTK_WIDGET(button), "Anti Aliasing");
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, -1);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",
		G_CALLBACK(ft_antialiasing), scn);
	button_img = gtk_image_new_from_file(ft_glob()->greico);
	button = gtk_tool_button_new(button_img, "Greyscale");
	gtk_widget_set_tooltip_text(GTK_WIDGET(button), "Greyscale effect");
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, -1);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",
		G_CALLBACK(ft_greyscale), scn);
	ft_add_button_4(scn);
}

void				ft_add_button_2(t_scene *scn)
{
	GtkWidget		*button_img;
	GtkToolItem		*button;

	button_img = gtk_image_new_from_file(ft_glob()->recico);
	button = gtk_tool_button_new(button_img, "Rec scene");
	gtk_widget_set_tooltip_text(GTK_WIDGET(button), "Record scene");
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, -1);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",
		G_CALLBACK(ft_film), scn);
	button_img = gtk_image_new_from_file(ft_glob()->dupico);
	button = gtk_tool_button_new(button_img, "Duplicate scene");
	gtk_widget_set_tooltip_text(GTK_WIDGET(button), "Duplicate scene");
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, -1);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",
		G_CALLBACK(ft_dup_scn), scn);
	ft_add_button_3(scn);
}

void				ft_add_button(t_scene *scn)
{
	GtkWidget		*button_img;
	GtkToolItem		*button;

	button_img = gtk_image_new_from_file(ft_glob()->newico);
	button = gtk_tool_button_new(button_img, "Add object");
	gtk_widget_set_tooltip_text(GTK_WIDGET(button), "Add object");
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, -1);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",
		G_CALLBACK(ft_add_obj), scn);
	button_img = gtk_image_new_from_file(ft_glob()->colico);
	button = gtk_tool_button_new(button_img, "Change color");
	gtk_widget_set_tooltip_text(GTK_WIDGET(button), "Change color");
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, -1);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",
		G_CALLBACK(ft_change_color), scn);
	button_img = gtk_image_new_from_file(ft_glob()->savico);
	button = gtk_tool_button_new(button_img, "Save scene");
	gtk_widget_set_tooltip_text(GTK_WIDGET(button), "Save scene");
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, -1);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",
		G_CALLBACK(ft_save_img), scn);
	ft_add_button_2(scn);
}
