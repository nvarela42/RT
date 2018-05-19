/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 11:51:48 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/14 12:07:52 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void				ft_copy_object_bis(t_objects *obj, t_objects *cur)
{
	ft_copy_vector(&cur->rotation, &obj->rotation);
	ft_copy_vector(&cur->normal, &obj->normal);
	ft_copy_vector(&cur->translation, &obj->translation);
	ft_copy_vector(&cur->edge_a, &obj->edge_a);
	ft_copy_vector(&cur->edge_b, &obj->edge_b);
	ft_copy_vector(&cur->edge_c, &obj->edge_c);
	ft_copy_vector(&cur->edge_d, &obj->edge_d);
	ft_copy_vector(&cur->edge_e, &obj->edge_e);
	ft_copy_vector(&cur->edge_f, &obj->edge_f);
	ft_copy_vector(&cur->edge_g, &obj->edge_g);
	ft_copy_vector(&cur->edge_h, &obj->edge_h);
	ft_copy_vector(&cur->pos_edge1, &obj->pos_edge1);
	ft_copy_vector(&cur->pos_edge2, &obj->pos_edge2);
	ft_copy_vector(&cur->pos_edge3, &obj->pos_edge3);
}

void					ft_copy_object(t_scene *tmp, t_scene *act)
{
	t_objects			*obj;
	t_objects			*cur;

	if ((cur = act->objects) == NULL)
		return ;
	while (cur)
	{
		obj = (t_objects*)ft_create_object(tmp);
		obj->type = cur->type;
		ft_copy_vector(&cur->pos, &obj->pos);
		obj->radius = cur->radius;
		obj->size = cur->size;
		obj->limit_pos = cur->limit_pos;
		obj->limit_neg = cur->limit_neg;
		ft_copy_object_bis(obj, cur);
		obj->material_id = cur->material_id;
		obj->material_id1 = cur->material_id1;
		obj->material_id2 = cur->material_id2;
		obj->material_id3 = cur->material_id3;
		obj->material_id4 = cur->material_id4;
		obj->material_id5 = cur->material_id5;
		obj->texture_id = cur->texture_id;
		cur = cur->next;
	}
}
