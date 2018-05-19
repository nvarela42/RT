/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_hit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 07:07:37 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/14 14:51:23 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vector		ft_calc_pix_dir(t_camera *cam, int x, int y)
{
	t_vector		tmp;
	float			indent_x;
	float			indent_y;

	indent_x = cam->viewport_w / (float)cam->size_x;
	indent_y = cam->viewport_h / (float)cam->size_y;
	tmp.x = (cam->up_left.x + cam->right.x * indent_x * x -
			cam->up.x * indent_y * y) - cam->pos.x;
	tmp.y = (cam->up_left.y + cam->right.y * indent_x * x -
			cam->up.y * indent_y * y) - cam->pos.y;
	tmp.z = (cam->up_left.z + cam->right.z * indent_x * x -
			cam->up.z * indent_y * y) - cam->pos.z;
	return (tmp);
}

void				ft_init_ray(t_scene *scn, t_ray *ray, int x, int y)
{
	t_vector		pix_dir;

	pix_dir = ft_calc_pix_dir(scn->camera, x, y);
	ray->dir.x = pix_dir.x;
	ray->dir.y = pix_dir.y;
	ray->dir.z = pix_dir.z;
	ft_vector_normalize(&ray->dir);
	ray->dist = DEFAULT_DISTANCE;
}

void				ft_search_hit(t_thread *th, t_ray *ray)
{
	t_objects		*obj;
	t_scene			*scn;

	scn = th->scn;
	th->hit.touch = 0;
	if (th->keep_hit == 0)
		th->hit.object = NULL;
	ft_vector_init(&th->hit.inter);
	ft_vector_init(&th->hit.normal);
	obj = scn->objects;
	while (obj)
	{
		(*ft_glob()->object_calc[obj->type])(th, obj, ray);
		obj = obj->next;
	}
	if (th->keep_hit == 1 && ray->dist == DEFAULT_DISTANCE)
		th->hit.touch = 0;
	th->keep_hit = 0;
}
