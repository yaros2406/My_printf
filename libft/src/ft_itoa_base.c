/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:51:08 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 20:51:11 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_cal(char *str, long n, int len, int base)
{
	if ((n % base) < 10)
		str[len--] = (char)(n % base) + 48;
	else
		str[len--] = (char)(n % base) + 55;
	while (n >= base)
	{
		n = n / base;
		if ((n % base) < 10)
			str[len--] = (char)(n % base) + 48;
		else
			str[len--] = (char)(n % base) + 55;
	}
	return (str);
}

char		*ft_itoa_base(int nb, int base)
{
	int		len;
	char	*str;
	long	n;

	n = (long)nb;
	if (base < 2 || base > 16)
		return (NULL);
	if (n < 0 && base != 10)
		n = -n;
	len = ft_intlen_base(n, base);
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	if (n < 0 && base == 10)
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
	return (ft_itoa_cal(str, n, len, base));
}
