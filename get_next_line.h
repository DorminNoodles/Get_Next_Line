/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:40:11 by lchety            #+#    #+#             */
/*   Updated: 2016/12/29 14:07:19 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 50000

typedef struct s_line_lst t_line_lst;
typedef struct s_proto t_proto;
typedef struct s_fd_lst t_fd_lst;

struct s_fd_lst
{
	int			fd;
	int			eof;
	char		*content;
	char		*tmp_line;
	t_fd_lst 	*next;
};

int		get_next_line(int, char**);

#endif
