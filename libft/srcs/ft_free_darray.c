/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_darray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:28:47 by agoomany          #+#    #+#             */
/*   Updated: 2017/11/05 12:29:48 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_darray(char **array)
{
	int			i;

	if (array != NULL)
	{
		i = 0;
		while (array[i] != NULL)
		{
			free(array[i]);
			array[i] = NULL;
			i++;
		}
		free(array);
	}
}
