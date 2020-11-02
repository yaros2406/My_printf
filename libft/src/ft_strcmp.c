/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:04:10 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:04:13 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				count;
	int				result;
	unsigned char	*t_s1;
	unsigned char	*t_s2;

	count = 0;
	result = 0;
	t_s1 = (unsigned char*)s1;
	t_s2 = (unsigned char*)s2;
	while (1)
	{
		result += (t_s1[count] - t_s2[count]);
		if (t_s1[count] == '\0' || t_s2[count] == '\0')
			return (result);
		if (t_s1[count] == t_s2[count])
			count++;
		else
			return (result);
	}
}
