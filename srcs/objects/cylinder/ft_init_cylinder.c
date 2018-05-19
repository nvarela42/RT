/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 14:24:12 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 15:09:40 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			ft_init_cylinder_2(t_objects *cyl, xmlNodePtr child)
{
	t_vector		tmp;
	xmlAttrPtr		attr;

	while (child != NULL)
	{
		attr = child->properties;
		if (!ft_strcmp((char*)child->name, "pos"))
			ft_create_vector(&tmp, attr);
		if (!ft_strcmp((char*)child->name, "rotation"))
			ft_create_vector(&cyl->rotation, attr);
		if (!ft_strcmp((char*)child->name, "translation"))
			ft_create_vector(&cyl->translation, attr);
		if (!ft_strcmp((char*)child->name, "limit_pos"))
			cyl->limit_pos = ft_atof((char*)attr->children->content);
		if (!ft_strcmp((char*)child->name, "limit_neg"))
			cyl->limit_neg = ft_atof((char*)attr->children->content);
		child = child->next;
	}
	cyl->type = 3;
	ft_plus_vector(&cyl->pos, &tmp, &cyl->translation);
}

void				ft_init_cylinder(void *obj, xmlNodePtr node, t_scene *scene)
{
	xmlNodePtr		child;
	xmlAttrPtr		attr;
	t_objects		*cyl;

	(void)scene;
	cyl = (t_objects*)obj;
	attr = node->properties;
	while (attr != NULL)
	{
		if (!ft_strcmp((char*)attr->name, "radius"))
			cyl->radius = ft_atof((char *)attr->children->content);
		if (!ft_strcmp((char*)attr->name, "materia_id"))
			cyl->material_id = ft_atof((char *)attr->children->content);
		attr = attr->next;
	}
	child = node->children;
	ft_init_cylinder_2(cyl, child);
}
