/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:04:57 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 19:05:02 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_createtab(int nb, char c)
{
	int		a;
	int		b;
	char	**tab;

	a = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (nb + 1))))
		return (NULL);
	while (a < nb)
	{
		b = 0;
		if (!(tab[a] = malloc(sizeof(char*) * (nb + 1))))
			return (NULL);
		while (b < nb)
			tab[a][b++] = c;
		tab[a][b] = '\0';
		a++;
	}
	tab[a] = NULL;
	return (tab);
}
