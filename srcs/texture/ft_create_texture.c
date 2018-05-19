/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontagn <vmontagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 00:00:26 by vmontagn          #+#    #+#             */
/*   Updated: 2018/05/11 19:21:47 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_texture		*ft_get_last_texture(t_scene *scene)
{
	t_texture			*current;

	current = scene->textures;
	if (current)
	{
		while (current->next)
			current = current->next;
	}
	return (current);
}

void					*ft_create_texture(t_scene *scene)
{
	t_texture			*tmp;
	t_texture			*current;

	if ((tmp = (t_texture*)malloc(sizeof(t_texture))) == NULL)
		ft_perror(NULL, TRUE);
	tmp->id = 0;
	tmp->type = 0;
	tmp->w = 0;
	tmp->h = 0;
	tmp->sh = 1;
	tmp->sw = 1;
	tmp->oh = 0;
	tmp->ow = 0;
	tmp->data = NULL;
	tmp->next = NULL;
	if ((current = ft_get_last_texture(scene)) == NULL)
		scene->textures = tmp;
	else
		current->next = tmp;
	return ((void*)tmp);
}
