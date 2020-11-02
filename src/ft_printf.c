/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:59:19 by bshaquan          #+#    #+#             */
/*   Updated: 2020/01/15 20:53:01 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_conv(t_pf *lst, char *str, int ret)
{
	ret = lst_putoption(lst, str, 1);
	if (CONVERT == 'n')
		recast_nlen(lst);
	else if (CONVERT == 'f' || CONVERT == 'F' || CONVERT == 'e' ||
			CONVERT == 'E' || CONVERT == 'g' || CONVERT == 'G')
		lst_putdouble(lst);
	else if (CONVERT == 't' && str[ret] == 's')
		ret += recast_tabstring(lst);
	else if (CONVERT == 's' || CONVERT == 'S' ||
			CONVERT == 'r' || CONVERT == 'm')
		recast_string(lst);
	else if (CONVERT == 'd' || CONVERT == 'i' || CONVERT == 'D' ||
			CONVERT == 'x' || CONVERT == 'X' || CONVERT == 'o' ||
			CONVERT == 'O' || CONVERT == 'u' ||
			CONVERT == 'U' || CONVERT == 'p' || CONVERT == 'b' ||
			CONVERT == 'B')
		recast_int(lst);
	else if (CONVERT == '@')
		recast_other(lst);
	else if (CONVERT == '{')
		ret += recast_color(lst, str + ret);
	else if (CONVERT != 0)
		recast_char(lst);
	return (ret);
}

static void	ftprintf_base(char *str, t_pf *lst, size_t i, size_t j)
{
	va_copy(lst->va_copy, lst->va_lst);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] != '%')
			j++;
		put_buff(lst, str + i, j, 0);
		if (str[i + j] == '%')
			i += find_conv(lst, (str + i + j), 0);
		i += j;
	}
	va_end(lst->va_lst);
	va_end(lst->va_copy);
}

int			ft_sprintf(UCHAR **dest, const char *format, ...)
{
	t_pf	*lst;

	lst = lst_init();
	va_start(lst->va_lst, format);
	ftprintf_base((char*)format, lst, 0, 0);
	convert_buff(lst, NULL, 0);
	*dest = lst->str;
	return (lst->count + lst->buff_count);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	t_pf	*lst;

	lst = lst_init();
	va_start(lst->va_lst, format);
	ftprintf_base((char*)format, lst, 0, 0);
	if (lst->count != 0)
		write(fd, lst->str, lst->count);
	if (lst->buff_count != 0)
		write(fd, lst->buff, lst->buff_count);
	if (lst->str != NULL)
		free(lst->str);
	free(lst);
	return (lst->count + lst->buff_count);
}

int			ft_printf(const char *format, ...)
{
	t_pf	*lst;

	lst = lst_init();
	va_start(lst->va_lst, format);
	ftprintf_base((char*)format, lst, 0, 0);
	if (lst->count != 0)
		write(1, lst->str, lst->count);
	if (lst->buff_count != 0)
		write(1, lst->buff, lst->buff_count);
	if (lst->str != NULL)
		free(lst->str);
	free(lst);
	return (lst->count + lst->buff_count);
}
