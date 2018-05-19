/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cone_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:04:42 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 15:08:35 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				ft_cone_add(t_scene *scn)
{
	t_objects		*obj;

	obj = (t_objects*)ft_create_object(scn);
	obj->type = 4;
	obj->radius = 50;
	obj->material_id = 1;
	obj->material = scn->materials;
}
