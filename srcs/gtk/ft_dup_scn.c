/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_scn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 14:12:27 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 20:00:23 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			ft_create_new_scene_bis(t_rt *rt, t_scene *tmp)
{
	t_scene			*cur;

	tmp->perlin_permutation = ft_init_perlin();
	rt->progress.max = 0;
	rt->progress.current = 0;
	tmp->greyscale = 0;
	tmp->antialiasing = 0;
	tmp->sepia = 0;
	tmp->anaglyph = 0;
	tmp->cartoon = 0;
	tmp->motionblur = 0;
	tmp->deuteranopia = 0;
	tmp->protanopia = 0;
	tmp->tritanopia = 0;
	cur = rt->scenes;
	if (!cur)
		rt->scenes = tmp;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = tmp;
		tmp->prev = cur;
	}
}

void				ft_create_new_scene(t_rt *rt, t_scene *act)
{
	t_scene			*tmp;

	if ((tmp = (t_scene*)malloc(sizeof(t_scene))) == NULL)
		ft_perror(NULL, TRUE);
	tmp->scene = NULL;
	tmp->camera = NULL;
	tmp->objects = NULL;
	tmp->materials = NULL;
	tmp->textures = NULL;
	tmp->lights = NULL;
	tmp->ambiant = NULL;
	tmp->sel_obj = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	ft_copy_camera(tmp, act);
	ft_copy_object(tmp, act);
	ft_copy_materia(tmp, act);
	ft_copy_texture(tmp, act);
	ft_link_mat(tmp->textures, tmp->materials, tmp->objects);
	ft_copy_light(tmp, act);
	ft_copy_ambiant(tmp, act);
	ft_create_new_scene_bis(rt, tmp);
}

void				ft_dup_scn(gpointer data)
{
	t_scene			*scn;

	if (ft_can_create_scene(ft_glob()) == FALSE)
	{
		ft_print_error_xml(ft_glob(), "Can't open another scene.");
		return ;
	}
	scn = (t_scene*)data;
	ft_create_new_scene(ft_glob(), scn);
	ft_run(ft_glob());
}
