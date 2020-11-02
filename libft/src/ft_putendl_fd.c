/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:57:05 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 20:57:08 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int count;

	count = 0;
	if (!s)
		return ;
	while (s[count] != '\0')
		ft_putchar_fd(s[count++], fd);
	ft_putchar_fd('\n', fd);
}
