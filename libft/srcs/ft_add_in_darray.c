/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_in_darray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:28:40 by agoomany          #+#    #+#             */
/*   Updated: 2017/11/05 12:29:41 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int						ft_count(char **array)
{
	int							i;

	i = 0;
	if (array != NULL)
	{
		while (array[i] != NULL)
			i++;
	}
	return (i + 2);
}

static char						**ft_create_new(char **array)
{
	char						**ret;
	int							i;
	int							j;

	j = ft_count(array);
	if ((ret = (char **)malloc(sizeof(char *) * j)) == NULL)
		return (NULL);
	i = 0;
	while (i < j)
	{
		ret[i] = NULL;
		i++;
	}
	return (ret);
}

char							**ft_add_in_darray(char **array, char *str)
{
	char						**ret;
	int							i;
	char						*tmp;

	if ((ret = ft_create_new(array)) == NULL)
		return (NULL);
	i = 0;
	if (array != NULL)
	{
		while (array[i] != NULL)
		{
			ret[i] = ft_strdup(array[i]);
			i++;
		}
	}
	tmp = ft_strtrim(str);
	if (tmp == str)
		ret[i] = ft_strdup(str);
	else
		ret[i] = tmp;
	ft_free_darray(array);
	return (ret);
}
