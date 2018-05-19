/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_effects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstroh <cstroh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 11:02:46 by cstroh            #+#    #+#             */
/*   Updated: 2018/05/15 15:41:10 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				ft_init_effects(t_scene *scn)
{
	scn->anaglyph = 0;
	scn->antialiasing = 0;
	scn->cartoon = 0;
	scn->greyscale = 0;
	scn->sepia = 0;
	scn->motionblur = 0;
	scn->deuteranopia = 0;
	scn->protanopia = 0;
	scn->tritanopia = 0;
	scn->defcolors = 0;
}
