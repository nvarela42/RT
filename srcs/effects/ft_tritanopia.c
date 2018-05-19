/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tritanopia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstroh <cstroh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 17:51:42 by cstroh            #+#    #+#             */
/*   Updated: 2018/05/15 11:21:02 by cstroh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			ft_tritanopia(gpointer data)
{
	t_scene		*scn;

	scn = (t_scene*)data;
	ft_init_effects(scn);
	scn->tritanopia = 1;
	scn->scene->recalc = 1;
	ft_calc_scene((gpointer)scn);
	gtk_image_set_from_pixbuf(GTK_IMAGE(scn->scene->view), scn->scene->pixbuf);
	ft_text_effects(scn);
}

void			ft_set_tritanopia(t_color *color)
{
	t_color		c;

	c.r = (0.95 * color->r) + (0.05 * color->g) + (0.0 * color->b);
	c.g = (0.433 * color->r) + (0.567 * color->g) + (0.0 * color->b);
	c.b = (0.0 * color->r) + (0.475 * color->g) + (0.525 * color->b);
	if (c.r > 1)
		c.r = 1;
	if (c.g > 1)
		c.g = 1;
	if (c.b > 1)
		c.b = 1;
	*color = c;
}
