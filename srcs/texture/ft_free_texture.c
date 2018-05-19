/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontagn <vmontagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 10:44:35 by vmontagn          #+#    #+#             */
/*   Updated: 2018/05/11 17:21:29 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_free_texture(t_scene *scene)
{
	t_texture			*texture;
	t_texture			*tmp;

	texture = scene->textures;
	if (!texture)
		return ;
	while (texture)
	{
		tmp = texture->next;
		if (texture->data != NULL)
			g_object_unref(texture->data);
		free(texture);
		texture = tmp;
	}
	scene->textures = NULL;
}
