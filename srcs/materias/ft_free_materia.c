/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_materia.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 15:16:40 by agoomany          #+#    #+#             */
/*   Updated: 2018/04/08 15:18:59 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void					ft_free_materia(t_scene *scene)
{
	t_materials			*material;
	t_materials			*tmp;

	material = scene->materials;
	if (!material)
		return ;
	while (material)
	{
		tmp = material->next;
		free(material);
		material = tmp;
	}
	scene->materials = NULL;
}
