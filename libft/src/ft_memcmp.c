/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:54:42 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 20:54:45 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	count;
	unsigned char	*s1_b;
	unsigned char	*s2_b;

	count = 0;
	s1_b = (unsigned char*)s1;
	s2_b = (unsigned char*)s2;
	while (n-- > 0)
	{
		if (s1_b[count] != s2_b[count])
			return ((s1_b[count] - s2_b[count]));
		count++;
	}
	return (0);
}
