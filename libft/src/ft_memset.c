/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:55:47 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 20:55:51 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				count;
	unsigned char	*dest;

	count = 0;
	dest = b;
	while (len-- > 0)
		dest[count++] = (unsigned char)c;
	return (b);
}
