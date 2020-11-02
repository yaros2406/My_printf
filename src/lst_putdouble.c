/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_putdouble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:59:53 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 18:59:58 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	lst_putdouble_pos(t_pf *lst, long double numb, ULONG coef)
{
	while (((coef * BASE) < (ULONG)numb) && numb != 0)
	{
		coef *= BASE;
		EXPONENT++;
	}
	lst->ul_numb = (ULONG)numb / coef;
	lst->ful_numb = numb - (lst->ul_numb * coef);
	lst->fl_numb = numb - (ULONG)numb;
}

static void	lst_putdouble_neg(t_pf *lst, long double numb, ULONG coef)
{
	while (((ULONG)(coef * numb) <= 0) && numb != 0)
	{
		coef *= BASE;
		EXPONENT--;
	}
	lst->ul_numb = (ULONG)(numb * coef);
	lst->fl_numb = (numb * coef) - lst->ul_numb;
}

static void	lst_putdouble_main(t_pf *lst, long double numb)
{
	if (numb < 0)
	{
		numb = -numb;
		PSIGN = "-";
	}
	else if (numb >= 0 && SIGN == '+')
		PSIGN = "+";
	if (POINT == 0)
		STRICT = 6;
	if ((CONVERT == 'f' || CONVERT == 'F') || (CONVERT == 'g' &&
			STRICT >= ulen_base(numb, BASE)))
	{
		lst->ul_numb = (ULONG)numb;
		lst->fl_numb = numb - (ULONG)numb;
	}
	else if ((ULONG)numb > 0)
		lst_putdouble_pos(lst, numb, 1);
	else
		lst_putdouble_neg(lst, numb, 1);
	if (POINT == 0 && (CONVERT == 'e' || CONVERT == 'E'))
		STRICT = MAX(6, ABS(EXPONENT));
}

void		lst_putdouble(t_pf *lst)
{
	long double	numb;
	ULONG		*tab_nb;

	if (LENGTH == 100000)
		numb = va_arg(lst->va_copy, long double);
	else
		numb = (long double)va_arg(lst->va_copy, double);
	if ((1.0 / 0.0) == numb || (-1.0 / 0.0) == numb)
		put_buff(lst, (MAJOR == 1 ? "INF" : "inf"), 3, 0);
	else if (numb != numb)
		put_buff(lst, (MAJOR == 1 ? "NAN" : "nan"), 3, 0);
	else
	{
		lst_putdouble_main(lst, numb);
		if (!(tab_nb = (ULONG*)ft_memalloc(sizeof(ULONG) *
						(STRICT + 2 + ulen_base(lst->ul_numb, BASE)))))
			ERROR(lst, "lst_putdouble", 1);
		recast_double(lst, tab_nb, 0);
	}
}
