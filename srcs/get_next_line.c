/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:40:16 by lchety            #+#    #+#             */
/*   Updated: 2016/12/19 14:22:45 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>


int		find_fd(int fd, t_fd_lst *lst, t_fd_lst **tmp)
{
	//printf("FIND_FD\n");

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

	/*
	if (!lst)
	{
		printf("if lst est null\n");
		lst = (t_fd_lst*)malloc(sizeof(t_fd_lst));
		lst->next = NULL;
		lst->content = NULL;
		return (lst);
	}
	if (fd && fd == lst->fd)
	{
		printf("if find fd\n");
		return (lst);
	}
	return (find_fd(fd, lst->next));
	*/
	//push in line

int		my_read(t_fd_lst *lst)
{
	//printf("##ENTER MY_READ\n");
	size_t ret;
	char buff[BUFF_SIZE + 1];

	ret = 0;
	//printf("Read function\n");
	//printf("Test fd = %d\n", lst->fd);
	ret = read(lst->fd, buff, BUFF_SIZE);

	if (ret < 1)
		return (ret);
	buff[ret] = '\0';
	//printf("###BUFF = %s\n", buff);

	if (lst->content)
	{
		lst->content = ft_strjoin(lst->content, buff);
	}
	else
	{
		lst->content = ft_strnew(strlen(buff));
		ft_strcpy(lst->content, buff);
		//printf("##FT_STRCPY content = %s\n", lst->content);
	}

	//if read dont return 0 and no /n
	//call my read again
	return (ret);
}

int		punchline(t_fd_lst *lst, char **line)
{
	char *end;
	char *tmp;
	char *cut;

	if (*lst->content == 0)
		return (0);
	tmp = lst->content;
	cut = ft_strchr(lst->content,'\n');
	//
	// printf("IF lst->content is : %d", *lst->content);
	// printf("\n");

	if (cut)
	{
		//printf("strchr start as %s\n", lst->content);
		*line = (char*)ft_memalloc(sizeof(char) * (cut - lst->content));
		*line = ft_strncpy(*line, lst->content, cut - lst->content);
		*(*line + (cut - lst->content)) = '\0';

		lst->content = (char*)malloc(sizeof(char) * ft_strlen(cut + 1));
		ft_strcpy(lst->content, cut + 1);

		//printf("## LINE RES = %s", *line);

		//send to line
		//1 cut
		//2 cpy
		//lst->content =

		return (1);
	}
	else
	{
		//printf("RECHERCHE QUI MET CONTENT A 0\n");
		*line = ft_strcpy(*line, lst->content);
		return (1);
		lst->content = NULL;
	}
	//je met dans **line lst->content
	// ensuite je cut lst->content jusqu a \n ou \0
	return(0);
}

int		get_next_line(int fd, char **line)
{
	//printf("GET_NEXT_LINE\n");
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
	//printf("fd after find_fd = %d\n", tmp->fd);

	while (ret > 0)
	{
		//printf("While ret != 0 call my_read\n");
		ret = my_read(tmp);
		if (ret == 0)
			tmp->eof = 1;
		if (ret == -1)
			return (-1);
		//printf("Ret after read = %d\n", ret);

		if (tmp->content)
		{
			//printf("CONTENT before ft_strchr = %s\n", tmp->content);
			if (ft_strchr(tmp->content, '\n'))
			{
				ret = 0;
				//printf("FT_STRCHR \\n kill the loop\n");
			}
		}
	}

	ret = punchline(lst, line);
	if (!ret)
	{
		*line = NULL;
	}

	//printf("##RET OF PUNCHLINE %d\n", ret);

	return (ret);
}

//mon content est jamais NULL

//le fd est null quand il existe deja dans la liste fuck fuck

