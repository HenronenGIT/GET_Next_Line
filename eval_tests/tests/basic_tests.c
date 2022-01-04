/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:40:36 by hmaronen          #+#    #+#             */
/*   Updated: 2021/12/27 13:58:28 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	basic_tests()
{
	int		fd;
	char	*line;
	int		ret;
	int		fail;
	char	*str;
	int		out;
	int		p[2];
	
	fd = 0;
	str = "12345678";
	fail = 0;
	ret = 1;
	/*	Dublicate existing fd	*/
	out = dup(1);
	fd = 1;
	/* 1 line, 8 char with newlines.*/
	pipe(p);
	dup2(p[1], fd);
	write(fd, "12345678\n", 9);
	close(p[1]);
	dup2(out, fd);
	while (get_next_line(p[0], &line))
	{
		//printf("%s\n", line);
		if (ret != 1 || strcmp(line, str) != 0)
		{
			printf("%sbasic_fail\n", RED);
			printf(RESET);
			printf("Ret value = %d\nExpected = 1\n", ret);
			printf("line = |%s|\n", line);
			printf("Expected %s\n", str);
			fail = 1;
		}
		free(line);
	}
	/*			2 lines 		*/
	out = dup(1);
	/* create descriptor pair for interprocess communication */
	pipe(p);
	/* Duplicate existing fd	*/
	dup2(p[1], fd);
	write(fd, "12345678\n12345678\n", 20);
	close(p[1]);
	dup2(out, fd);
	while (get_next_line(p[0], &line))
	{
		//printf("%s\n", line);
		if (ret != 1 || strcmp(line, str) != 0)
		{
			printf("%sbasic_fail\n", RED);
			printf(RESET);
			printf("Ret value = %d\nExpected = 1\n", ret);
			printf("line = |%s|\n", line);
			printf("Expected %s\n", str);
			fail = 1;
		}
		free(line);
	}
	out = dup(1);
	/* create descriptor pair for interprocess communication */
	pipe(p);
	/* Duplicate existing fd	*/
	dup2(p[1], fd);
	write(fd, "12345678\n12345678\n12345678\n12345678\n12345678\n12345678\n", (6*8 + 6));
	close(p[1]);
	dup2(out, fd);
	while (get_next_line(p[0], &line))
	{
		//printf("%s\n", line);
		if (ret != 1 || strcmp(line, str) != 0)
		{
			printf("%sbasic_fail\n", RED);
			printf(RESET);
			printf("Ret value = %d\nExpected = 1\n", ret);
			printf("line = |%s|\n", line);
			printf("Expected %s\n", str);
			fail = 1;
		}
		free(line);
	}
	/* BASIC FILE TESTS */
	fd = open("./test_files/basic_tests_1.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open () error in basic_test_fail!\n");
		return (0);
	}
	while ((ret = get_next_line(fd, &line)) != 0)
	{
		if (ret != 1 || strcmp(line, str) != 0)
		{
			printf("%s1l_8c FAIL 1\n", RED);
			printf(RESET);
			printf("Ret value = %d\nExpected = 1\n", ret);
			printf("line = |%s|\n", line);
			printf("Expected %s\n", str);
			fail = 1;
		}
		free(line);
	}
	close(fd);

	fd = open("./test_files/basic_tests_2.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open () error in basic_test_fail!\n");
		return (0);
	}
	while ((ret = get_next_line(fd, &line)) != 0)
	{
		//printf("%s\n", line);
		if (ret != 1 || strcmp(line, str) != 0)
		{
			printf("%s2l_8c FAIL 1\n", RED);
			printf(RESET);
			printf("Ret value = %d\nExpected = 1\n", ret);
			printf("line = |%s|\n", line);
			printf("Expected %s\n", str);
			fail = 1;
		}
		free(line);
	}
	close(fd);

	fd = open("./test_files/basic_tests_3.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open () error in basic_test_fail!\n");
		return (0);
	}
	while ((ret = get_next_line(fd, &line)) != 0)
	{
		//printf("%s\n", line);
		if (ret != 1 || strcmp(line, str) != 0)
		{
			printf("%s8l_8c FAIL 1\n", RED);
			printf(RESET);
			printf("Ret value = %d\nExpected = 1\n", ret);
			printf("line = |%s|\n", line);
			printf("Expected %s\n", str);
			fail = 1;
		}
		free(line);
	}
	close(fd);
	return (fail);
}
