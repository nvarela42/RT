/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_effects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstroh <cstroh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 15:53:53 by cstroh            #+#    #+#             */
/*   Updated: 2018/05/12 23:01:14 by cstroh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			ft_set_red_view(t_color *color)
{
	t_color			red;

	red.r = (0.5 * color->r) + (0.5 * color->g) + (0.5 * color->b);
	red.g = (0.0 * color->r) + (0.0 * color->g) + (0.0 * color->b);
	red.b = (0.0 * color->r) + (0.0 * color->g) + (0.0 * color->b);
	if (red.r > 1)
		red.r = 1;
	if (red.g > 1)
		red.g = 1;
	if (red.b > 1)
		red.b = 1;
	*color = red;
}

static void			ft_set_cyan_view(t_color *color)
{
	t_color			cyan;

	cyan.r = (0.0 * color->r) + (0.0 * color->g) + (0.0 * color->b);
	cyan.g = (0.5 * color->r) + (0.5 * color->g) + (0.5 * color->b);
	cyan.b = (0.5 * color->r) + (0.5 * color->g) + (0.5 * color->b);
	if (cyan.r > 1)
		cyan.r = 1;
	if (cyan.g > 1)
		cyan.g = 1;
	if (cyan.b > 1)
		cyan.b = 1;
	*color = cyan;
}

void				ft_launch_effects(t_thread *th, t_color *color)
{
	if (th->scn->greyscale == 1)
		ft_set_greyscale(color);
	if (th->scn->sepia == 1)
		ft_set_sepia(color);
	if (th->scn->cartoon == 1)
		ft_set_cartoon(color);
	if (th->scn->anaglyph == 1)
		ft_set_red_view(color);
	if (th->scn->anaglyph == 2)
		ft_set_cyan_view(color);
	if (th->scn->deuteranopia == 1)
		ft_set_deuteranopia(color);
	if (th->scn->protanopia == 1)
		ft_set_protanopia(color);
	if (th->scn->tritanopia == 1)
		ft_set_tritanopia(color);
}
