/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:26:10 by agoomany          #+#    #+#             */
/*   Updated: 2018/04/14 15:28:20 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void					*ft_create_camera(t_scene *scene)
{
	t_camera			*tmp;

	if ((tmp = (t_camera*)malloc(sizeof(t_camera))) == NULL)
		ft_perror(NULL, TRUE);
	ft_vector_init(&tmp->pos);
	ft_vector_init(&tmp->lookat);
	ft_vector_init(&tmp->up);
	ft_vector_init(&tmp->dir);
	ft_vector_init(&tmp->right);
	ft_vector_init(&tmp->up_left);
	tmp->dist = 0;
	tmp->viewport_w = 0;
	tmp->viewport_h = 0;
	tmp->size_x = 0;
	tmp->size_y = 0;
	scene->camera = tmp;
	return ((void*)tmp);
}
