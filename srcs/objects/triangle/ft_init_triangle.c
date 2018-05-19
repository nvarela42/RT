/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_triangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:29:45 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/09 14:06:03 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			ft_init_triangle2(t_objects *tri, xmlNodePtr child)
{
	xmlAttrPtr		attr;

	while (child != NULL)
	{
		attr = child->properties;
		if (!ft_strcmp((char*)child->name, "pos_edge1"))
			ft_create_vector(&tri->pos_edge1, attr);
		if (!ft_strcmp((char*)child->name, "pos_edge2"))
			ft_create_vector(&tri->pos_edge2, attr);
		if (!ft_strcmp((char*)child->name, "pos_edge3"))
			ft_create_vector(&tri->pos_edge3, attr);
		child = child->next;
	}
	tri->type = 5;
}

void				ft_init_triangle(void *obj, xmlNodePtr node, t_scene *scene)
{
	xmlNodePtr		child;
	xmlAttrPtr		attr;
	t_objects		*tri;

	(void)scene;
	tri = (t_objects*)obj;
	attr = node->properties;
	while (attr != NULL)
	{
		if (!ft_strcmp((char*)attr->name, "materia_id"))
			tri->material_id = ft_atof((char *)attr->children->content);
		attr = attr->next;
	}
	child = node->children;
	ft_init_triangle2(tri, child);
}
