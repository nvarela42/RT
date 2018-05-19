/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 14:30:53 by agoomany          #+#    #+#             */
/*   Updated: 2018/04/28 14:30:57 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void					ft_create_vector(t_vector *vec, xmlAttrPtr attr)
{
	while (attr != NULL)
	{
		if (attr->name[0] == 'x')
			vec->x = ft_atof((char *)attr->children->content);
		if (attr->name[0] == 'y')
			vec->y = ft_atof((char *)attr->children->content);
		if (attr->name[0] == 'z')
			vec->z = ft_atof((char *)attr->children->content);
		attr = attr->next;
	}
}
