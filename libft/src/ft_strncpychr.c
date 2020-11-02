/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpychr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:09:52 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:09:57 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpychr(const char *s, int c)
{
	int count;
	int len;

	count = 0;
	len = ft_strlen(s);
	if (!s)
		return (NULL);
	while (s[count] != '\0' && s[count] != c)
		count++;
	if (s[count] == '\n')
		count++;
	if (count == len)
		return (NULL);
	return (ft_strsub(s, count, (len - count)));
}
