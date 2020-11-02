/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:59:41 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 18:59:46 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	lst_zero(t_pf *lst)
{
	lst->ul_numb = 0;
	lst->ful_numb = 0;
	lst->fl_numb = 0;
	lst->exponent = 0;
	lst->hash = 0;
	lst->space = 0;
	lst->zero = 0;
	lst->sign = 0;
	lst->local = 0;
	lst->field = 0;
	lst->point = 0;
	lst->strict = 0;
	lst->major = 0;
	lst->psign = "";
	lst->base = 0;
	lst->length = 0;
	lst->convert = 0;
}

t_pf	*lst_init(void)
{
	t_pf *lst;

	if (!(lst = (t_pf*)malloc(sizeof(t_pf))))
		ERROR(lst, "lst_init", 1);
	lst->count = 0;
	lst->buff_count = 0;
	lst->str = NULL;
	return (lst);
}

void	lst_putdollar(t_pf *lst, int len)
{
	va_end(lst->va_copy);
	va_copy(lst->va_copy, lst->va_lst);
	while (--len > 0)
		va_arg(lst->va_copy, int);
}
