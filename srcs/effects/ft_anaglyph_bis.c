/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anaglyph_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 17:52:03 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/13 18:01:09 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			ft_mix_color(t_color *red, t_color *cyan, t_color *mix)
{
	mix->r = (red->r + cyan->r) / 2;
	mix->g = (red->g + cyan->g) / 2;
	mix->b = (red->b + cyan->b) / 2;
	if (mix->r < 0)
		mix->r = -mix->r;
	if (mix->g < 0)
		mix->g = -mix->g;
	if (mix->b < 0)
		mix->b = -mix->b;
}
