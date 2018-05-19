/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:29:00 by agoomany          #+#    #+#             */
/*   Updated: 2017/11/05 12:29:53 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_char(long long n)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char		*ft_ltoa(long long n)
{
	char	*s;
	int		i;
	int		len;

	if ((long long)n < -9223372036854775807)
		return ("-9223372036854775808");
	i = 0;
	len = ft_count_char(n);
	s = (char *)malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return (NULL);
	s[len] = '\0';
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	while (n > 9)
	{
		s[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	s[len - 1] = n + '0';
	return (s);
}
