/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 20:26:05 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/15 16:35:25 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				ft_copy_camera(t_scene *tmp, t_scene *act)
{
	t_camera		*ret;
	t_camera		*cur;

	ret = NULL;
	ret = ft_create_camera(tmp);
	if ((cur = act->camera) == NULL)
		return ;
	ft_copy_vector(&cur->pos, &ret->pos);
	ft_copy_vector(&cur->lookat, &ret->lookat);
	ft_copy_vector(&cur->up, &ret->up);
	ft_copy_vector(&cur->sav_up, &ret->sav_up);
	ft_copy_vector(&cur->dir, &ret->dir);
	ft_copy_vector(&cur->right, &ret->right);
	ft_copy_vector(&cur->up_left, &ret->up_left);
	ret->dist = cur->dist;
	ret->viewport_w = cur->viewport_w;
	ret->viewport_h = cur->viewport_h;
	ret->size_x = cur->size_x;
	ret->size_y = cur->size_y;
	tmp->camera = ret;
}
