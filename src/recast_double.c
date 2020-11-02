/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recast_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:21:13 by bshaquan          #+#    #+#             */
/*   Updated: 2020/01/16 18:21:20 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	vanish_zero(t_pf *lst, ULONG *numb, int i, size_t index)
{
	if ((CONVERT == 'g' || CONVERT == 'G') && (index == 1 || index == 3))
	{
		while (i < STRICT)
		{
			if (numb[i] == 0)
				STRICT++;
			else
				break ;
			i++;
		}
	}
	if ((CONVERT == 'g' || CONVERT == 'G') && (index == 2 || index == 3))
	{
		i = STRICT;
		while (i > 1)
		{
			if (numb[i] == 0)
				STRICT--;
			else
				break ;
			i--;
		}
	}
}

static void	roundup_double(t_pf *lst, ULONG *numb, int i, int max)
{
	vanish_zero(lst, numb, 1, 3);
	i = STRICT + 1;
	max = STRICT + 1;
	while (i > 0)
	{
		if ((numb[i] >= (BASE / 2) && i == max) ||
			(numb[i] >= BASE && i > 0))
		{
			numb[i - 1] += 1;
			numb[i] = numb[i] % BASE;
		}
		i--;
	}
	vanish_zero(lst, numb, 1, 2);
}

static void	assume_double(t_pf *lst, ULONG *numb, size_t i, int j)
{
	int		strict;
	size_t	verif;

	strict = STRICT + 1;
	numb[i++] = lst->ul_numb;
	verif = 0;
	j = (lst->ful_numb != 0 ? ulen_base(lst->ful_numb, BASE) : 0);
	i += j;
	while (j > 0)
	{
		numb[j--] = lst->ful_numb % BASE;
		lst->ful_numb /= BASE;
	}
	while (strict > 0)
	{
		lst->fl_numb *= BASE;
		numb[i++] = (int)lst->fl_numb;
		lst->fl_numb -= (int)lst->fl_numb;
		strict--;
	}
	roundup_double(lst, numb, 0, 0);
}

static int	max_calc(t_pf *lst, int max)
{
	if (SPACE == 1 && SIGN != '+' && ft_strlen(PSIGN) == 0)
	{
		put_prefix(lst, 0, 1, 0);
		if (FIELD > 0)
			FIELD--;
		else if (FIELD < 0)
			FIELD++;
	}
	max = ulen_base(lst->ul_numb, BASE) + STRICT;
	max += ft_strlen(PSIGN);
	if (!((CONVERT == 'g' || CONVERT == 'G') && STRICT == 0))
		max += ((POINT == 0 || STRICT > 0) ? 1 : 0);
	if (CONVERT == 'e' || CONVERT == 'E' ||
			((CONVERT == 'g' || CONVERT == 'G') &&
			STRICT != 0 && (EXPONENT < -4 || EXPONENT >= STRICT)))
		max += 2 + MAX(ulen_base(ABS(EXPONENT), BASE), 2);
	return (max);
}

void		recast_double(t_pf *lst, ULONG *numb, int i)
{
	unsigned char	*new;
	int				max;

	max = 0;
	if ((CONVERT == 'g' || CONVERT == 'G') && POINT == 0)
		lst->strict -= ulen_base(lst->ul_numb, BASE);
	assume_double(lst, numb, 0, 0);
	max = max_calc(lst, 0);
	if (ZERO == 1)
		put_buff(lst, PSIGN, ft_strlen(PSIGN), 0);
	put_prefix(lst, max, FIELD, ZERO);
	if (ZERO == 0)
		put_buff(lst, PSIGN, ft_strlen(PSIGN), 0);
	put_itoa(lst, numb[i++]);
	if (STRICT > 0)
		put_buff(lst, ".", 1, 0);
	while ((i - 1) < STRICT)
		put_itoa(lst, numb[i++]);
	if (CONVERT == 'e' || CONVERT == 'E' || ((CONVERT == 'g' ||
					CONVERT == 'G') &&
				STRICT != 0 && (EXPONENT < -4 || EXPONENT >= STRICT)))
	{
		i = ft_sprintf(&new, "%c%+.2d", (MAJOR == 1 ? 'E' : 'e'), EXPONENT);
		put_buff(lst, new, i, 1);
	}
}
