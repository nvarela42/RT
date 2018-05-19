/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_ambiant.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:27:58 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/02 17:22:53 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				*ft_create_ambiant(t_scene *scene)
{
	t_ambiant		*tmp;

	if ((tmp = (t_ambiant*)malloc(sizeof(t_ambiant))) == NULL)
		ft_perror(NULL, TRUE);
	ft_color_init(&tmp->color);
	scene->ambiant = tmp;
	return ((void*)tmp);
}
