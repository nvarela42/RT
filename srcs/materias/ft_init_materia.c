/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_materia.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:29:01 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/14 12:13:59 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			ft_init_materia_2(t_materials *mat, xmlNodePtr child)
{
	xmlAttrPtr		attr;

	while (child != NULL)
	{
		attr = child->properties;
		if (!ft_strcmp("color", (char*)child->name))
			ft_create_color(&mat->material_color, attr);
		if (!ft_strcmp("shiness", (char*)child->name))
			mat->shiness = ft_atof((char *)attr->children->content);
		if (!ft_strcmp("reflect", (char*)child->name))
			mat->reflect = ft_atof((char*)attr->children->content);
		if (!ft_strcmp("refract", (char*)child->name))
			mat->refract = ft_atof((char*)attr->children->content);
		if (!ft_strcmp("bump", (char*)child->name))
			mat->bump = ft_atof((char*)attr->children->content);
		child = child->next;
	}
}

void				ft_init_materia(void *obj, xmlNodePtr node, t_scene *scn)
{
	xmlAttrPtr		attr;
	xmlNodePtr		child;
	t_materials		*mat;

	(void)scn;
	mat = (t_materials*)obj;
	attr = node->properties;
	while (attr != NULL)
	{
		if (!ft_strcmp((char*)attr->name, "id"))
			mat->material_id = ft_atof((char *)attr->children->content);
		if (!ft_strcmp((char*)attr->name, "texture_id"))
			mat->texture_id = ft_atoi((char *)attr->children->content);
		if (!ft_strcmp((char*)attr->name, "normal_id"))
			mat->normal_id = ft_atoi((char *)attr->children->content);
		attr = attr->next;
	}
	child = node->children;
	ft_init_materia_2(mat, child);
}
