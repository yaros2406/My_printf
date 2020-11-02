/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:02:08 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:02:11 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_printable(char *str)
{
	int a;

	a = 0;
	while (str[a] != '\0')
	{
		if (ft_isprint(str[a]))
			a++;
		else
			return (0);
	}
	return (1);
}
