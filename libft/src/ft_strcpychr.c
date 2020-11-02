/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpychr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:04:51 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:04:54 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpychr(const char *s, int c)
{
	int count;

	count = 0;
	if (!s)
		return (NULL);
	while (s[count] != '\0' && s[count] != c)
		count++;
	return (ft_strncpy(ft_strnew(count), s, count));
}
