/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:40:16 by lchety            #+#    #+#             */
/*   Updated: 2016/12/21 17:57:47 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>


int		find_fd(int fd, t_fd_lst *lst, t_fd_lst **tmp)
{

	if (!lst)
		return (0);
	if (lst->fd == fd)
	{
		//printf("lst->fd == fd\n");
		*tmp = lst;
		return (1);
	}
	return (find_fd(fd, lst->next, tmp));
}

int		my_read(t_fd_lst *lst)
{
	//printf("##ENTER MY_READ\n");
	char	*tmp;
	size_t ret;
	char buff[BUFF_SIZE + 1];

	ret = 0;
	//printf("Test fd = %d\n", lst->fd);
	ret = read(lst->fd, buff, BUFF_SIZE);
	if (ret < BUFF_SIZE)
		lst->eof = 1;

	if ((int)ret == -1)
		return (ret);
	buff[ret] = '\0';
	//printf("###BUFFER = %s\n", buff);

	if (ret)
	{
		tmp = lst->content;
		if (lst->content)
		{
			lst->content = ft_strjoin(lst->content, buff);
		}
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
	// printf("###PUNCHLINE START\n");
	char *tmp;
	char *cut;

	if (lst->content == NULL)
		return (0);

	tmp = lst->content;
	cut = NULL;
	cut = ft_strchr(lst->content,'\n');

	if (cut)
	{
		if (*line)
			free(*line);
		*line = (char*)ft_memalloc(sizeof(char) * (cut - lst->content) + 1);
		*line = ft_strncpy(*line, lst->content, cut - lst->content);
		*(*line + (cut - lst->content)) = '\0';

		tmp = lst->content;
		lst->content = (char*)malloc(sizeof(char) * ft_strlen(cut));
		ft_strcpy(lst->content, cut + 1);
		free(tmp);
		// printf("11111111\n");
		return (1);
	}
	else if (ft_strlen(lst->content))
	{
		if (*line)
			free(*line);
		*line = (char*)ft_memalloc(sizeof(char) * (ft_strlen(lst->content)));
		*line = ft_strcpy(*line, lst->content);
		// printf("line = %s", *line);
		// printf("test\n");
		free(lst->content);
		lst->content = NULL;
		// printf("22222222\n");
		return (1);

	}

	//je met dans **line lst->content
	// ensuite je cut lst->content jusqu a \n ou \0
	return (0);
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
		tmp = (t_fd_lst*)malloc(sizeof(t_fd_lst));
		tmp->next = NULL;
		tmp->content = NULL;
		tmp->fd = fd;
		tmp->eof = 0;

		if (!lst)
			lst = tmp;
		else
		{
			tmp->next = lst;
			lst = tmp;
		}
	}
	// printf("##CONTENT TEST = %s\n\n", tmp->content);
	if (!lst->content)
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

	ret = punchline(lst, line);

	return (ret);
}
