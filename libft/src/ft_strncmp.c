/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:09:09 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:09:12 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				count;
	int				result;
	unsigned char	*t_s1;
	unsigned char	*t_s2;

	count = 0;
	result = 0;
	t_s1 = (unsigned char*)s1;
	t_s2 = (unsigned char*)s2;
	if ((int)n == 0)
		return (0);
	while (1)
	{
		result += (t_s1[count] - t_s2[count]);
		if (count >= ((int)n - 1))
			return (result);
		if (t_s1[count] == '\0' && t_s2[count] == '\0')
			return (result);
		if (t_s1[count] == t_s2[count])
			count++;
		else
			return (result);
	}
}
