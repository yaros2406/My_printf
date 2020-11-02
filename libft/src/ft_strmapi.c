/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:08:25 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:08:28 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		new[count] = f(count, (char)s[count]);
		count++;
	}
	new[count] = '\0';
	return (new);
}
