/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recast_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:18:56 by bshaquan          #+#    #+#             */
/*   Updated: 2020/01/16 18:20:55 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static UCHAR	*pf_convwchar(t_pf *lst, wchar_t wc)
{
	UCHAR	*new;
	size_t	a;

	if (!(new = (UCHAR*)malloc(len_wchar_single(wc) + 1)))
		ERROR(lst, "pf_convwchar", 1);
	a = 0;
	convert_wchar(&new, wc, &a);
	return (new);
}

static void		pf_putchar(t_pf *lst, UCHAR c, UCHAR *wc, int index)
{
	size_t max;

	if (index == 1)
		max = len_wuchart(wc);
	else
		max = 1;
	put_prefix(lst, max, FIELD, ZERO);
	put_buff(lst, (index == 1 ? wc : &c), max, index);
	put_prefix(lst, max, -FIELD, 0);
}

void			recast_char(t_pf *lst)
{
	UCHAR	*wc;
	size_t	verif;

	if (CONVERT != 'c' && CONVERT != 'C')
		pf_putchar(lst, CONVERT, 0, 0);
	else
	{
		verif = va_arg(lst->va_copy, int);
		if (verif > 127)
			wc = pf_convwchar(lst, verif);
		if (((LENGTH >= 10 && LENGTH <= 20) || CONVERT == 'C')
				&& verif > 127)
			pf_putchar(lst, 0, wc, 1);
		else
			pf_putchar(lst, (char)verif, 0, 0);
	}
}
