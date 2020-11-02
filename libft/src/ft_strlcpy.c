/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:07:20 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:07:23 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t a;

	a = 0;
	if (!dest || !src)
		return (0);
	while (src[a] != '\0' && size > 1)
	{
		dest[a] = src[a];
		a++;
		size--;
	}
	if (size > 0)
		dest[a] = '\0';
	return (ft_strlen(src));
}
