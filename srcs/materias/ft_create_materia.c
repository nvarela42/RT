/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_materia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:28:44 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/11 18:01:16 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_materials		*ft_get_last_materia(t_scene *scene)
{
	t_materials			*current;

	current = scene->materials;
	if (current)
	{
		while (current->next)
			current = current->next;
	}
	return (current);
}

void					*ft_create_materia(t_scene *scene)
{
	t_materials			*tmp;
	t_materials			*current;

	if ((tmp = (t_materials*)malloc(sizeof(t_materials))) == NULL)
		ft_perror(NULL, TRUE);
	ft_color_init(&tmp->material_color);
	tmp->shiness = 0;
	tmp->next = NULL;
	tmp->material_id = 0;
	tmp->reflect = 0;
	tmp->refract = 0;
	tmp->texture_id = 0;
	tmp->normal_id = 0;
	tmp->texture = NULL;
	tmp->normal = NULL;
	tmp->bump = 0;
	if ((current = ft_get_last_materia(scene)) == NULL)
		scene->materials = tmp;
	else
		current->next = tmp;
	return ((void*)tmp);
}
