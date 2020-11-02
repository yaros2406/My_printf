/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:59:31 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 20:59:34 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char const *str)
{
	return (ft_putstr_fd(str, 1));
}

int	ft_putnstr(char const *str, int len)
{
	return (ft_putnstr_fd(str, len, 1));
}

int	ft_putstrw(wchar_t const *str)
{
	return (ft_putstrw_fd(str, 1));
}

int	ft_putnstrw(wchar_t const *str, int len)
{
	return (ft_putnstrw_fd(str, len, 1));
}
