/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 12:18:01 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/15 18:37:14 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void					ft_copy_texture(t_scene *tmp, t_scene *act)
{
	t_texture			*obj;
	t_texture			*cur;

	if ((cur = act->textures) == NULL)
		return ;
	while (cur)
	{
		obj = (t_texture*)ft_create_texture(tmp);
		obj->id = cur->id;
		obj->type = cur->type;
		obj->w = cur->w;
		obj->h = cur->h;
		obj->sw = cur->sw;
		obj->sh = cur->sh;
		obj->ow = cur->ow;
		obj->oh = cur->oh;
		obj->data = NULL;
		if (cur->data != NULL)
			obj->data = gdk_pixbuf_copy(cur->data);
		cur = cur->next;
	}
}
