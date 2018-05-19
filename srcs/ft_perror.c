/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 11:37:38 by agoomany          #+#    #+#             */
/*   Updated: 2018/04/28 17:20:37 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void					ft_perror(char *str, t_bool exit_flag)
{
	if (str)
	{
		ft_putstr_fd("rt: ", 2);
		ft_putendl_fd(str, 2);
	}
	else
		perror("rt");
	if (exit_flag)
		exit(EXIT_FAILURE);
}
