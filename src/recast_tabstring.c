/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recast_tabstring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 18:22:44 by bshaquan          #+#    #+#             */
/*   Updated: 2020/01/16 18:22:48 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_puttab_back(t_pf *lst, int len, int b)
{
	int			llen;
	int			ret;
	UCHAR		*str;

	llen = ulen_base(len, 10) + STRICT;
	llen -= (((len % 10) == 0) ? 1 : 0);
	if (STRICT == 1)
	{
		ret = ft_sprintf(&str, " %{T_BLUE}%*s%{T_EOC} |", llen, "\\0");
		put_buff(lst, str, ret, 1);
	}
	while ((b + STRICT) < len)
	{
		ret = ft_sprintf(&str, " %*C |", llen, ' ');
		put_buff(lst, str, ret, 1);
		b++;
	}
}

static void	pf_puttab_end(t_pf *lst, int larg, int max)
{
	UCHAR	*str;
	int		ret;

	if (STRICT == 1)
	{
		ret = ft_sprintf(&str, "\n[%.*d]| %{T_BLUE}$NULL%{T_EOC}", larg, max);
		put_buff(lst, str, ret, 1);
	}
}

static void	pf_puttab(t_pf *lst, char **tab, int len, int larg)
{
	UCHAR		*str;
	int			llen;
	int			a;
	int			b;
	int			ret;

	llen = ulen_base(len, 10) + STRICT;
	llen -= (((len % 10) == 0) ? 1 : 0);
	a = 0;
	while (tab[a] != NULL)
	{
		b = 0;
		ret = ft_sprintf(&str, "\n[%.*d]|", larg, a);
		put_buff(lst, str, ret, 1);
		while (tab[a][b] != '\0')
		{
			ret = ft_sprintf(&str, " %*C |", llen, tab[a][b]);
			put_buff(lst, str, ret, 1);
			b++;
		}
		pf_puttab_back(lst, len, b);
		a++;
	}
	pf_puttab_end(lst, larg, ft_maxlen_tab(tab, 0));
}

static void	pf_doublestring(t_pf *lst, char **tab, int len, int larg)
{
	UCHAR		*str;
	int			b;
	int			ret;
	int			llen;

	b = 0;
	len = ft_maxlen_tab(tab, 1) + STRICT;
	larg = ft_maxlen_tab(tab, 0);
	larg = ulen_base(MIN(larg - 1, larg), 10);
	llen = ulen_base(len, 10) + STRICT;
	llen -= (((len % 10) == 0) ? 1 : 0);
	ret = ft_sprintf(&str, "%*.c |", larg + 1, ' ');
	put_buff(lst, str, ret, 1);
	while (b < len)
	{
		ret = ft_sprintf(&str, "[%.*d]|", llen, b++);
		put_buff(lst, str, ret, 1);
	}
	pf_puttab(lst, tab, len, larg);
}

int			recast_tabstring(t_pf *lst)
{
	char		**tab;
	UCHAR		c;

	tab = va_arg(lst->va_copy, char**);
	c = '\n';
	if (tab == NULL)
		put_buff(lst, "tab (null)", 1, 0);
	else
	{
		if (POINT == 1)
			pf_doublestring(lst, tab, 0, 0);
		else
		{
			while (*tab != NULL && POINT == 0)
			{
				put_buff(lst, (UCHAR*)*tab, ft_strlen(*tab), 0);
				if (*tab++ != NULL)
					put_buff(lst, &c, 1, 0);
			}
		}
	}
	return (1);
}
