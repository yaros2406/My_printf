/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:54:26 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 20:54:29 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	int				count;
	unsigned char	*s2;

	count = 0;
	s2 = (unsigned char*)s;
	while (n-- > 0)
	{
		if (s2[count] == (unsigned char)c)
			return (s2 + count);
		else
			count++;
	}
	return (NULL);
}
