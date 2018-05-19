/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:30:25 by agoomany          #+#    #+#             */
/*   Updated: 2017/11/05 12:30:49 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	while (size > 0)
	{
		s[i] = '\0';
		i++;
		size--;
	}
	s[i] = '\0';
	return (s);
}
