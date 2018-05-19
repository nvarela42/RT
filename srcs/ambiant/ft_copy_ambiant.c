/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_ambiant.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 20:25:05 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/13 20:25:44 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			ft_copy_ambiant(t_scene *tmp, t_scene *act)
{
	t_ambiant	*obj;

	if (act->ambiant == NULL)
		return ;
	obj = (t_ambiant*)ft_create_ambiant(tmp);
	ft_copy_color(&act->ambiant->color, &obj->color);
}
