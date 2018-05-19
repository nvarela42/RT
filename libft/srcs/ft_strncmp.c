/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:30:23 by agoomany          #+#    #+#             */
/*   Updated: 2017/11/05 12:30:47 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2 || !n)
		return (0);
	while (n != 0)
	{
		if (*s1 != *s2)
		{
			if ((*(unsigned char *)s1 - *(unsigned char *)s2) > 0)
				return (1);
			else
				return (-1);
		}
		if (*s1 == 0)
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
