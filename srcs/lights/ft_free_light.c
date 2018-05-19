/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 15:14:18 by agoomany          #+#    #+#             */
/*   Updated: 2018/04/08 15:15:15 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void						ft_free_light(t_scene *scene)
{
	t_lights				*light;
	t_lights				*tmp;

	light = scene->lights;
	if (!light)
		return ;
	while (light)
	{
		tmp = light->next;
		free(light);
		light = tmp;
	}
	scene->lights = NULL;
}
