/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:29:02 by agoomany          #+#    #+#             */
/*   Updated: 2017/11/05 12:29:54 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_merge_array(char **array, int i, char *sep)
{
	int					size;
	char				*ret;
	char				*tmp;

	size = ft_size_darray(array);
	if (i > size || array[i] == NULL)
		return (NULL);
	ret = ft_strnew(0);
	while (array[i] != NULL)
	{
		tmp = ft_strdup(ret);
		free(ret);
		ret = ft_strjoin(tmp, array[i], 1);
		if (array[i + 1] != NULL)
		{
			tmp = ft_strdup(ret);
			free(ret);
			ret = ft_strjoin(tmp, sep, 1);
		}
		i++;
	}
	return (ret);
}
