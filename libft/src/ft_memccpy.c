/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:54:02 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 20:54:05 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				count;

	count = 0;
	while (n-- > 0)
	{
		((unsigned char*)dest)[count] = ((unsigned char*)src)[count];
		if (((unsigned char*)src)[count] == (unsigned char)c)
			return (dest + count + 1);
		count++;
	}
	return (NULL);
}
