/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 22:51:56 by nvarela           #+#    #+#             */
/*   Updated: 2018/03/25 22:52:22 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_copy_hit(t_thread *th, t_hit tmp)
{
	th->hit.touch = tmp.touch;
	th->hit.object = tmp.object;
	th->hit.inter.x = tmp.inter.x;
	th->hit.inter.y = tmp.inter.y;
	th->hit.inter.z = tmp.inter.z;
	th->hit.normal.x = tmp.normal.x;
	th->hit.normal.y = tmp.normal.y;
	th->hit.normal.z = tmp.normal.z;
	th->hit.material = tmp.material;
}
