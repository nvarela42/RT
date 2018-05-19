/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:15:37 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 15:22:11 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				ft_plane_add(t_scene *scn)
{
	t_objects		*obj;

	obj = (t_objects*)ft_create_object(scn);
	obj->type = 2;
	obj->pos.x = 0;
	obj->pos.y = -1;
	obj->pos.z = 0;
	obj->normal.x = 0;
	obj->normal.y = 1;
	obj->normal.z = 0;
	obj->material_id = 1;
	obj->material = scn->materials;
}
