/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:30:24 by agoomany          #+#    #+#             */
/*   Updated: 2017/11/05 12:30:48 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	char	*str;
	size_t	i;

	len = ft_strlen(s1);
	if (n < len)
		len = n;
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = *s1++;
	return (str);
}
