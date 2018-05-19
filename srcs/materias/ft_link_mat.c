/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_mat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 14:13:07 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/14 11:43:20 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_texture		*ft_get_texture(t_texture *texture, int i)
{
	if (!texture || i == 0)
		return (NULL);
	while (texture)
	{
		if (texture->id == i)
			return (texture);
		texture = texture->next;
	}
	return (NULL);
}

t_materials		*ft_get_material(t_materials *material, int i)
{
	while (material)
	{
		if (material->material_id == i)
			return (material);
		material = material->next;
	}
	return (material);
}

void			ft_link_mat(t_texture *tex, t_materials *mat, t_objects *obj)
{
	while (obj)
	{
		obj->material = ft_get_material(mat, obj->material_id);
		if (obj->material == NULL)
		{
			ft_putstr_fd("Unknow material (", 2);
			ft_putnbr_fd(obj->material_id, 2);
			ft_perror(").", TRUE);
		}
		obj->material->texture = ft_get_texture(tex, obj->material->texture_id);
		obj->material->normal = ft_get_texture(tex, obj->material->normal_id);
		obj = obj->next;
	}
}
