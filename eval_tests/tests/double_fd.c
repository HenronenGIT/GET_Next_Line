/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:19:57 by hmaronen          #+#    #+#             */
/*   Updated: 2021/12/20 14:19:59 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	double_fd()
{
	int		fd;
	int		fd2;
	char	*line;
	int		ret;
	int		pass;
	
	pass = 0;
	fd = open("./test_files/double_fd.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("1 double_fd open () error!\n");
		return (1);
	}
	fd2 = open("./test_files/double_fd_2.txt", O_RDONLY);
	if (fd2 == -1)
	{
		printf("2 double_fd open () error!\n");
		return (1);
	}
	/*	Read abcd from 1st file	*/
	if ((ret = get_next_line(fd, &line) != 1 || strcmp(line, "abcd") != 0))
	{
		printf("%sdouble_fd 1 FAIL\n", RED);
		printf(RESET);
		printf("ret = |%d|\nline = |%s|\n", ret, line);
		printf("%sExpexted\nret = |1|\nline = |abcd|\n", GREEN);
		printf(RESET);
		pass = 1;
	}
	free(line);
	/* Read "1234" from 2nd FD */
	if ((ret = get_next_line(fd2, &line) != 1 || strcmp(line, "1234") != 0))
	{
		printf("%sdouble_fd 2 FAIL\n", RED);
		printf(RESET);
		printf("ret = |%d|\nline = |%s|\n", ret, line);
		printf("%sExpexted\nret = |1|\nline = |1234|\n", GREEN);
		printf(RESET);
		pass = 1;
	}
	free(line);
	/* Read efhg from 1st fd */
	if ((ret = get_next_line(fd, &line) != 1 || strcmp(line, "efgh") != 0))
	{
		printf("%sdouble_fd 3 FAIL\n", RED);
		printf(RESET);
		printf("ret = |%d|\nline = |%s|\n", ret, line);
		printf("%sExpexted\nret = |1|\nline = |efgh|\n", GREEN);
		printf(RESET);
		pass = 1;
	}
	free(line);
	/* Read 5678 from 2nd FD */
	if ((ret = get_next_line(fd2, &line) != 1 || strcmp(line, "5678") != 0))
	{
		printf("%sdouble_fd 4 FAIL\n", RED);
		printf(RESET);
		printf("ret = |%d|\nline = |%s|\n", ret, line);
		printf("%sExpexted\nret = |1|\nline = |5678|\n", GREEN);
		printf(RESET);
		pass = 1;
	}
	close(fd);
	close(fd2);
	free(line);
	line = NULL;
	return (pass);
}