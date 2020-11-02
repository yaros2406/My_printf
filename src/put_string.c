/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:00:52 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 19:00:57 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_buff(t_pf *lst, void *tmp, size_t len)
{
	UCHAR	*new;
	size_t	len_malloc;

	len_malloc = lst->count + lst->buff_count + len + 1;
	if ((new = (UCHAR*)ft_memalloc(len_malloc)) == NULL)
		ERROR(lst, "comvert_buff", 1);
	new[lst->count + lst->buff_count + len + 1] = '\0';
	ft_memcpy(new, lst->str, lst->count);
	ft_memcpy(new + lst->count, lst->buff, lst->buff_count);
	if (len > 0)
		ft_memcpy(new + lst->count + lst->buff_count, tmp, len);
	if (lst->str != NULL)
		free(lst->str);
	lst->str = new;
	lst->count += lst->buff_count + len;
	lst->buff_count = 0;
}

void	put_buff(t_pf *lst, void *tmp, size_t len, size_t index)
{
	if (len == 0)
		return ;
	if (((lst->buff_count + len) >= BUFF_PRINTF) || len >= BUFF_PRINTF)
		convert_buff(lst, tmp, len);
	else
	{
		ft_memcpy(lst->buff + lst->buff_count, tmp, len);
		lst->buff_count += len;
	}
	if (index == 1)
		free(tmp);
}

void	put_itoa(t_pf *lst, ULONG n)
{
	UCHAR		tmp[27];
	int			len;
	int			mlen;

	len = ulen_base(n, BASE);
	if (LOCAL == 1 && (len - 1) > 3)
		len += ((len / 3) - (len % 3 == 0 ? 1 : 0));
	mlen = len;
	len--;
	while (len >= 0)
	{
		if (LOCAL == 1 && ((mlen - len) % 4 == 0))
			tmp[len--] = ',';
		if ((n % BASE) < 10)
			tmp[len--] = (n % BASE) + 48;
		else
			tmp[len--] = (n % BASE) + (MAJOR == 1 ? 55 : 87);
		n = n / BASE;
	}
	put_buff(lst, tmp, mlen, 0);
}

void	put_prefix(t_pf *lst, int len, int numb, int point)
{
	size_t	llen;
	UCHAR	tmp[numb - len];

	llen = (numb - len);
	if (len >= numb)
		return ;
	if ((llen + lst->buff_count) >= BUFF_PRINTF)
	{
		ft_memset(tmp, (point == 1 ? '0' : ' '), llen);
		convert_buff(lst, tmp, llen);
	}
	else
	{
		ft_memset(lst->buff + lst->buff_count, (point == 1 ? '0' : ' '), llen);
		lst->buff_count += llen;
	}
}
