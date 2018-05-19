/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:28:53 by agoomany          #+#    #+#             */
/*   Updated: 2017/11/05 12:29:52 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*test(char *ret, long n, int len)
{
	int		size;
	int		nbr;
	int		tmp;

	size = 1;
	tmp = n;
	while (tmp / 10 > 0)
	{
		size = size * 10;
		tmp = tmp / 10;
	}
	while (size > 0)
	{
		nbr = 0;
		nbr = n / size;
		ret[len] = ('0' + nbr);
		len += 1;
		n = n % size;
		size = size / 10;
	}
	ret[len] = '\0';
	return (ret);
}

static int	ret_count(int n, int count)
{
	while (n / 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	int		len;
	int		i;
	int		count;
	char	*ret;

	if (n == -2147483648)
		return ("-2147483648");
	i = n;
	count = 0;
	if (n < 0)
		count += 1;
	count = ret_count(n, count);
	if ((ret = (char *)malloc(sizeof(*ret) * (count + 1) + 1)) == NULL)
		return (NULL);
	len = 0;
	if (i < 0)
	{
		ret[len] = '-';
		len += 1;
		i = i * -1;
	}
	return (test(ret, i, len));
}
