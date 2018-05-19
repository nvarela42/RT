/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:17:47 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/15 15:22:43 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	ft_calc_edges(t_objects *cube)
{
	cube->edge_a = (t_vector){cube->pos.x - cube->size, cube->pos.y -
	cube->size, cube->pos.z - cube->size};
	cube->edge_b = (t_vector){cube->pos.x + cube->size, cube->pos.y -
	cube->size, cube->pos.z - cube->size};
	cube->edge_c = (t_vector){cube->pos.x - cube->size, cube->pos.y +
	cube->size, cube->pos.z - cube->size};
	cube->edge_d = (t_vector){cube->pos.x + cube->size, cube->pos.y +
	cube->size, cube->pos.z - cube->size};
	cube->edge_e = (t_vector){cube->pos.x + cube->size, cube->pos.y -
	cube->size, cube->pos.z + cube->size};
	cube->edge_f = (t_vector){cube->pos.x + cube->size, cube->pos.y +
	cube->size, cube->pos.z + cube->size};
	cube->edge_g = (t_vector){cube->pos.x - cube->size, cube->pos.y -
	cube->size, cube->pos.z + cube->size};
	cube->edge_h = (t_vector){cube->pos.x - cube->size, cube->pos.y +
	cube->size, cube->pos.z + cube->size};
}

void		ft_init_tricube(t_objects *cube, t_scene *scn)
{
	ft_calc_edges(cube);
	ft_add_edges(cube, scn);
}

static void	ft_init_cube_2(t_objects *cube, xmlNodePtr child)
{
	xmlAttrPtr	attr;
	t_vector	tmp;

	while (child != NULL)
	{
		attr = child->properties;
		if (!ft_strcmp((char*)child->name, "pos"))
		{
			ft_create_vector(&tmp, attr);
			cube->pos = tmp;
		}
		child = child->next;
	}
	cube->type = 6;
}

static void	ft_init_cube_1(t_objects *cube, xmlAttrPtr attr)
{
	if (!ft_strcmp((char*)attr->name, "size"))
		cube->size = ft_atof((char *)attr->children->content);
	if (!ft_strcmp((char*)attr->name, "materia_id"))
		cube->material_id = ft_atof((char *)attr->children->content);
	if (!ft_strcmp((char*)attr->name, "materia_id1"))
		cube->material_id1 = ft_atof((char *)attr->children->content);
	if (!ft_strcmp((char*)attr->name, "materia_id2"))
		cube->material_id2 = ft_atof((char *)attr->children->content);
	if (!ft_strcmp((char*)attr->name, "materia_id3"))
		cube->material_id3 = ft_atof((char *)attr->children->content);
	if (!ft_strcmp((char*)attr->name, "materia_id4"))
		cube->material_id4 = ft_atof((char *)attr->children->content);
	if (!ft_strcmp((char*)attr->name, "materia_id5"))
		cube->material_id5 = ft_atof((char *)attr->children->content);
}

void		ft_init_cube(void *obj, xmlNodePtr node, t_scene *scn)
{
	xmlNodePtr	child;
	xmlAttrPtr	attr;
	t_objects	*cube;

	cube = (t_objects*)obj;
	attr = node->properties;
	while (attr != NULL)
	{
		ft_init_cube_1(cube, attr);
		attr = attr->next;
	}
	child = node->children;
	ft_init_cube_2(cube, child);
	ft_init_tricube(cube, scn);
}
