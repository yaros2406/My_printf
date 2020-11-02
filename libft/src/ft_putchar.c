/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:56:43 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 20:56:46 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	return (ft_putchar_fd(c, 1));
}

int	ft_putwchar(wchar_t c)
{
	return (ft_putwchar_fd(c, 1));
}
