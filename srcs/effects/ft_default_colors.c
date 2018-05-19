/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_default_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstroh <cstroh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 19:10:24 by cstroh            #+#    #+#             */
/*   Updated: 2018/05/15 11:20:10 by cstroh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			ft_default_colors(gpointer data)
{
	t_scene		*scn;

	scn = (t_scene*)data;
	ft_init_effects(scn);
	scn->defcolors = 1;
	scn->scene->recalc = 1;
	ft_calc_scene((gpointer)scn);
	gtk_image_set_from_pixbuf(GTK_IMAGE(scn->scene->view), scn->scene->pixbuf);
	ft_text_effects(scn);
}
