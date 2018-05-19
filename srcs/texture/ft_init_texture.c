/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontagn <vmontagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 11:37:31 by vmontagn          #+#    #+#             */
/*   Updated: 2018/05/14 12:24:39 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int			ft_create_type(xmlAttrPtr attr)
{
	while (attr != NULL)
	{
		if (!ft_strcmp((char*)attr->name, "type"))
			return (ft_atof((char *)attr->children->content));
		attr = attr->next;
	}
	return (0);
}

static void			ft_get_width_height(xmlAttrPtr attr, int *w, int *h)
{
	while (attr != NULL)
	{
		if (!ft_strcmp((char*)attr->name, "width"))
			*w = ft_atoi((char *)attr->children->content);
		if (!ft_strcmp((char*)attr->name, "height"))
			*h = ft_atoi((char *)attr->children->content);
		attr = attr->next;
	}
}

static void			ft_create_texture_elem(t_texture *obj, xmlAttrPtr attr)
{
	while (attr != NULL)
	{
		if (!ft_strcmp((char*)attr->name, "texture"))
			ft_load_texture(obj, (char *)attr->children->content);
		attr = attr->next;
	}
}

static void			ft_init_texture_2(t_texture *texture, xmlNodePtr child)
{
	xmlAttrPtr		attr;

	while (child != NULL)
	{
		attr = child->properties;
		if (!ft_strcmp((char*)child->name, "type"))
			texture->type = ft_create_type(attr);
		if (!ft_strcmp((char*)child->name, "src"))
			ft_create_texture_elem(texture, attr);
		if (!ft_strcmp((char*)child->name, "scale"))
			ft_get_width_height(attr, &texture->sw, &texture->sh);
		if (!ft_strcmp((char*)child->name, "origin"))
			ft_get_width_height(attr, &texture->ow, &texture->oh);
		child = child->next;
	}
}

void				ft_init_texture(void *obj, xmlNodePtr node, t_scene *scn)
{
	xmlAttrPtr		attr;
	xmlNodePtr		child;
	t_texture		*texture;

	(void)scn;
	texture = (t_texture*)obj;
	attr = node->properties;
	texture->id = 0;
	while (attr != NULL)
	{
		if (!ft_strcmp((char*)attr->name, "id"))
			texture->id = ft_atoi((char *)attr->children->content);
		attr = attr->next;
	}
	child = node->children;
	ft_init_texture_2(texture, child);
}
