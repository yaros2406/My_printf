/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:07:35 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:07:38 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

size_t	ft_strnlen(const char *s, size_t max)
{
	size_t count;

	count = 0;
	while (s[count] != '\0' && count < max)
		count++;
	return (count);
}

size_t	ft_ustrlen(const unsigned char *s)
{
	size_t count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

size_t	ft_ustrnlen(const unsigned char *s, size_t max)
{
	size_t count;

	count = 0;
	while (s[count] != '\0' && count < max)
		count++;
	return (count);
}
