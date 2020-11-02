/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:55:17 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 20:55:20 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	int count;

	count = 0;
	if (!ap)
		return ;
	while (ap[count])
	{
		free(ap[count]);
		ap[count] = NULL;
	}
}
