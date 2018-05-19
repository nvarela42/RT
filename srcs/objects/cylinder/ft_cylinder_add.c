/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:09:52 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 15:12:18 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				ft_cylinder_add(t_scene *scn)
{
	t_objects		*obj;

	obj = (t_objects*)ft_create_object(scn);
	obj->type = 3;
	obj->radius = 2;
	obj->material_id = 1;
	obj->material = scn->materials;
}
