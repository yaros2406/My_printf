/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:08:45 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:08:48 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t count_s1;
	size_t count_s2;

	count_s1 = 0;
	count_s2 = 0;
	while (s1[count_s1] != '\0')
		count_s1++;
	while (s2[count_s2] != '\0' && count_s2 < n)
	{
		s1[count_s1] = s2[count_s2];
		count_s1++;
		count_s2++;
	}
	s1[count_s1] = '\0';
	return (s1);
}
