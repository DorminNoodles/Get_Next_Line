/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 14:02:03 by lchety            #+#    #+#             */
/*   Updated: 2016/12/18 17:42:22 by lchety           ###   ########.fr       */
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
	int ret;
	int fd;
	int fd2;
	int i;
	char *pathname = argv[1];
	char *pathname2 = "test_file_02";
	char *line;

	fd = 0;
	fd2 = 0;
	ret = 0;
	line = NULL;
/*
	i = 0;
	while (i < 25)
	{
		get_next_line(fd);
		i++;
	}
*/
	fd = open(pathname, O_RDONLY);
	fd2 = open(pathname2, O_RDONLY);

	printf("\n#####---->MAIN<----#####\n");
	ret = get_next_line(fd, &line);
	printf("##test = %s#bob\n", line);
	printf("#GNL : return %d", ret);
	printf("\n\n");

	printf("\n#####---->MAIN<----#####\n");
	ret = get_next_line(fd, &line);
	printf("##test = %s#bob\n", line);
	printf("#GNL : return %d", ret);
	printf("\n\n");

	printf("\n#####---->MAIN<----#####\n");
	ret = get_next_line(fd, &line);
	printf("##test = %s#bob\n", line);
	printf("#GNL : return %d", ret);
	printf("\n\n");

	printf("#####---->MAIN<----#####\n");
	ret = get_next_line(fd, &line);
	printf("##test = %s#bob\n", line);
	printf("#GNL : return %d", ret);
	printf("\n\n");

	printf("\n#####---->MAIN<----#####\n");
	ret = get_next_line(fd, &line);
	printf("##test = %s#bob\n", line);
	printf("#GNL : return %d", ret);
	printf("\n\n");


/*
	get_next_line(fd, &line);
	printf("\n#####---->MAIN<----#####");
	printf("\ntest = %s#bob\n", line);
*/

/*
	get_next_line(fd, &line);
	printf("\n#####---->MAIN<----#####");
	printf("\ntest = %s#bob\n", line);
*/

	/*
	get_next_line(fd, &line);
	printf("test = %s\n", line);
	printf("fd test = %d \n", fd);
	get_next_line(fd2, &line);
	printf("test = %s\n", line);
	printf("fd test = %d \n", fd2);
	get_next_line(fd, &line);
	printf("test = %s\n", line);
	printf("fd test = %d \n", fd);
	get_next_line(fd2, &line);
	printf("test = %s\n", line);
	printf("fd test = %d \n", fd2);
	get_next_line(fd, &line);
	printf("test = %s\n", line);
	printf("fd test = %d \n", fd);
	get_next_line(fd2, &line);
	printf("test = %s\n", line);
	printf("fd test = %d \n", fd2);
*/


	return (1);
}
