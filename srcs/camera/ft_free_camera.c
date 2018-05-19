/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 14:55:57 by agoomany          #+#    #+#             */
/*   Updated: 2018/04/28 11:02:54 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void					ft_free_camera(t_scene *scene)
{
	t_camera			*camera;

	camera = scene->camera;
	if (!camera)
		return ;
	free(camera);
	scene->camera = NULL;
}
