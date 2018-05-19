/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_materia.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 11:42:31 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/15 18:34:04 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void					ft_copy_materia(t_scene *tmp, t_scene *act)
{
	t_materials			*obj;
	t_materials			*cur;

	if ((cur = act->materials) == NULL)
		return ;
	while (cur)
	{
		obj = (t_materials*)ft_create_materia(tmp);
		obj->material_id = cur->material_id;
		ft_copy_color(&cur->material_color, &obj->material_color);
		obj->texture_id = cur->texture_id;
		obj->normal_id = cur->normal_id;
		obj->shiness = cur->shiness;
		obj->reflect = cur->reflect;
		obj->refract = cur->refract;
		cur = cur->next;
	}
}
