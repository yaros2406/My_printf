/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:03:15 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:03:18 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int count_s1;
	int count_s2;

	count_s1 = 0;
	count_s2 = 0;
	while (s1[count_s1] != '\0')
		count_s1++;
	while (s2[count_s2] != '\0')
	{
		s1[count_s1] = s2[count_s2];
		count_s1++;
		count_s2++;
	}
	s1[count_s1] = '\0';
	return (s1);
}
