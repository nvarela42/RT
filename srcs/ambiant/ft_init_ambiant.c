/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ambiant.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:28:24 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 10:58:23 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				ft_init_ambiant(void *obj, xmlNodePtr node, t_scene *scn)
{
	xmlAttrPtr		attr;
	xmlNodePtr		child;
	t_ambiant		*ambiant;

	(void)scn;
	ambiant = (t_ambiant*)obj;
	child = node->children;
	attr = child->properties;
	while (child != NULL)
	{
		if (!ft_strcmp("color", (char*)child->name))
			ft_create_color(&ambiant->color, attr);
		child = child->next;
	}
}
