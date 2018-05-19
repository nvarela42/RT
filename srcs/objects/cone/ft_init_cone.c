/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 14:13:49 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/14 11:51:25 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			ft_init_cone_2(t_objects *cone, xmlNodePtr child)
{
	xmlAttrPtr		attr;
	t_vector		tmp;

	while (child != NULL)
	{
		attr = child->properties;
		if (!ft_strcmp((char*)child->name, "pos"))
			ft_create_vector(&tmp, attr);
		if (!ft_strcmp((char*)child->name, "rotation"))
			ft_create_vector(&cone->rotation, attr);
		if (!ft_strcmp((char*)child->name, "translation"))
			ft_create_vector(&cone->translation, attr);
		child = child->next;
	}
	cone->type = 4;
	ft_plus_vector(&cone->pos, &tmp, &cone->translation);
}

void				ft_init_cone(void *obj, xmlNodePtr node, t_scene *scene)
{
	xmlAttrPtr		attr;
	xmlNodePtr		child;
	t_objects		*cone;

	(void)scene;
	cone = (t_objects*)obj;
	attr = node->properties;
	while (attr != NULL)
	{
		if (!ft_strcmp((char*)attr->name, "radius"))
			cone->radius = ft_atof((char *)attr->children->content);
		if (!ft_strcmp((char*)attr->name, "materia_id"))
			cone->material_id = ft_atof((char *)attr->children->content);
		attr = attr->next;
	}
	child = node->children;
	ft_init_cone_2(cone, child);
}
