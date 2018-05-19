/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deuteranopia.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstroh <cstroh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 17:46:21 by cstroh            #+#    #+#             */
/*   Updated: 2018/05/15 11:20:27 by cstroh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			ft_deuteranopia(gpointer data)
{
	t_scene		*scn;

	scn = (t_scene*)data;
	ft_init_effects(scn);
	scn->deuteranopia = 1;
	scn->scene->recalc = 1;
	ft_calc_scene((gpointer)scn);
	gtk_image_set_from_pixbuf(GTK_IMAGE(scn->scene->view), scn->scene->pixbuf);
	ft_text_effects(scn);
}

void			ft_set_deuteranopia(t_color *color)
{
	t_color		c;

	c.r = (0.625 * color->r) + (0.375 * color->g) + (0.0 * color->b);
	c.g = (0.7 * color->r) + (0.3 * color->g) + (0.0 * color->b);
	c.b = (0.0 * color->r) + (0.3 * color->g) + (0.7 * color->b);
	if (c.r > 1)
		c.r = 1;
	if (c.g > 1)
		c.g = 1;
	if (c.b > 1)
		c.b = 1;
	*color = c;
}
