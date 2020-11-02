/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:04:31 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:04:34 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int count;

	count = 0;
	while (src[count] != '\0')
	{
		dst[count] = (char)src[count];
		count++;
	}
	dst[count] = '\0';
	return (dst);
}
