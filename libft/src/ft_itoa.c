/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:51:21 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 20:51:24 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_cal(char *str, int n, int len)
{
	str[len--] = (char)(n % 10) + '0';
	while (n > 9)
	{
		n = n / 10;
		str[len--] = (char)(n % 10) + '0';
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_intlen(n);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		if (n == -2147483648)
		{
			str[1] = '2';
			n = -147483648;
		}
		str[0] = '-';
		n = n * -1;
	}
	len--;
	return (ft_itoa_cal(str, n, len));
}
