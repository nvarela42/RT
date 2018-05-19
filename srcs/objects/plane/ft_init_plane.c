/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 14:38:38 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 15:47:57 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			ft_init_plane_2(t_objects *pln, xmlNodePtr child)
{
	xmlAttrPtr		attr;
	t_vector		tmp;

	while (child != NULL)
	{
		attr = child->properties;
		if (!ft_strcmp((char*)child->name, "pos"))
			ft_create_vector(&tmp, attr);
		if (!ft_strcmp((char*)child->name, "normal"))
			ft_create_vector(&pln->normal, attr);
		if (!ft_strcmp((char*)child->name, "translation"))
			ft_create_vector(&pln->translation, attr);
		child = child->next;
	}
	pln->type = 2;
	ft_plus_vector(&pln->pos, &tmp, &pln->translation);
}

void				ft_init_plane(void *obj, xmlNodePtr node, t_scene *scn)
{
	xmlAttrPtr		attr;
	xmlNodePtr		child;
	t_objects		*pln;

	(void)scn;
	pln = (t_objects*)obj;
	attr = node->properties;
	while (attr != NULL)
	{
		if (!ft_strcmp((char*)attr->name, "materia_id"))
			pln->material_id = ft_atof((char *)attr->children->content);
		if (!ft_strcmp((char*)attr->name, "radius"))
			pln->radius = ft_atof((char *)attr->children->content);
		attr = attr->next;
	}
	child = node->children;
	ft_init_plane_2(pln, child);
}
