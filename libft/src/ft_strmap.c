/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:08:08 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:08:11 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		count;
	int		len;
	char	*new;

	count = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[count] != '\0')
	{
		new[count] = f((char)s[count]);
		count++;
	}
	new[count] = '\0';
	return (new);
}
