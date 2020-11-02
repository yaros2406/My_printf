/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:52:53 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 20:52:57 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*t_result;
	t_list	*t_lst;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	t_lst = f(lst);
	if (!(new = ft_lstnew(t_lst->content, t_lst->content_size)))
		return (new);
	t_result = new;
	lst = lst->next;
	while (lst)
	{
		t_lst = f(lst);
		if (!(t_result->next = ft_lstnew(t_lst->content, t_lst->content_size)))
			return (NULL);
		lst = lst->next;
		t_result = t_result->next;
	}
	return (new);
}
