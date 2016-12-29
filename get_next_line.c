/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:40:16 by lchety            #+#    #+#             */
/*   Updated: 2016/12/29 12:13:10 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

int		find_fd(int fd, t_fd_lst *lst, t_fd_lst **tmp)
{
	if (!lst)
	{
		*tmp = (t_fd_lst*)ft_memalloc(sizeof(t_fd_lst));
		(*tmp)->next = NULL;
		(*tmp)->content = NULL;
		(*tmp)->fd = fd;
		(*tmp)->eof = 0;
		return (0);
	}
	if (lst->fd == fd)
	{
		*tmp = lst;
		return (1);
	}
	return (find_fd(fd, lst->next, tmp));
}

int		my_read(t_fd_lst *lst)
{
	char	*tmp;
	size_t	ret;
	char	buff[BUFF_SIZE + 1];

	ret = 0;
	ret = read(lst->fd, buff, BUFF_SIZE);
	if ((int)ret == -1)
		return (ret);
	if (ret < BUFF_SIZE)
		lst->eof = 1;
	buff[ret] = '\0';
	if (ret)
	{
		tmp = lst->content;
		if (lst->content)
			lst->content = ft_strjoin(lst->content, buff);
		else
		{
			lst->content = ft_strnew(ft_strlen(buff));
			ft_strcpy(lst->content, buff);
		}
		if (tmp)
			free(tmp);
	}
	return (ret);
}

int		punchline(t_fd_lst *lst, char **line)
{
	char *tmp;
	char *cut;

	if (lst->content == NULL || !*(lst->content))
		return (0);
	cut = ft_strchr(lst->content, '\n');
	if (ft_strchr(lst->content, '\n'))
	{
		*line = (char*)ft_memalloc(sizeof(char) * (cut - lst->content) + 1);
		*line = ft_strncpy(*line, lst->content, cut - lst->content);
		*(*line + (cut - lst->content)) = '\0';
		tmp = lst->content;
		lst->content = (char*)ft_memalloc(sizeof(char) * ft_strlen(cut));
		ft_strcpy(lst->content, cut + 1);
		free(tmp);
	}
	else
	{
		*line = (char*)ft_memalloc(sizeof(char) * (ft_strlen(lst->content) + 1 ));
		*line = ft_strcpy(*line, lst->content);
		ft_memdel((void*)&(lst->content));
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int ret;
	static t_fd_lst	*lst = NULL;
	t_fd_lst *tmp;

	ret = 1;
	if (fd < 0 || !line)
		return (-1);
	if (!find_fd(fd, lst, &tmp))
	{
		if (lst)
			tmp->next = lst;
		lst = tmp;
	}
	if (!tmp->content)
	{
		ret = my_read(tmp);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (0);
	}
	while (tmp->eof != 1 && !ft_strchr(tmp->content, '\n'))
	{
		ret = my_read(tmp);
		if (ret == -1)
			return (-1);
	}
	ret = punchline(tmp, line);
	return (ret);
}
