/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 14:33:34 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/09 13:45:49 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			ft_init_sphere_2(t_objects *sph, xmlNodePtr child)
{
	xmlAttrPtr		attr;
	t_vector		tmp;

	while (child != NULL)
	{
		attr = child->properties;
		if (!ft_strcmp((char*)child->name, "pos"))
			ft_create_vector(&tmp, attr);
		else if (!ft_strcmp((char*)child->name, "rotation"))
			ft_create_vector(&sph->rotation, attr);
		else if (!ft_strcmp((char*)child->name, "translation"))
			ft_create_vector(&sph->translation, attr);
		child = child->next;
	}
	sph->type = 1;
	ft_plus_vector(&sph->pos, &tmp, &sph->translation);
}

void				ft_init_sphere(void *obj, xmlNodePtr node, t_scene *scene)
{
	xmlAttrPtr		attr;
	xmlNodePtr		child;
	t_objects		*sph;

	(void)scene;
	sph = (t_objects*)obj;
	attr = node->properties;
	while (attr != NULL)
	{
		if (!ft_strcmp((char*)attr->name, "radius"))
			sph->radius = ft_atof((char *)attr->children->content);
		if (!ft_strcmp((char*)attr->name, "materia_id"))
			sph->material_id = ft_atof((char *)attr->children->content);
		attr = attr->next;
	}
	child = node->children;
	ft_init_sphere_2(sph, child);
}
