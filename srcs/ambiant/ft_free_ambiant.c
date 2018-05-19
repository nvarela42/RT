/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ambiant.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 15:14:18 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/02 14:22:54 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void						ft_free_ambiant(t_scene *scene)
{
	t_ambiant				*ambiant;

	ambiant = scene->ambiant;
	if (!ambiant)
		return ;
	free(ambiant);
	scene->ambiant = NULL;
}
