/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:58:46 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 20:58:49 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putpstr_fd(char const *s, int fd)
{
	int count;

	count = 0;
	if (!s)
		return (-1);
	while (s[count] != '\0')
		ft_putpchar_fd(s[count++], fd);
	return (count);
}

int	ft_putpnstr_fd(char const *s, int len, int fd)
{
	int count;

	count = 0;
	if (!s)
		return (-1);
	while (s[count] != '\0' && count < len)
		ft_putpchar_fd(s[count++], fd);
	return (count);
}
