/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:12:13 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:12:16 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int count;
	int count2;

	count = 0;
	count2 = 0;
	if (haystack[count] == '\0' && needle[count2] == '\0')
		return ((char*)haystack);
	while (haystack[count] != '\0')
	{
		while (haystack[count + count2] == needle[count2] &&
				haystack[count + count2] != '\0')
			count2++;
		if (needle[count2] == '\0')
			return ((char*)haystack + count);
		count++;
		count2 = 0;
	}
	return (NULL);
}
