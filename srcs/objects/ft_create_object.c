/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 15:01:43 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/07 14:04:38 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void				ft_init_edges_and_pos(t_objects *tmp)
{
	ft_vector_init(&tmp->edge_a);
	ft_vector_init(&tmp->edge_b);
	ft_vector_init(&tmp->edge_c);
	ft_vector_init(&tmp->edge_d);
	ft_vector_init(&tmp->edge_e);
	ft_vector_init(&tmp->edge_f);
	ft_vector_init(&tmp->edge_g);
	ft_vector_init(&tmp->edge_h);
	ft_vector_init(&tmp->pos_edge1);
	ft_vector_init(&tmp->pos_edge2);
	ft_vector_init(&tmp->pos_edge3);
}

static void				ft_init_material_id(t_objects *tmp)
{
	tmp->material_id = 0;
	tmp->material_id1 = 0;
	tmp->material_id2 = 0;
	tmp->material_id3 = 0;
	tmp->material_id4 = 0;
	tmp->material_id5 = 0;
}

static t_objects		*ft_get_last_object(t_scene *scene)
{
	t_objects			*current;

	current = scene->objects;
	if (current)
	{
		while (current->next)
			current = current->next;
	}
	return (current);
}

void					*ft_create_object(t_scene *scene)
{
	t_objects			*tmp;
	t_objects			*current;

	if ((tmp = (t_objects*)malloc(sizeof(t_objects))) == NULL)
		ft_perror(NULL, TRUE);
	tmp->type = 0;
	ft_vector_init(&tmp->pos);
	tmp->radius = 0;
	tmp->size = 0;
	tmp->tri_cube = NULL;
	tmp->limit_pos = 0;
	tmp->limit_neg = 0;
	ft_vector_init(&tmp->rotation);
	ft_vector_init(&tmp->normal);
	ft_vector_init(&tmp->translation);
	ft_init_edges_and_pos(tmp);
	ft_init_material_id(tmp);
	tmp->material = NULL;
	tmp->next = NULL;
	if ((current = ft_get_last_object(scene)) == NULL)
		scene->objects = tmp;
	else
		current->next = tmp;
	return ((void*)tmp);
}
