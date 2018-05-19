/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_darray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:30:03 by agoomany          #+#    #+#             */
/*   Updated: 2017/11/05 12:30:37 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_size_darray(char **array)
{
	int			i;

	i = 0;
	if (array != NULL)
	{
		while (array[i] != NULL)
			i++;
	}
	return (i);
}
