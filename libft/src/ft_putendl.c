/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:57:26 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 20:57:29 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int count;

	count = 0;
	if (!s)
		return ;
	while (s[count] != '\0')
		ft_putchar(s[count++]);
	ft_putchar('\n');
}
