/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:10:16 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:10:19 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int count;

	count = 0;
	if (!s1 || (!s2 && n > 0))
		return (0);
	while (s1[count] != '\0' && s2[count] != '\0' && count < ((int)n - 1))
	{
		if (s1[count] == s2[count])
			count++;
		else
			return (0);
	}
	if (s1[count] == s2[count] || n == 0)
		return (1);
	else
		return (0);
}
