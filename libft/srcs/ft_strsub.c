/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:30:29 by agoomany          #+#    #+#             */
/*   Updated: 2017/11/05 12:30:51 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*s_conv;
	int		i;

	if (s == NULL)
		return (0);
	str = ft_strnew(len);
	s_conv = (char *)s;
	i = 0;
	if (str)
	{
		while (len)
		{
			str[i] = s_conv[start + i];
			len--;
			i++;
		}
	}
	return (str);
}
