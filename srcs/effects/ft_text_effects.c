/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_effects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 16:31:42 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 10:59:08 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			ft_text_colors_effects(t_scene *scn)
{
	if (scn->deuteranopia == 1)
		gtk_statusbar_push((GtkStatusbar *)scn->scene->status, 5,
		"Current effect loaded: Deuteranopia [colorblind mode]\n");
	if (scn->protanopia == 1)
		gtk_statusbar_push((GtkStatusbar *)scn->scene->status, 6,
		"Current effect loaded: Protanopia [colorblind mode]\n");
	if (scn->tritanopia == 1)
		gtk_statusbar_push((GtkStatusbar *)scn->scene->status, 7,
		"Current effect loaded: Tritanopia [colorblind mode]\n");
	if (scn->defcolors == 1)
		gtk_statusbar_push((GtkStatusbar *)scn->scene->status, 8,
		"Current effect loaded: Default colors mode\n");
}

void				ft_text_effects(t_scene *scn)
{
	if (scn->antialiasing == 1)
		gtk_statusbar_push((GtkStatusbar *)scn->scene->status, 1,
		"Current effect loaded: Anti aliasing\n");
	if (scn->greyscale == 1)
		gtk_statusbar_push((GtkStatusbar *)scn->scene->status, 1,
		"Current effect loaded: Greyscale filter\n");
	if (scn->sepia == 1)
		gtk_statusbar_push((GtkStatusbar *)scn->scene->status, 2,
		"Current effect loaded: Sepia filter\n");
	if (scn->anaglyph != 0)
		gtk_statusbar_push((GtkStatusbar *)scn->scene->status, 3,
		"Current effect loaded: Anaglyph [or Sterepscopy]\n");
	if (scn->cartoon == 1)
		gtk_statusbar_push((GtkStatusbar *)scn->scene->status, 4,
		"Current effect loaded: Cartoon filter\n");
	ft_text_colors_effects(scn);
}
