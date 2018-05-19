/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 13:58:44 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 19:49:39 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_scene				*ft_get_last_scene(t_scene *scn)
{
	while (scn->next)
		scn = scn->next;
	if (scn->scene == NULL)
	{
		if ((scn->scene = (t_scene_win*)malloc(sizeof(t_scene_win))) == NULL)
			ft_perror(NULL, TRUE);
		scn->scene->win = NULL;
	}
	return (scn);
}

static void			ft_launch_scene_3(t_rt *rt, t_scene *scn)
{
	gtk_container_add(GTK_CONTAINER(scn->scene->event_box), scn->scene->view);
	gtk_box_pack_start((GtkBox*)scn->scene->vbox, scn->scene->event_box, TRUE,
		TRUE, 0);
	gtk_box_pack_start((GtkBox*)scn->scene->vbox, scn->scene->status, TRUE,
		TRUE, 0);
	gtk_container_add(GTK_CONTAINER(scn->scene->win), scn->scene->vbox);
	g_signal_connect(G_OBJECT(scn->scene->win), "key_press_event",
		G_CALLBACK(ft_key_press), scn);
	gtk_application_add_window(rt->app, GTK_WINDOW(scn->scene->win));
	g_signal_connect_swapped(G_OBJECT(scn->scene->win), "destroy",
		G_CALLBACK(ft_quit_scene), scn);
	g_signal_connect(G_OBJECT(scn->scene->event_box), "button_press_event",
		G_CALLBACK(ft_sel_object), scn);
	scn->scene->recalc = 1;
}

static void			ft_launch_scene_2(t_rt *rt, t_scene *scn, t_stat *sb)
{
	if ((scn->vid_dir = ft_strjoin(rt->wd, VIDDIR, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((scn->vid_dir = ft_strjoin(scn->vid_dir,
		ft_itoa((unsigned)time(NULL)), 0)) == NULL)
		ft_perror(NULL, TRUE);
	if (stat(VIDDIR, sb) != 0)
	{
		if (mkdir(VIDDIR, 0700) == -1)
			ft_perror(NULL, TRUE);
	}
	if (stat(scn->vid_dir, sb) != 0)
	{
		if (mkdir(scn->vid_dir, 0700) == -1)
			ft_perror(NULL, TRUE);
	}
	ft_launch_scene_3(rt, scn);
}

void				ft_launch_scene(t_rt *rt)
{
	t_scene			*scn;
	t_stat			sb;

	scn = ft_get_last_scene(rt->scenes);
	scn->scene->status = gtk_statusbar_new();
	scn->scene->win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_resize(GTK_WINDOW(scn->scene->win), 1280, 980);
	scn->scene->vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 1);
	scn->scene->toolbar = gtk_toolbar_new();
	scn->perlin_permutation = ft_init_perlin();
	ft_add_button(scn);
	gtk_box_pack_start((GtkBox*)scn->scene->vbox, scn->scene->toolbar, TRUE,
		TRUE, 0);
	scn->scene->event_box = gtk_event_box_new();
	scn->scene->pixbuf = gdk_pixbuf_new(GDK_COLORSPACE_RGB, TRUE, 8, 1280, 960);
	scn->scene->red_pixbuf = NULL;
	scn->scene->view = gtk_image_new_from_pixbuf(scn->scene->pixbuf);
	ft_launch_scene_2(rt, scn, &sb);
	scn->scene->n_channels = gdk_pixbuf_get_n_channels(scn->scene->pixbuf);
	scn->scene->rowstride = gdk_pixbuf_get_rowstride(scn->scene->pixbuf);
	scn->scene->pixels = gdk_pixbuf_get_pixels(scn->scene->pixbuf);
	ft_calc_scene((gpointer)scn);
	gtk_widget_show_all(scn->scene->win);
}
