/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_on_vector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 14:29:53 by agoomany          #+#    #+#             */
/*   Updated: 2018/04/28 14:29:57 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				ft_div_vector(t_vector *dest, t_vector *vector, float val)
{
	dest->x = vector->x / val;
	dest->y = vector->y / val;
	dest->z = vector->z / val;
}

void				ft_mult_num_vector(t_vector *dest, t_vector *a, int i)
{
	dest->x = a->x * i;
	dest->y = a->y * i;
	dest->z = a->z * i;
}

void				ft_plus_vector(t_vector *dest, t_vector *a, t_vector *b)
{
	dest->x = a->x + b->x;
	dest->y = a->y + b->y;
	dest->z = a->z + b->z;
}

void				ft_mult_vector(t_vector *dest, t_vector *a, t_vector *b)
{
	dest->x = (a->y * b->z) - (a->z * b->y);
	dest->y = (a->z * b->x) - (a->x * b->z);
	dest->z = (a->x * b->y) - (a->y * b->x);
}

void				ft_moins_vector(t_vector *dest, t_vector *a, t_vector *b)
{
	dest->x = a->x - b->x;
	dest->y = a->y - b->y;
	dest->z = a->z - b->z;
}
