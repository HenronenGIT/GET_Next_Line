/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:25:41 by hmaronen          #+#    #+#             */
/*   Updated: 2022/01/05 12:25:42 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	middle_tests()
{
	int		fd;
	int		ret;
	int		fail;
	char	*line;
	char	*str;
	
	str = "0123456789ABCDEF";
	line = NULL;
	ret = 1;
	fail = 0;

	/*	1 LINE, 16 CHARS WITH NEWLINE	*/
	fd = open("./test_files/middle_tests_1.txt", O_RDONLY);
	if (fd == -1)
		printf("middle_tests_1.txt open() ERROR\n");
	else
	{
		while ((ret = get_next_line(fd, &line)) != 0)
		{
			if (ret != 1 || strcmp(line, str) != 0)
			{
				printf("%sMIDDLE TESTS FAIL 1\n", RED);
				printf(RESET);
				printf("Ret value = %d\nExpected = 1\n", ret);
				printf("line = |%s|\n", line);
				printf("Expected %s\n", str);
				fail = 1;
			}
			free(line);
			line = NULL;
		}
		close(fd);
	}
	/*	2 line, 16 CHARS WITH NEWLINE	*/
	fd = open("./test_files/middle_tests_2.txt", O_RDONLY);
	if (fd == -1)
		printf("middle_tests_2.txt open() ERROR\n");
	else
	{
		while ((ret = get_next_line(fd, &line)) != 0)
		{
			//printf("%s\n",line);
			if (line)
			{
				if ((strcmp(line, str)) != 0)
				{
					printf("%sMIDDLE TESTS FAIL \n", RED);
					printf(RESET);
					printf("Ret value = %d\nExpected = 1\n", ret);
					printf("line = |%s|\n", line);
					printf("Expected |%s|\n", str);
				}
			}
			if (ret != 1 )
			{
				printf("%sMIDDLE TESTS FAIL \n", RED);
				printf(RESET);
				printf("Ret value = %d\nExpected = 1\n", ret);
				printf("line = |%s|\n", line);
				printf("Expected |%s|\n", str);
				fail = 1;
			}
			free(line);
		}
		close(fd);
	}
	/*	8 LINE, 16 CHARS WITH NEWLINE	*/
	fd = open("./test_files/middle_tests_3.txt", O_RDONLY);
	if (fd == -1)
		printf("middle_tests_3.txt open() ERROR\n");
	else
	{
		while ((ret = get_next_line(fd, &line)) != 0)
		{
			if (ret != 1 || strcmp(line, str) != 0)
			{
				printf("%sMIDDLE TESTS FAIL 1\n", RED);
				printf(RESET);
				printf("Ret value = %d\nExpected = 1\n", ret);
				printf("line = |%s|\n", line);
				printf("Expected %s\n", str);
				fail = 1;
			}
			free(line);
			line = NULL;
		}
		close(fd);
	}

	/* STDOUT TESTS	*/
	/*	1 LINE, 16 CHARS	*/
	int		p[2];
	int		out;

	out = dup(1);
	fd = 1;
	/*	READ p[0] - WRITE p[1]	*/
	pipe(p);
	dup2(p[1], fd);
	write(fd, "0123456789ABCDEF\n", 17);
	close(p[1]);
	dup2(out, fd);
	while ((ret = get_next_line(p[0], &line)) != 0)
	{
		//printf("%s\n", line);
		if (ret != 1 || strcmp(line, str) != 0)
		{
			printf("%sMIDDLE TESTS FAIL - STDOUT\n", RED);
			printf(RESET);
			printf("Ret value = %d\nExpected = 1\n", ret);
			printf("line = |%s|\n", line);
			printf("Expected %s\n", str);
			fail = 1;
		}
		free(line);
	}
	close (p[0]);
	close(out);
	
	/*	2 LINES 16 CHARS	*/
	out = dup(1);
	fd = 1;
	/*	READ p[0] - WRITE p[1]	*/
	pipe(p);
	dup2(p[1], fd);
	write(fd, "0123456789ABCDEF\n0123456789ABCDEF\n", 34);
	close(p[1]);
	dup2(out, fd);
	while ((ret = get_next_line(p[0], &line)) != 0)
	{
		//printf("%s\n", line);
		if (ret != 1 || strcmp(line, str) != 0)
		{
			printf("%sMIDDLE TESTS FAIL - STDOUT\n", RED);
			printf(RESET);
			printf("Ret value = %d\nExpected = 1\n", ret);
			printf("line = |%s|\n", line);
			printf("Expected %s\n", str);
			fail = 1;
		}
		free(line);
	}
	close (p[0]);
	close(out);

	/*	8 LINES 16 CHARS	*/
	out = dup(1);
	fd = 1;
	/*	READ p[0] - WRITE p[1]	*/
	pipe(p);
	dup2(p[1], fd);
	write(fd, "0123456789ABCDEF\n0123456789ABCDEF\n0123456789ABCDEF\n0123456789ABCDEF\n0123456789ABCDEF\n0123456789ABCDEF\n0123456789ABCDEF\n0123456789ABCDEF\n", 136);
	close(p[1]);
	dup2(out, fd);
	while ((ret = get_next_line(p[0], &line)) != 0)
	{
		//printf("%s\n", line);
		if (ret != 1 || strcmp(line, str) != 0)
		{
			printf("%sMIDDLE TESTS FAIL - STDOUT\n", RED);
			printf(RESET);
			printf("Ret value = %d\nExpected = 1\n", ret);
			printf("line = |%s|\n", line);
			printf("Expected %s\n", str);
			fail = 1;
		}
		free(line);
	}
	close (p[0]);
	close(out);
	return(fail);
}