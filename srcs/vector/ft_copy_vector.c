/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontagn <vmontagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 11:29:42 by vmontagn          #+#    #+#             */
/*   Updated: 2018/05/14 11:29:53 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void					ft_copy_vector(t_vector *src, t_vector *dest)
{
	dest->x = src->x;
	dest->y = src->y;
	dest->z = src->z;
}
