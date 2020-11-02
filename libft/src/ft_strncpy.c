/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:09:32 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:09:35 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int count;

	count = 0;
	while (src[count] != '\0' && count < (int)len)
	{
		dst[count] = (char)src[count];
		count++;
	}
	while (count < (int)len)
		dst[count++] = '\0';
	return (dst);
}
