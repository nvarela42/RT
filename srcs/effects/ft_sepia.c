/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sepia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstroh <cstroh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 22:39:56 by cstroh            #+#    #+#             */
/*   Updated: 2018/05/15 11:20:55 by cstroh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				ft_sepia(gpointer data)
{
	t_scene			*scn;

	scn = (t_scene*)data;
	ft_init_effects(scn);
	scn->sepia = 1;
	scn->scene->recalc = 1;
	ft_calc_scene((gpointer)scn);
	gtk_image_set_from_pixbuf(GTK_IMAGE(scn->scene->view), scn->scene->pixbuf);
	ft_text_effects(scn);
}

void				ft_set_sepia(t_color *color)
{
	t_color			c;

	c.r = (0.393 * color->r) + (0.769 * color->g) + (0.189 * color->b);
	c.g = (0.349 * color->r) + (0.686 * color->g) + (0.168 * color->b);
	c.b = (0.272 * color->r) + (0.534 * color->g) + (0.131 * color->b);
	if (c.r > 1)
		c.r = 1;
	if (c.g > 1)
		c.g = 1;
	if (c.b > 1)
		c.b = 1;
	*color = c;
}
