/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:11:13 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:11:16 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		locat;
	int		locat_on;
	int		count;
	char	*dest;

	locat = 0;
	locat_on = 0;
	count = 0;
	dest = (char*)s;
	while (dest[count] != '\0')
	{
		if (dest[count] == (char)c)
		{
			locat = count;
			locat_on = 1;
		}
		count++;
	}
	if (dest[count] == (char)c)
		return (dest + count);
	if (locat_on == 1)
		return (dest + locat);
	return (NULL);
}
