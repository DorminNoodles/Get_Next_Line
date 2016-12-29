/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 14:02:03 by lchety            #+#    #+#             */
/*   Updated: 2016/12/29 14:29:29 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int i;
	int ret;
	int fd;
	int fd2;
	int *fd_tab;
	// char *pathname2 = "test_file_02";
	char *line;

	//argv[0][0] = 'b';
	fd = 0;
	fd2 = 0;
	ret = 1;
	line = NULL;
	i = 1;

	//printf ("argc : %d", argc);
	fd_tab = (int*)malloc(sizeof(int) * argc - 1);
	if (!fd_tab)
		return (0);
	i = 1;
	while (i < argc)
	{
		fd_tab[i - 1] = open(argv[i], O_RDONLY);
		//printf("%d", fd)
		i++;
	}

	i = 1;
	while (ret)
	{
		ret = 0;
		i = 1;

		while (i < argc)
		{
			line = NULL;
			if (get_next_line(fd_tab[i - 1], &line) == 1)
				ret = 1;
			i++;
			printf("%s\n", line);
			printf("return : %d\n", ret);
			//free(line);
		}
	}
	return (1);
}

/*
static void test01(t_test *test)
{
	test->timeout = 1;

	char *line;
	int fd;
	int fd2;
	int fd3;
	int	diff_file_size;

	fd = open("sandbox/one_big_fat_line.txt", O_RDONLY);
	fd2 = open("sandbox/one_big_fat_line.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

	while (get_next_line(fd, &line) == 1)
	{
	    write(fd2, line, strlen(line));
	    write(fd2, "\n", 1);
	}
	if (line)
		write(fd2, line, strlen(line));
	close(fd);
	close(fd2);

	system("diff sandbox/one_big_fat_line.txt sandbox/one_big_fat_line.txt.mine > sandbox/one_big_fat_line.diff");
	fd3 = open("sandbox/one_big_fat_line.diff", O_RDONLY);
	diff_file_size = read(fd3, NULL, 10);
	close(fd3);

	mt_assert(diff_file_size == 0);
}
*/




// #include <fcntl.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <time.h>
// #include "get_next_line.h"
// #include "libft.h"
//
// # define BLACK "\x1B[30m"
// # define RED "\x1B[31m"
// # define GREEN "\x1B[32m"
// # define YELLOW "\x1B[33m"
// # define BLUE "\x1B[34m"
// # define MAGENTA "\x1B[35m"
// # define CYAN "\x1B[36m"
// # define WHITE "\x1B[37m"
// # define CRESET "\x1B[0m"
//
// int	main(int ac, char **av)
// {
// 	char	*line;
// 	int		fd[5];
// 	int		i;
// 	int		j;
// 	int		status;
//
// 	j = 1;
// 	i = 1;
// 	status = 1;
// 	printf(YELLOW"===========================================================\n"CRESET);
// 	printf(YELLOW"=            ----> "RED"BADASS "YELLOW"GNL CHECKER !! <----            =\n"CRESET);
// 	printf(YELLOW"===========================================================\n"CRESET);
// 	printf(RED"error test = %d\n"CRESET, get_next_line(13, &line));
// 	printf(RED"error test = %d\n"CRESET, get_next_line(-2, &line));
// 	printf(RED"error test = %d\n"CRESET, get_next_line(1, NULL));
// 	if (ac > 1)
// 	{
// 		while (i <= ac)
// 		{
// 			fd[i - 1] = open(av[i], O_RDONLY);
// 			i++;
// 		}
// 		i = 1;
// 		for (int j = 0; j < 10; j++)
// 		{
// 			i = 1;
// 			while (i < ac)
// 			{
// 				status = get_next_line(fd[i  - 1], &line);
// 				printf(CYAN"L%dGNL(%d):	%s fd[%d]		%sline{%s}\n"CRESET, j, status, fd[i - 1] % 3 ? (fd[i - 1] % 3 == 1 ? GREEN : YELLOW) : WHITE, fd[i - 1],line ? BLUE : RED , line);
// 				ft_memdel((void**)&line);
// 				i++;
// 			}
// 		}
// 	}
// 	printf(YELLOW"===========================================================\n"CRESET);
// 	printf(YELLOW"=        ----> END OF "RED"BADASS "YELLOW"GNL CHECKER !! <----         =\n"CRESET);
// 	printf(YELLOW"===========================================================\n"CRESET);
// 	return (0);
// }
//
// int	main(int ac, char **av)
// {
// 	char	*line;
// 	int		ensang;
// 	int		fd;
//
// 	fd = 0;
// 	if (ac == 2)
// 	{
// 		fd = open(av[1], O_RDONLY);
// 		if (fd == -1)
// 		{
// 			write(2, "open() error\n", 11);
// 			return (0);
// 		}
// 	}
// 	while ((ensang = get_next_line(fd, &line)))
// 	{
// 		printf("---\n");
// 		printf("%s\n", line);
// 		printf("+++\n");
// 		free(line);
// 		line = NULL;
// 	}
// 	printf("!%s!\n", line);
// 	if (line)
// 		free(line);
// 	return (0);
// }
