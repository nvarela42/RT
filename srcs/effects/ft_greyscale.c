/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_greyscale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstroh <cstroh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 12:56:28 by cstroh            #+#    #+#             */
/*   Updated: 2018/05/15 11:20:33 by cstroh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				ft_greyscale(gpointer data)
{
	t_scene			*scn;

	scn = (t_scene*)data;
	ft_init_effects(scn);
	scn->greyscale = 1;
	scn->scene->recalc = 1;
	ft_calc_scene((gpointer)scn);
	gtk_image_set_from_pixbuf(GTK_IMAGE(scn->scene->view), scn->scene->pixbuf);
	ft_text_effects(scn);
}

void				ft_set_greyscale(t_color *color)
{
	t_color			c;

	c.r = (0.299 * color->r) + (0.587 * color->g) + (0.114 * color->b);
	c.g = (0.299 * color->r) + (0.587 * color->g) + (0.114 * color->b);
	c.b = (0.299 * color->r) + (0.587 * color->g) + (0.114 * color->b);
	if (c.r > 1)
		c.r = 1;
	if (c.g > 1)
		c.g = 1;
	if (c.b > 1)
		c.b = 1;
	*color = c;
}
