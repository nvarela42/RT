/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_button_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstroh <cstroh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 10:58:50 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 00:03:01 by cstroh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			ft_add_button_8(t_scene *scn)
{
	GtkToolItem		*button;

	button = gtk_separator_tool_item_new();
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, 2);
	button = gtk_separator_tool_item_new();
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, 5);
	button = gtk_separator_tool_item_new();
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, 8);
	button = gtk_separator_tool_item_new();
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, 14);
	button = gtk_separator_tool_item_new();
	gtk_separator_tool_item_set_draw((GtkSeparatorToolItem*)button, FALSE);
	gtk_tool_item_set_expand(button, TRUE);
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, 19);
}

void				ft_add_button_7(t_scene *scn)
{
	GtkWidget		*button_img;
	GtkToolItem		*button;

	button_img = gtk_image_new_from_file(ft_glob()->triico);
	button = gtk_tool_button_new(button_img, "Tritanopia");
	gtk_widget_set_tooltip_text(GTK_WIDGET(button), "Tritanopia effect");
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, -1);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",
			G_CALLBACK(ft_tritanopia), scn);
	button_img = gtk_image_new_from_file(ft_glob()->offico);
	button = gtk_tool_button_new(button_img, "Default colors");
	gtk_widget_set_tooltip_text(GTK_WIDGET(button), "Default colors");
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, -1);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",
			G_CALLBACK(ft_default_colors), scn);
	button_img = gtk_image_new_from_file(ft_glob()->zikico);
	button = gtk_tool_button_new(button_img, "Run music");
	gtk_widget_set_tooltip_text(GTK_WIDGET(button), "Do you love music ?");
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, -1);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",
			G_CALLBACK(ft_play_sound), scn);
	ft_add_button_8(scn);
}

void				ft_add_button_6(t_scene *scn)
{
	GtkWidget		*button_img;
	GtkToolItem		*button;

	button_img = gtk_image_new_from_file(ft_glob()->deuico);
	button = gtk_tool_button_new(button_img, "Deuteranopia");
	gtk_widget_set_tooltip_text(GTK_WIDGET(button), "Deuteranopia effect");
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, -1);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",
		G_CALLBACK(ft_deuteranopia), scn);
	button_img = gtk_image_new_from_file(ft_glob()->proico);
	button = gtk_tool_button_new(button_img, "Protanopia");
	gtk_widget_set_tooltip_text(GTK_WIDGET(button), "Protanopia effect");
	gtk_toolbar_insert(GTK_TOOLBAR(scn->scene->toolbar), button, -1);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",
		G_CALLBACK(ft_protanopia), scn);
	ft_add_button_7(scn);
}
