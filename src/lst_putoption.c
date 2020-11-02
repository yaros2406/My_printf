/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_putoption.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:00:09 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 19:00:14 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	lst_undefined(t_pf *lst)
{
	if (ZERO > 1 && POINT > 1)
		ZERO = 0;
	else if (ZERO > 1)
		ZERO = 1;
	if (POINT > 1)
	{
		POINT = 0;
		STRICT = 0;
	}
	if (CONVERT != 'i' && CONVERT != 'd' && CONVERT != 'u' &&
			CONVERT != 'f' && CONVERT != 'F' && CONVERT != 'g' &&
			CONVERT != 'G')
		LOCAL = 0;
	if (CONVERT == 's' || CONVERT == 'S')
		STRICT = ABS(STRICT);
	if (HASH == 1 && (CONVERT == 'u' || CONVERT == 'U'))
		HASH = 0;
	if (SPACE == 1 && (CONVERT == 'o' || CONVERT == 'O' ||
				CONVERT == 'x' || CONVERT == 'X'))
		SPACE = 0;
}

static void	lst_base(t_pf *lst)
{
	if (CONVERT == 'x' || CONVERT == 'X' || CONVERT == 'p'
				|| CONVERT == 'a' || CONVERT == 'A')
		BASE = 16;
	else if (CONVERT == 'o' || CONVERT == 'O')
		BASE = 8;
	else if (CONVERT == 'b' || CONVERT == 'B')
		BASE = 2;
	else
		BASE = 10;
	if (!ft_islowercase(CONVERT))
		MAJOR = 1;
	lst_undefined(lst);
}

static int	lst_putflag_conv(t_pf *lst, char *str, int count)
{
	if (str[count] == 'h')
		LENGTH++;
	else if (str[count] == 'l')
		LENGTH += 10;
	else if (str[count] == 'j')
		LENGTH += 100;
	else if (str[count] == 'z')
		LENGTH += 1000;
	else if (str[count] == 'L')
		LENGTH += 100000;
	else
		CONVERT = str[count];
	count++;
	return (count);
}

static int	lst_putdigit(t_pf *lst, char *str, int count, int *neg)
{
	int nb_tmp;

	nb_tmp = 0;
	if (str[count] == '+')
		SIGN = str[count++];
	else if (str[count] == '-')
		(*neg) = str[count++] - 46;
	else if (ft_isdigit(str[count]) == 1 || str[count] == '*'
			|| str[count] == '$')
	{
		while (str[count] >= '0' && str[count] <= '9')
			nb_tmp = (nb_tmp * 10) + (str[count++] - '0');
		if (str[count] == '$')
			lst_putdollar(lst, nb_tmp);
		if ((str[count] == '*' || str[count] == '$') && (count++))
			nb_tmp = va_arg(lst->va_copy, int);
		if (POINT == 0)
			FIELD = (nb_tmp * (*neg));
		else
			STRICT = nb_tmp;
	}
	return (count);
}

int			lst_putoption(t_pf *lst, char *str, int count)
{
	int		neg;

	neg = 1;
	lst_zero(lst);
	while (str[count] != '\0' && CONVERT == 0)
	{
		if (str[count] == '.')
			POINT += str[count++] - 45;
		else if (str[count] == '0' && POINT == 0)
			ZERO += str[count++] - 47;
		else if (str[count] == 39)
			LOCAL = str[count++] - 38;
		else if (str[count] == '#')
			HASH = str[count++] - 34;
		else if (str[count] == ' ')
			SPACE = str[count++] - 31;
		else if (ft_isdigit(str[count]) == 1 || str[count] == '+' ||
				str[count] == '-' || str[count] == '*' || str[count] == '$')
			count = lst_putdigit(lst, str, count, &neg);
		else
			count = lst_putflag_conv(lst, str, count);
	}
	lst_base(lst);
	return (count);
}
