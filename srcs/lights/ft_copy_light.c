/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 11:41:00 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/15 16:32:28 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void					ft_copy_light(t_scene *tmp, t_scene *act)
{
	t_lights			*obj;
	t_lights			*cur;

	if ((cur = act->lights) == NULL)
		return ;
	while (cur)
	{
		obj = (t_lights*)ft_create_light(tmp);
		ft_copy_vector(&cur->pos, &obj->pos);
		ft_copy_color(&cur->light_color, &obj->light_color);
		obj->radius = cur->radius;
		obj->spot = cur->spot;
		obj->intensity = cur->intensity;
		obj->rad_spot = cur->rad_spot;
		cur = cur->next;
	}
}
