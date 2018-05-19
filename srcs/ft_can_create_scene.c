/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_can_create_scene.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 20:28:49 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/15 17:53:22 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int				ft_count_scene(t_rt *rt)
{
	int					ret;
	t_scene				*scn;

	ret = 0;
	scn = rt->scenes;
	if (scn)
	{
		while (scn)
		{
			ret++;
			scn = scn->next;
		}
	}
	return (ret);
}

int						ft_can_create_scene(t_rt *rt)
{
	if (ft_count_scene(rt) < MAXSCENE)
		return (TRUE);
	return (FALSE);
}
