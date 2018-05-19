/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_home.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:24:29 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/13 21:18:59 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void					ft_quit_app(gpointer data)
{
	t_rt					*rt;
	t_scene					*scn;
	t_scene					*tmp;

	rt = (t_rt*)data;
	scn = rt->scenes;
	gtk_main_quit();
	if (scn)
	{
		while (scn)
		{
			tmp = scn->next;
			ft_free_camera(scn);
			ft_free_light(scn);
			ft_free_materia(scn);
			ft_free_object(scn);
			ft_free_perlin(scn);
			free(scn);
			scn = tmp;
		}
	}
	exit(EXIT_SUCCESS);
}

static void					ft_init_home_2(t_rt *rt)
{
	GtkWidget				*button;
	GtkWidget				*button_img;
	GtkWidget				*button_box;

	button_box = gtk_button_box_new(GTK_ORIENTATION_VERTICAL);
	gtk_container_add(GTK_CONTAINER(rt->home), button_box);
	button = gtk_button_new_with_label("Open file");
	button_img = gtk_image_new_from_file(rt->openico);
	gtk_button_set_image(GTK_BUTTON(button), button_img);
	gtk_button_set_always_show_image(GTK_BUTTON(button), TRUE);
	gtk_container_add(GTK_CONTAINER(button_box), button);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",
			G_CALLBACK(ft_select_file), rt);
	button = gtk_button_new_with_label("Close RT");
	button_img = gtk_image_new_from_file(rt->quitico);
	gtk_button_set_image(GTK_BUTTON(button), button_img);
	gtk_button_set_always_show_image(GTK_BUTTON(button), TRUE);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",
			G_CALLBACK(ft_quit_app), rt);
	gtk_container_add(GTK_CONTAINER(button_box), button);
	gtk_button_box_set_layout((GtkButtonBox*)button_box, GTK_BUTTONBOX_EXPAND);
	gtk_widget_show_all(rt->home);
}

void						ft_init_home(GtkApplication *app, gpointer data)
{
	t_rt					*rt;
	GtkWidget				*titlebar;

	rt = (t_rt*)data;
	rt->home = gtk_application_window_new(app);
	gtk_window_set_default_size(GTK_WINDOW(rt->home), 200, 300);
	gtk_window_set_resizable(GTK_WINDOW(rt->home), FALSE);
	gtk_window_set_position(GTK_WINDOW(rt->home), GTK_WIN_POS_CENTER_ALWAYS);
	titlebar = gtk_header_bar_new();
	gtk_header_bar_set_title((GtkHeaderBar*)titlebar, "RT6CTRISTE");
	gtk_window_set_titlebar(GTK_WINDOW(rt->home), titlebar);
	ft_init_home_2(rt);
	gtk_widget_show_all(rt->home);
	gtk_main();
}
