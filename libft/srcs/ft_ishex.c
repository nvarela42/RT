/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:28:50 by agoomany          #+#    #+#             */
/*   Updated: 2017/11/05 12:29:50 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ishex(char *str)
{
	int	i;

	i = 2;
	if (ft_strlen(str) < 3 || (str[0] != '0' && str[2] != 'x'))
		return (0);
	while (str[i] != '\0')
	{
		if ((str[i] >= 48 && str[i] <= 57) || str[i] == 'a' || str[i] == 'A' ||
			str[i] == 'b' || str[i] == 'B' || str[i] == 'c' || str[i] == 'C' ||
			str[i] == 'd' || str[i] == 'D' || str[i] == 'e' || str[i] == 'E' ||
			str[i] == 'f' || str[i] == 'F')
			i++;
		else
			return (0);
	}
	return (1);
}
