/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:05:25 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:05:28 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *s1)
{
	int		len;
	int		count;
	char	*dest;

	len = ft_strlen(s1);
	count = 0;
	if (!(dest = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s1[count] != '\0')
	{
		dest[count] = s1[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

unsigned char	*ft_ustrdup(unsigned char *s1)
{
	unsigned char	*dest;
	int				len;
	int				count;

	len = ft_ustrlen(s1);
	count = 0;
	if (!(dest = (unsigned char *)malloc(sizeof(unsigned char) * len + 1)))
		return (NULL);
	while (s1[count] != '\0')
	{
		dest[count] = s1[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

unsigned char	*ft_strudup(char *s1)
{
	unsigned char	*dest;
	int				len;
	int				count;

	len = ft_strlen(s1);
	count = 0;
	if (!(dest = (unsigned char *)malloc(sizeof(unsigned char) * len + 1)))
		return (NULL);
	while (s1[count] != '\0')
	{
		dest[count] = s1[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
