/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:00:22 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:00:25 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_sort_integer_table(int *tab, int size)
{
	int a;
	int b;

	b = 0;
	a = size - 1;
	while (a != 0)
	{
		if (tab[a] > tab[a - 1])
		{
			b = tab[a];
			tab[a] = tab[a - 1];
			tab[a - 1] = b;
			a = size - 1;
		}
		else
			a--;
	}
}
