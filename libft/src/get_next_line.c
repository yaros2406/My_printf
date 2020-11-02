/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:14:16 by bshaquan          #+#    #+#             */
/*   Updated: 2019/11/21 21:14:19 by bshaquan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*ft_find_fd(t_list **list, int fd)
{
	t_list	*list_temp;

	list_temp = *list;
	while (list_temp && list_temp->content_size != (size_t)fd)
		list_temp = list_temp->next;
	if (list_temp == NULL)
	{
		list_temp = ft_lstnew(NULL, 0);
		list_temp->content_size = (size_t)fd;
		ft_lstadd(list, list_temp);
	}
	return (list_temp);
}

static int		ft_read_fd(int fd, t_list *list)
{
	int		ret;
	char	*buff;
	char	*temp;

	ret = 0;
	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	if ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (!list->content)
			list->content = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(list->content, buff);
			ft_memdel(&list->content);
			list->content = temp;
		}
	}
	free(buff);
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*p_list = NULL;
	t_list			*list;
	char			*temp;
	int				ret;
	char			test[0];

	ret = 1;
	if (fd < 0 || line == NULL || (read(fd, test, 0) < 0))
		return (-1);
	list = ft_find_fd(&p_list, fd);
	while (((!list->content || (ft_strchr(list->content, '\n') == NULL))
			&& ret > 0))
		ret = ft_read_fd(fd, list);
	*line = ft_strcpychr(list->content, '\n');
	if (*line == NULL || (ret < BUFF_SIZE && ft_strlen(list->content) == 0))
		return (0);
	else
	{
		temp = ft_strncpychr(list->content, '\n');
		ft_memdel(&list->content);
		list->content = temp;
	}
	return (1);
}
