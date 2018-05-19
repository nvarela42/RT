/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cartoon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstroh <cstroh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:33:30 by cstroh            #+#    #+#             */
/*   Updated: 2018/05/15 22:00:50 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static float		ft_round(float number)
{
	if (number < 0.0)
		number = 0.0;
	if (number > 0.0 && number < 0.2)
		number = 0.0;
	if (number > 0.2 && number < 0.4)
		number = 0.2;
	if (number > 0.4 && number < 0.6)
		number = 0.4;
	if (number > 0.6 && number < 0.8)
		number = 0.6;
	if (number > 0.8 && number < 1.0)
		number = 0.8;
	if (number >= 1.0)
		number = 1.0;
	return (number);
}

void				ft_cartoon(gpointer data)
{
	t_scene			*scn;

	scn = (t_scene*)data;
	ft_init_effects(scn);
	scn->cartoon = 1;
	scn->scene->recalc = 1;
	ft_calc_scene((gpointer)scn);
	gtk_image_set_from_pixbuf(GTK_IMAGE(scn->scene->view), scn->scene->pixbuf);
	ft_text_effects(scn);
}

void				ft_set_cartoon(t_color *color)
{
	color->r = ft_round(color->r);
	color->g = ft_round(color->g);
	color->b = ft_round(color->b);
}
