/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recast_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:21:31 by bshaquan          #+#    #+#             */
/*   Updated: 2020/01/16 18:21:37 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	lst_putnb_unb(t_pf *lst)
{
	if (LENGTH == 1 && CONVERT != 'O' && CONVERT != 'U'
			&& CONVERT != 'D')
		lst->ul_numb = (unsigned short)va_arg(lst->va_copy, ULONG);
	else if (LENGTH == 2 && CONVERT != 'O' && CONVERT != 'U'
			&& CONVERT != 'D')
		lst->ul_numb = (unsigned char)va_arg(lst->va_copy, ULONG);
	else if (LENGTH == 10)
		lst->ul_numb = va_arg(lst->va_copy, long);
	else if (LENGTH == 20)
		lst->ul_numb = va_arg(lst->va_copy, ULONG);
	else if (LENGTH == 100)
		lst->ul_numb = va_arg(lst->va_copy, intmax_t);
	else if (LENGTH == 1000)
		lst->ul_numb = va_arg(lst->va_copy, size_t);
	else if (CONVERT == 'o' || CONVERT == 'x' || CONVERT == 'X' ||
			CONVERT == 'u' || CONVERT == 'X')
		lst->ul_numb = va_arg(lst->va_copy, unsigned int);
	else
		lst->ul_numb = va_arg(lst->va_copy, ULONG);
	if (SIGN == '+' && (CONVERT == 'd' || CONVERT == 'D' ||
				CONVERT == 'I' || CONVERT == 'i'))
		PSIGN = "+";
}

static void	lst_putnb_snb(t_pf *lst)
{
	long nb_tmp;

	if (LENGTH == 1)
		nb_tmp = (short)va_arg(lst->va_copy, int);
	else if (LENGTH == 2)
		nb_tmp = (char)va_arg(lst->va_copy, int);
	else if (LENGTH == 10)
		nb_tmp = va_arg(lst->va_copy, long);
	else if (LENGTH == 20)
		nb_tmp = va_arg(lst->va_copy, long);
	else if (LENGTH == 100)
		nb_tmp = va_arg(lst->va_copy, intmax_t);
	else if (LENGTH == 1000)
		nb_tmp = va_arg(lst->va_copy, size_t);
	else if (CONVERT == 'D' || CONVERT == 'I' || LENGTH != 0)
		nb_tmp = va_arg(lst->va_copy, long);
	else
		nb_tmp = va_arg(lst->va_copy, int);
	PSIGN = (nb_tmp < 0 ? "-" : "");
	if (SIGN == '+' && nb_tmp >= 0 && (CONVERT == 'd' ||
				CONVERT == 'D' || CONVERT == 'I' || CONVERT == 'i'))
		PSIGN = "+";
	lst->ul_numb = (nb_tmp < 0 ? -nb_tmp : nb_tmp);
}

void		lst_putint(t_pf *lst)
{
	if (CONVERT == 'd' || (CONVERT == 'i') ||
			(CONVERT == 'D' && LENGTH == 0))
		lst_putnb_snb(lst);
	else
		lst_putnb_unb(lst);
	if (CONVERT == 'p' || ((CONVERT == 'x' || CONVERT == 'X')
				&& HASH == 1 && lst->ul_numb != 0))
		PSIGN = (MAJOR == 1 ? "0X" : "0x");
}

static void	ft_spacecalc(t_pf *lst, int len)
{
	if ((HASH == 1 && (CONVERT == 'o' || CONVERT == 'O')) &&
		!((lst->ul_numb == 0 && POINT == 1 && STRICT > 0) ||
			(POINT == 0 && lst->ul_numb == 0)))
	{
		HASH = 1;
		if ((POINT == 1 && STRICT > len))
			STRICT = (STRICT != 0 ? STRICT - 1 : STRICT);
		if (FIELD < 0)
			FIELD++;
	}
	else
		HASH = 0;
	if (POINT == 1 && STRICT >= 0)
		ZERO = 0;
	if (SPACE == 1 && SIGN != '+' && ft_strlen(PSIGN) == 0
			&& CONVERT != 'u' && CONVERT != 'U')
	{
		put_prefix(lst, 0, 1, 0);
		if (FIELD > 0)
			FIELD--;
		else if (FIELD < 0)
			FIELD++;
	}
}

void		recast_int(t_pf *lst)
{
	int len;
	int max;

	lst_putint(lst);
	len = ulen_base(lst->ul_numb, BASE);
	if (lst->ul_numb == 0 && POINT == 1 && STRICT == 0)
		len = 0;
	ft_spacecalc(lst, len);
	max = MAX(len, STRICT) + ft_strlen(PSIGN);
	if (ZERO == 1)
		put_buff(lst, PSIGN, ft_strlen(PSIGN), 0);
	put_prefix(lst, max + HASH, FIELD, ZERO);
	if (ZERO == 0)
		put_buff(lst, PSIGN, ft_strlen(PSIGN), 0);
	put_prefix(lst, 0, HASH, 1);
	put_prefix(lst, len, STRICT, 1);
	if (!(POINT == 1 && STRICT == 0 && lst->ul_numb == 0))
		put_itoa(lst, lst->ul_numb);
	put_prefix(lst, max, -FIELD, 0);
}
