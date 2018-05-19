/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_misc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 14:30:38 by agoomany          #+#    #+#             */
/*   Updated: 2018/04/28 14:30:46 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void					ft_vector_normalize(t_vector *vector)
{
	float			val;

	val = ft_vector_magnitude(vector);
	vector->x /= val;
	vector->y /= val;
	vector->z /= val;
}

float					ft_vector_magnitude(t_vector *vector)
{
	float				val;

	val = ft_vector_square_len(vector);
	return (sqrt(val));
}

float					ft_vector_square_len(t_vector *vector)
{
	float				val;

	val = (vector->x * vector->x);
	val += (vector->y * vector->y);
	val += (vector->z * vector->z);
	return (val);
}

float					ft_vector_dot_mult(t_vector *a, t_vector *b)
{
	float				val;

	val = (a->x * b->x);
	val += (a->y * b->y);
	val += (a->z * b->z);
	return (val);
}
