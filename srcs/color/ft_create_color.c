/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 11:03:02 by agoomany          #+#    #+#             */
/*   Updated: 2018/04/28 11:03:09 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void					ft_create_color(t_color *color, xmlAttrPtr attr)
{
	while (attr != NULL)
	{
		if (attr->name[0] == 'r')
			color->r = ft_atof((char *)attr->children->content);
		if (attr->name[0] == 'g')
			color->g = ft_atof((char *)attr->children->content);
		if (attr->name[0] == 'b')
			color->b = ft_atof((char *)attr->children->content);
		attr = attr->next;
	}
}
