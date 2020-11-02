/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:03:34 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:03:37 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		count;
	char	*dest;

	count = 0;
	dest = (char*)s;
	while (dest[count] != '\0')
	{
		if (dest[count] == (char)c)
			return (dest + count);
		count++;
	}
	if (dest[count] == (char)c)
		return (dest + count);
	return (NULL);
}
