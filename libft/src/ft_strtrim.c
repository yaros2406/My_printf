/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:13:02 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:13:05 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_white(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	int		len;
	int		count;

	count = 0;
	if (!s)
		return (NULL);
	while (ft_find_white(s[count]) == 1 && s[count] != '\0')
		count++;
	len = ft_strlen(s);
	while (ft_find_white(s[len - 1]) == 1 && len > 0)
		len--;
	if (len == 0)
		len = 0;
	else
		len -= count;
	return (ft_strsub(s, count, len));
}
