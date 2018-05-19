/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:28:24 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/10 17:53:39 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			ft_init_light_2(t_lights *light, xmlNodePtr child)
{
	xmlAttrPtr		attr;

	while (child != NULL)
	{
		attr = child->properties;
		if (!ft_strcmp("pos", (char*)child->name))
			ft_create_vector(&light->pos, attr);
		if (!ft_strcmp("color", (char*)child->name))
			ft_create_color(&light->light_color, attr);
		if (!ft_strcmp("intensity", (char*)child->name))
			light->intensity = ft_atof((char*)attr->children->content);
		child = child->next;
	}
}

void				ft_init_light(void *obj, xmlNodePtr node, t_scene *scn)
{
	xmlAttrPtr		attr;
	xmlNodePtr		child;
	t_lights		*light;

	(void)scn;
	light = (t_lights*)obj;
	attr = node->properties;
	while (attr != NULL)
	{
		if (!ft_strcmp("radius", (char*)attr->name))
			light->radius = ft_atof((char*)attr->children->content);
		if (!ft_strcmp("spot", (char*)attr->name))
			light->spot = ft_atof((char*)attr->children->content);
		if (!ft_strcmp("rad_spot", (char*)attr->name))
			light->rad_spot = ft_atof((char*)attr->children->content);
		attr = attr->next;
	}
	child = node->children;
	ft_init_light_2(light, child);
}
