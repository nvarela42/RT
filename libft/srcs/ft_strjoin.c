/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:30:20 by agoomany          #+#    #+#             */
/*   Updated: 2017/11/05 12:30:45 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2, int free_m)
{
	char	*dst;

	dst = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 3);
	if (!dst)
		return (NULL);
	ft_strcpy(dst, s1);
	ft_strcat(dst, s2);
	if (free_m == 1)
		free((char *)s1);
	if (free_m == 2)
		free((char *)s2);
	if (free_m == 0)
	{
		free((char *)s1);
		free((char *)s2);
	}
	return (dst);
}
