/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 14:31:09 by agoomany          #+#    #+#             */
/*   Updated: 2018/04/28 14:31:12 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void					ft_vector_init(t_vector *vec)
{
	vec->x = 0;
	vec->y = 0;
	vec->z = 0;
}
