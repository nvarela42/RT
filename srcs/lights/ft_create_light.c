/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:27:58 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 03:44:46 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_lights		*ft_get_last_light(t_scene *scene)
{
	t_lights		*current;

	current = scene->lights;
	if (current)
	{
		while (current->next)
			current = current->next;
	}
	return (current);
}

void				*ft_create_light(t_scene *scene)
{
	t_lights		*tmp;
	t_lights		*current;

	if ((tmp = (t_lights*)malloc(sizeof(t_lights))) == NULL)
		ft_perror(NULL, TRUE);
	ft_vector_init(&tmp->pos);
	ft_color_init(&tmp->light_color);
	tmp->radius = 0;
	tmp->spot = 0;
	tmp->next = NULL;
	tmp->rad_spot = 0;
	tmp->intensity = 0;
	if ((current = ft_get_last_light(scene)) == NULL)
		scene->lights = tmp;
	else
		current->next = tmp;
	return ((void*)tmp);
}
