/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:10:35 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:10:38 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new;

	if (size > 2147483647 || (int)size < 0)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(new, 0, size + 1);
	return (new);
}
