/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:53:27 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 20:53:30 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_match_test_case(char s1, char s2)
{
	if (s1 == s2)
		return (1);
	else if (s2 == '*')
		return (2);
	else if (s1 != s2)
		return (0);
	return (0);
}

static	int		ft_return_star(char *s2, int b)
{
	while (s2[b + 1] == '*')
		b++;
	return (b);
}

static	int		ft_return_star2(char *s1, int a)
{
	while (s1[a] == '*')
		a++;
	return (a);
}

static	int		ft_test_match_final(char *s1, char *s2, int a, int b)
{
	while (s2[b] == '*')
		b++;
	if (s1[a] != s2[b])
		return (0);
	return (1);
}

int				ft_match(char *s1, char *s2)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (s1[a] != '\0' && s2[b] != '\0')
	{
		a = ft_return_star2(s1, a);
		if ((ft_match_test_case(s1[a], s2[b]) == 1))
		{
			a++;
			b++;
		}
		else if ((ft_match_test_case(s1[a], s2[b]) == 2))
		{
			b = ft_return_star(s2, b);
			if ((s2[b + 1] != '*') && (s1[a] == s2[b + 1]))
				b++;
			else
				a++;
		}
		else
			return (0);
	}
	return (ft_test_match_final(s1, s2, a, b));
}
