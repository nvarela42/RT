/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 11:29:24 by agoomany          #+#    #+#             */
/*   Updated: 2018/04/29 11:29:41 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			ft_save_img(gpointer data)
{
	t_stat			st;
	char			*filename;
	char			*timestamp;
	t_scene			*scn;

	if (stat(ft_glob()->savedir, &st) == -1)
		mkdir(ft_glob()->savedir, 0700);
	filename = ft_strjoin_sep(ft_glob()->savedir, "scene_", '/');
	timestamp = ft_itoa((unsigned)time(NULL));
	filename = ft_strjoin(filename, timestamp, 2);
	filename = ft_strjoin(filename, ".jpeg", 1);
	scn = (t_scene*)data;
	if (!gdk_pixbuf_save(scn->scene->pixbuf, filename, "jpeg",
		&ft_glob()->error, "quality", "100", NULL))
	{
		ft_putstr_fd("rt: ", 2);
		ft_putendl_fd(ft_glob()->error->message, 2);
		g_free(ft_glob()->error);
		exit(EXIT_FAILURE);
	}
	free(filename);
}
