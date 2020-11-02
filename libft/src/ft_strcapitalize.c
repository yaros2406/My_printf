/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:02:51 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:02:55 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_alpha_test(char *str, int a)
{
	if (str[a - 1] >= 'A' && str[a - 1] <= 'Z')
		return (0);
	else if (str[a - 1] >= 'a' && str[a - 1] <= 'z')
		return (0);
	else if (str[a - 1] >= '0' && str[a - 1] <= '9')
		return (0);
	else
		return (1);
}

char			*ft_strcapitalize(char *str)
{
	int a;

	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] >= 'A' && str[a] <= 'Z')
			str[a] = str[a] + 32;
		a++;
	}
	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] >= 'a' && str[a] <= 'z')
			if (ft_alpha_test(str, a))
				str[a] = str[a] - 32;
		a++;
	}
	return (str);
}
