/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 15:10:11 by agoomany          #+#    #+#             */
/*   Updated: 2018/04/08 15:38:53 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void					ft_free_object(t_scene *scene)
{
	t_objects			*obj;
	t_objects			*tmp;

	obj = scene->objects;
	if (!obj)
		return ;
	while (obj)
	{
		tmp = obj->next;
		free(obj);
		obj = tmp;
	}
	scene->objects = NULL;
}
