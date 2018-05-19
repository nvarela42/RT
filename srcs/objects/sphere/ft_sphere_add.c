/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 11:19:48 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 14:59:35 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				ft_sphere_add(t_scene *scn)
{
	t_objects		*obj;

	obj = (t_objects*)ft_create_object(scn);
	obj->type = 1;
	obj->radius = 2;
	obj->material_id = 1;
	obj->material = scn->materials;
}
