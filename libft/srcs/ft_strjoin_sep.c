/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:30:19 by agoomany          #+#    #+#             */
/*   Updated: 2017/11/05 12:30:44 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_sep(char const *s1, char const *s2, char const sep)
{
	char	*str;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	str = ft_strnew(s1_len + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	str[s1_len] = sep;
	ft_strcat(str, s2);
	return (str);
}
