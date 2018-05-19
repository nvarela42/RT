/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_darray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:29:03 by agoomany          #+#    #+#             */
/*   Updated: 2017/11/05 12:29:55 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_print_darray(char **array)
{
	int				i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_putendl_fd(array[i], 2);
		i++;
	}
}
