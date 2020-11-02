/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:59:14 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 20:59:18 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char const *s, int fd)
{
	int count;

	if (!s)
		return (-1);
	count = ft_strlen(s);
	write(fd, s, count);
	return (count);
}

int	ft_putnstr_fd(char const *s, int len, int fd)
{
	int count;

	if (!s)
		return (-1);
	count = ft_strnlen(s, len);
	write(fd, s, count);
	return (count);
}

int	ft_putstrw_fd(wchar_t const *s, int fd)
{
	int count;
	int len;

	count = 0;
	len = 0;
	if (!s)
		return (-1);
	while (s[count] != '\0')
		len += ft_putwchar_fd(s[count++], fd);
	return (len);
}

int	ft_putnstrw_fd(wchar_t const *s, int len, int fd)
{
	int count;
	int	len2;

	count = 0;
	len2 = 0;
	if (!s)
		return (-1);
	while (s[count] != '\0' && len2 < len)
		len2 += ft_putwchar_fd(s[count++], fd);
	return (len2);
}
