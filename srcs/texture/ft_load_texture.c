/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontagn <vmontagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 09:52:09 by vmontagn          #+#    #+#             */
/*   Updated: 2018/05/15 13:46:46 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				ft_load_texture(t_texture *t, char *name)
{
	GdkPixbuf		*img;
	GError			*error;

	if (name == NULL || ft_strlen(name) == 0)
		return ;
	error = NULL;
	img = gdk_pixbuf_new_from_file(name, &error);
	if (img == NULL)
	{
		ft_perror(name, FALSE);
		t->data = NULL;
	}
	else
	{
		t->data = img;
		t->w = gdk_pixbuf_get_width(img);
		t->h = gdk_pixbuf_get_height(img);
	}
}
