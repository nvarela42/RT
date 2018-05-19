/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anaglyph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstroh <cstroh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:24:32 by cstroh            #+#    #+#             */
/*   Updated: 2018/05/15 11:51:49 by cstroh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			ft_conv_red(t_scene *scn, int x, int y, t_color *color)
{
	guchar			*p;

	p = scn->scene->pixels_2 + y * scn->scene->rowstride_2 + x *
	scn->scene->n_channels_2;
	color->r = (float)p[0] / (float)255;
	color->g = (float)p[1] / (float)255;
	color->b = (float)p[2] / (float)255;
}

static void			ft_conv_cyan(t_scene *scn, int x, int y, t_color *color)
{
	guchar			*p;

	p = scn->scene->pixels + y * scn->scene->rowstride + x *
	scn->scene->n_channels;
	color->r = (float)p[0] / (float)255;
	color->g = (float)p[1] / (float)255;
	color->b = (float)p[2] / (float)255;
}

static void			*ft_merge_views(void *obj)
{
	t_thread		*th;
	t_color			mix;
	t_color			red;
	t_color			cyan;
	int				x;

	th = (t_thread*)obj;
	x = 0;
	while (x < 1280)
	{
		ft_color_init(&cyan);
		ft_color_init(&red);
		ft_conv_red(th->scn, x, th->y1, &red);
		ft_conv_cyan(th->scn, x, th->y1, &cyan);
		ft_mix_color(&red, &cyan, &mix);
		put_pixel(th->scn, x, th->y1, mix);
		x++;
	}
	pthread_exit(NULL);
	return (NULL);
}

static void			ft_set_anaglyph(t_scene *scn)
{
	int				i;

	ft_create_thread(scn);
	i = 0;
	while (i < MAXTHREAD)
	{
		if (pthread_create(&scn->thread[i].id, NULL, ft_merge_views,
			(void*)&scn->thread[i]) != 0)
			ft_perror(NULL, TRUE);
		i++;
	}
	scn->scene->recalc = 0;
	i = 0;
	while (i < MAXTHREAD)
	{
		pthread_join(scn->thread[i].id, NULL);
		i++;
	}
}

void				ft_anaglyph(gpointer data)
{
	t_scene			*scn;

	scn = (t_scene*)data;
	ft_init_effects(scn);
	scn->anaglyph = 1;
	scn->camera->pos.x += 0.005;
	scn->scene->recalc = 1;
	scn->scene->n_channels_2 = gdk_pixbuf_get_n_channels(scn->scene->pixbuf);
	scn->scene->rowstride_2 = gdk_pixbuf_get_rowstride(scn->scene->pixbuf);
	scn->scene->pixels_2 = gdk_pixbuf_get_pixels(scn->scene->pixbuf);
	ft_calc_scene((gpointer)scn);
	scn->scene->red_pixbuf = scn->scene->pixbuf;
	scn->anaglyph = 2;
	scn->camera->pos.x -= 0.005;
	scn->scene->recalc = 1;
	scn->scene->pixbuf = gdk_pixbuf_new(GDK_COLORSPACE_RGB, TRUE, 8, 1280, 960);
	scn->scene->n_channels = gdk_pixbuf_get_n_channels(scn->scene->pixbuf);
	scn->scene->rowstride = gdk_pixbuf_get_rowstride(scn->scene->pixbuf);
	scn->scene->pixels = gdk_pixbuf_get_pixels(scn->scene->pixbuf);
	ft_calc_scene((gpointer)scn);
	ft_set_anaglyph(scn);
	g_object_unref(scn->scene->red_pixbuf);
	gtk_image_set_from_pixbuf(GTK_IMAGE(scn->scene->view), scn->scene->pixbuf);
	ft_text_effects(scn);
	scn->anaglyph = 1;
}
