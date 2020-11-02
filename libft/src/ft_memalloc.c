/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:53:46 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 20:53:49 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mnew;

	if (size > 2147483647)
		return (NULL);
	if (!(mnew = (void*)malloc(sizeof(void) * size + 1)))
		return (NULL);
	ft_memset(mnew, 0, size);
	return (mnew);
}
