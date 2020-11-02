/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:05:47 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 19:05:53 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen_base(int nb, int base)
{
	if (nb < 0)
		nb = -nb;
	return (1 + (nb >= base ? ft_intlen_base(nb / base, base) : 0));
}

int	ft_intlen(int n)
{
	return (ft_intlen_base(n, 10));
}
