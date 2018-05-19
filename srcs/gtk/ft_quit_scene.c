/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 13:37:19 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 22:01:52 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		ft_quit_scene_2(t_scene *scn)
{
	pthread_cancel(scn->pid_rec);
	gtk_window_close(GTK_WINDOW(scn->scene->win));
	gtk_widget_destroy(scn->scene->win);
	g_object_unref(scn->scene->pixbuf);
	scn->scene->pixbuf = NULL;
	ft_free_camera(scn);
	ft_free_light(scn);
	ft_free_materia(scn);
	ft_free_object(scn);
	ft_free_perlin(scn);
	ft_free_texture(scn);
}

void			ft_quit_scene(gpointer data)
{
	t_scene		*scn;
	t_scene		*prev;
	t_scene		*next;

	scn = (t_scene*)data;
	if (!scn)
		return ;
	next = scn->next;
	prev = scn->prev;
	ft_quit_scene_2(scn);
	free(scn->vid_dir);
	scn->vid_dir = NULL;
	free(scn);
	if (prev == NULL)
		ft_glob()->scenes = next;
	else
		prev->next = NULL;
	if (next != NULL)
		next->prev = prev;
	scn = ft_glob()->scenes;
}
