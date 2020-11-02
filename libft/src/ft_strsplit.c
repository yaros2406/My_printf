/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:11:51 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:11:54 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_pass_char(const char *str, char c, int count)
{
	while (str[count] == c && str[count] != '\0')
		count++;
	return (count);
}

static int		ft_strlen_word(const char *str, char c)
{
	int len;

	len = 0;
	while (str[len] != c && str[len] != '\0')
		len++;
	return (len);
}

static int		ft_strlen_tab(const char *str, char c)
{
	int count;
	int len;

	count = 0;
	len = 0;
	while (str[count] != '\0')
	{
		count = ft_pass_char(str, c, count);
		if (str[count] != '\0')
			len++;
		while (str[count] != c && str[count] != '\0')
			count++;
	}
	return (len);
}

static char		**ft_strsplit2(const char *s, char c)
{
	int		longeur;
	int		largeur;
	int		count;
	char	**tab;

	longeur = 0;
	largeur = 0;
	if ((!(tab = (char **)malloc(sizeof(char *) *
			(ft_strlen_tab(s, c)) + 1))))
		return (NULL);
	count = ft_pass_char(s, c, 0);
	while (s[count] != '\0')
	{
		if (!(tab[largeur] = (char *)malloc(sizeof(char) *
				(ft_strlen_word(s + count, c)) + 1)))
			return (NULL);
		while (s[count] != c && s[count] != '\0')
			tab[largeur][longeur++] = (char)s[count++];
		tab[largeur][longeur] = '\0';
		longeur = 0;
		largeur++;
		count = ft_pass_char(s, c, count);
	}
	tab[largeur] = NULL;
	return (tab);
}

char			**ft_strsplit(const char *s, char c)
{
	if (!s)
		return (NULL);
	else
		return (ft_strsplit2(s, c));
}
