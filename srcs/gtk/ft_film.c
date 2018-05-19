/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_film.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 10:32:47 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 22:07:22 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void					ft_create_film(t_scene *scn)
{
	char					*cmd;
	char					**cmd_array;
	pid_t					pid;

	if (!scn)
		return ;
	cmd = ft_strdup("ffmpeg -framerate 1 -pattern_type glob -i ");
	cmd = ft_strjoin(cmd, scn->vid_dir, 1);
	cmd = ft_strjoin(cmd, "/*.jpeg -vf fps=25 ", 1);
	cmd = ft_strjoin(cmd, ft_itoa((int)time(NULL)), 1);
	cmd = ft_strjoin(cmd, ".mp4", 1);
	cmd_array = ft_strsplit(cmd, ' ');
	if ((pid = fork()) == -1)
		ft_perror(NULL, FALSE);
	if (pid == 0)
	{
		execvp(cmd_array[0], cmd_array);
		ft_perror(NULL, TRUE);
	}
}

void						ft_save_img_film(t_scene *scn)
{
	char					*filename;

	if (!scn->scene->pixbuf)
		return ;
	filename = ft_strjoin(scn->vid_dir, "/", 3);
	filename = ft_strjoin(filename, ft_itoa(scn->order), 2);
	filename = ft_strjoin(filename, ".jpeg", 1);
	if (!gdk_pixbuf_save(scn->scene->pixbuf, filename, "jpeg",
		&ft_glob()->error, "quality", "100", NULL))
	{
		ft_putstr_fd("rt: ", 2);
		ft_putendl_fd(ft_glob()->error->message, 2);
		g_free(ft_glob()->error);
		exit(EXIT_FAILURE);
	}
	scn->order++;
	free(filename);
}

void						*ft_film2(void *arg)
{
	t_scene					*scn;

	scn = (t_scene*)arg;
	while (42)
	{
		sleep(1);
		ft_save_img_film(scn);
	}
	return (NULL);
}

void						ft_film(gpointer data)
{
	t_scene					*scn;

	scn = (t_scene*)data;
	if (scn->vid == 0)
	{
		scn->vid = 1;
		scn->order = 0;
		pthread_create(&scn->pid_rec, NULL, &ft_film2, scn);
	}
	else
	{
		scn->vid = 0;
		pthread_cancel(scn->pid_rec);
		if (scn->scene->pixbuf)
			ft_create_film(scn);
	}
}
