/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:05:52 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:05:57 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int count;

	count = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[count] != '\0' && s2[count] != '\0')
	{
		if (s1[count] == s2[count])
			count++;
		else
			return (0);
	}
	if (s1[count] == s2[count])
		return (1);
	else
		return (0);
}
