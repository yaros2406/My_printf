/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:54:59 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 20:55:03 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*src2;
	unsigned char	*dest2;

	count = 0;
	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	while (count < n)
	{
		dest2[count] = src2[count];
		count++;
	}
	return (dest);
}
