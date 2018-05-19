/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 11:15:58 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 17:55:36 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void					ft_run(t_rt *rt)
{
	t_scene				*scn;

	scn = ft_get_last_scene(rt->scenes);
	ft_link_mat(scn->textures, scn->materials, scn->objects);
	ft_launch_scene(rt);
	scn->sel_obj = NULL;
}
