/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:10:54 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:10:57 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int count;
	int count2;

	count = 0;
	count2 = 0;
	while (haystack[count] != '\0' && count < (int)len)
	{
		while (haystack[count + count2] == needle[count2] &&
				haystack[count + count2] != '\0' && (count + count2) < (int)len)
			count2++;
		if (needle[count2] == '\0')
			return ((char*)haystack + count);
		count++;
		count2 = 0;
	}
	return (NULL);
}
