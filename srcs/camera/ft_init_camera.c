/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:26:47 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/11 20:46:19 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			ft_fill_camera_top_left(t_camera *camera)
{
	camera->up_left.x = camera->pos.x + ((camera->dir.x *
		camera->dist) + (camera->up.x * (camera->viewport_h / 2.0f))) -
		(camera->right.x * (camera->viewport_w / 2.0f));
	camera->up_left.y = camera->pos.y + ((camera->dir.y *
		camera->dist) + (camera->up.y * (camera->viewport_h / 2.0f))) -
		(camera->right.y * (camera->viewport_w / 2.0f));
	camera->up_left.z = camera->pos.z + ((camera->dir.z *
		camera->dist) + (camera->up.z * (camera->viewport_h / 2.0f))) -
		(camera->right.z * (camera->viewport_w / 2.0f));
}

static void			ft_init_camera_2(t_camera *cam)
{
	cam->dist = 1;
	cam->viewport_w = 0.50;
	cam->viewport_h = 0.35;
	ft_moins_vector(&cam->dir, &cam->lookat, &cam->pos);
	ft_vector_normalize(&cam->dir);
	ft_mult_vector(&cam->right, &cam->up, &cam->dir);
	ft_mult_vector(&cam->up, &cam->dir, &cam->right);
	cam->size_x = 1280;
	cam->size_y = 960;
	ft_fill_camera_top_left(cam);
}

void				ft_init_camera(void *obj, xmlNodePtr node, t_scene *scn)
{
	xmlAttrPtr		attr;
	xmlNodePtr		child;
	t_camera		*cam;

	(void)scn;
	cam = (t_camera*)obj;
	child = node->children;
	while (child != NULL)
	{
		attr = child->properties;
		if (!ft_strcmp("pos", (char*)child->name))
			ft_create_vector(&cam->pos, attr);
		if (!ft_strcmp("look_at", (char*)child->name))
			ft_create_vector(&cam->lookat, attr);
		if (!ft_strcmp("up", (char*)child->name))
		{
			ft_create_vector(&cam->up, attr);
			ft_create_vector(&cam->sav_up, attr);
		}
		child = child->next;
	}
	ft_init_camera_2(cam);
}