/*
int		my_read(t_fd_lst *lst)
{
	printf("Enter in my_read\n");
	int ret;
	char buff[BUFF_SIZE + 1];
	char *tmp;

	ret = 0;
	ret = read(lst->fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	printf("ret mes couilles %d\n", ret);
	printf("My read buff == %s\n", buff);

	if (ret)
	{
		printf("My read if ret == something\n");
		if (ret < BUFF_SIZE)
		{
			lst->eof = 1;
			printf("EOF by comparaison of ret and BUFF_SIZE\n");
		}
		tmp = lst->content;
		if (tmp)
		{
			lst->content = ft_strjoin(lst->content, buff);
			free(tmp);
		}
		else
		{
			printf("ft_strlen if content == empty before %d\n", (int)ft_strlen(buff));
			lst->content = (char*)malloc(sizeof(char) * ft_strlen(buff));
			ft_strcpy(lst->content, buff);
		}
		//free(buff);
	}
	else if (ret == 0)
		lst->eof = 1;
	return (ret);
}

int			get_line(t_fd_lst *lst)
{
	printf("GET_LINE\n");
	int ret;
	if (lst->content)//something
	{
		printf("if content full\n");
		//search \n
		if(ft_strchr(lst->content, '\n'))
		{
			printf("ft_strchr \\n in content\n");
			return (1);
		}
		else
		{
			printf("No \\n in content\n");
			printf("Read with content full\n");
			if(my_read(lst))
			{
				printf("Read return 1\n");
				//if read return 1

			}
			else
			{
				printf("Read return 0\n");
				return (0);
			}
		}
		return (1);
	}

	if (!lst->content)
	{
		printf("if content empty\n");
		if(my_read(lst))
		{
			printf("read return something");
		}
		else
		{
			printf("read return 0");
		}
	}

	return (0);// nothing to read
}

t_fd_lst	*find_fd(t_fd_lst *lst, int fd)
{
	if (!lst)
		return (NULL);
	if (!fd && fd == lst->fd)
		return (lst);
	return(find_fd(lst->next, fd));

}

int		get_next_line(const int fd, char **line)
{
	printf("GET_NEXT_LINE\n");
	//create list if dont exist
	static t_fd_lst *lst = NULL;
	t_fd_lst *fd_link = NULL;
	int ret;

	ret = 0;
	if (fd < 0)//si fd == -1 bad file name
	{
		ft_putstr("bad file name");
		return (0);
	}
	fd_link = find_fd(lst, fd);
	if (!fd_link)
	{
		fd_link = (t_fd_lst*)malloc(sizeof(t_fd_lst));
		fd_link->next = NULL;
		fd_link->content = NULL;
		fd_link->eof = 0;
		fd_link->fd = fd;
		if (!lst)
			lst = fd_link;
		else
		{
			fd_link->next = lst;
			lst = fd_link;
		}
	}

	if (lst->eof && !fd_link->content)
		return(0);
	ret = get_line(fd_link);
	if (ret == 1)
	{
		return(1);
	}
	else if (ret == -1)
	{
		printf("error\n");
		return (-1);
	}

	if (*line)
		free(*line);
	*line = NULL;
	return (0);
}


t_fd_lst	*find_fd(t_fd_lst *lst, int fd)
{
	if (lst)
	{
		if (lst->fd == fd)
			return (lst);
		else
			return(find_fd (lst->next, fd));
	}
	return (NULL);
}

int		add_content(t_fd_lst *lst)
{
	char *tmp;
	char buff[BUFF_SIZE + 1];
	int ret;

	ret = 0;
	buff[BUFF_SIZE] = '\0';
	ret = read(lst->fd, buff, BUFF_SIZE);
	if (ret == 0)
		return (0);
	printf("###%s###\n", buff);

	if (lst->content)
	{
		tmp = lst->content;
		lst->content = ft_strjoin(lst->content, buff);
		free(tmp);
		tmp = lst->content;
		//free(tmp);
	}
	else
	{
		lst->content = (char*)ft_memalloc(sizeof(char) * ft_strlen(buff));
		lst->content = ft_strcpy(lst->content, buff);
	}
	return (1);
}

int		get_line(t_fd_lst *lst, char **line)
{
	char *tmp;
	char *cut;
	int ret;

	ret = 0;
	cut = 0;
	if (!lst->content)
		ret = add_content(lst);
	while (!ft_strchr(lst->content, '\n') && ret != 0)
		ret = add_content(lst);
	cut = ft_strchr(lst->content, '\n');


 		je dois couper un morceau de content et le mettre dans *line
		et pas content en entier...

	*line = ft_strnew(sizeof(char) * ((cut+ 1) - lst->content));// HAHA !
	ft_strncpy(*line, lst->content, (cut + 1) - lst->content);
	tmp = lst->content;
	lst->content = ft_strnew(ft_strlen(cut + 1));
	ft_strcpy(lst->content, cut + 1);
	// printf("#->cut part : %s\n", lst->content);
	//
	// printf("#->after strncpy : %s\n", *line);
	//printf("sgfault\n");
	free(tmp);
	//ft_strcpy(*line, lst->content);
	//tmp = lst->content;
	//free(tmp);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_fd_lst		*fd_lst = NULL;
	t_fd_lst		*tmp;
	*line = NULL;

	tmp = find_fd(fd_lst, fd);

	if (!tmp)
	{
		tmp = (t_fd_lst*)malloc(sizeof(t_fd_lst));
		tmp->next = NULL;
		tmp->lst_line = NULL;
		tmp->content = NULL;
		tmp->fd = fd;

		if (!fd_lst)
			fd_lst = tmp;
		else
		{
			//si lst existait je place le nouveau fd au dessus
			tmp->next = fd_lst;
			fd_lst = tmp;
		}
	}

	get_line(tmp, line);
	// printf("fuck =============>\n");
	//ft_putstr(*line);
	//printf("\n");
	//apres je prend la taille de line pour faire un strsub je garde l ancienne chaine dans tmp je copie le strsub dans content et je free tmp
	//printf("%s", *line);
	//ft_putstr(*line);

	return (0);// 1, 0, -1
}




	return 1 line lue
	return 0 termine
	return -1 erreur




*/
