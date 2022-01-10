/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:45:13 by hmaronen          #+#    #+#             */
/*   Updated: 2022/01/05 13:45:15 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	advanced_tests()
{
	int		fd;
	int		ret;
	int		fail;
	char	*line;
	char	*str;
	
	str = "1234";
	line = NULL;
	ret = 1;
	fail = 0;
	/*	1 LINE, 4 CHARS WITH NEWLINE	*/
	fd = open("./test_files/advanced_1.txt", O_RDONLY);
	if (fd == -1)
		printf("advanced_1.txt open() ERROR\n");
	else
	{
		while ((ret = get_next_line(fd, &line)) != 0)
		{
			if (ret != 1 || strcmp(line, str) != 0)
			{
				printf("%sADVANCED TESTS FAIL 1\n", RED);
				printf(RESET);
				printf("Ret value = %d\nExpected = 1\n", ret);
				printf("line = |%s|\n", line);
				printf("Expected |%s|\n", str);
				fail = 1;
			}
			free(line);
			line = NULL;
		}
		close(fd);
	}

	/*	2 LINE, 4 CHARS WITH NEWLINE	*/
	fd = open("./test_files/advanced_2.txt", O_RDONLY);
	if (fd == -1)
		printf("advanced_2.txt open() ERROR\n");
	else
	{
		while ((ret = get_next_line(fd, &line)) != 0)
		{
			if (ret != 1 || strcmp(line, str) != 0)
			{
				printf("%sADVANCED TESTS FAIL 2\n", RED);
				printf(RESET);
				printf("Ret value = %d\nExpected = 1\n", ret);
				printf("line = |%s|\n", line);
				printf("Expected |%s|\n", str);
				fail = 1;
			}
			free(line);
			line = NULL;
		}
		close(fd);
	}
	/*	8 LINE, 4 CHARS WITH NEWLINE	*/
	fd = open("./test_files/advanced_3.txt", O_RDONLY);
	if (fd == -1)
		printf("advanced_3.txt open() ERROR\n");
	else
	{
		while ((ret = get_next_line(fd, &line)) != 0)
		{
			if (ret != 1 || strcmp(line, str) != 0)
			{
				printf("%sADVANCED TESTS FAIL 3\n", RED);
				printf(RESET);
				printf("Ret value = %d\nExpected = 1\n", ret);
				printf("line = |%s|\n", line);
				printf("Expected |%s|\n", str);
				fail = 1;
			}
			free(line);
			line = NULL;
		}
		close(fd);
	}
	/*	1 LINE, 4 CHARS NO NL	*/
	fd = open("./test_files/advanced_4.txt", O_RDONLY);
	if (fd == -1)
		printf("advanced_4.txt open() ERROR\n");
	else
	{
		while ((ret = get_next_line(fd, &line)) != 0)
		{
			if (ret != 1 || strcmp(line, str) != 0)
			{
				printf("%sADVANCED TESTS FAIL 4\n", RED);
				printf(RESET);
				printf("Ret value = %d\nExpected = 1\n", ret);
				printf("line = |%s|\n", line);
				printf("Expected |%s|\n", str);
				fail = 1;
			}
			free(line);
			line = NULL;
		}
		close(fd);
	}
	/*	1 LINE, 8 CHARS NO NL	*/
	fd = open("./test_files/advanced_5.txt", O_RDONLY);
	if (fd == -1)
		printf("advanced_5.txt open() ERROR\n");
	else
	{
		while ((ret = get_next_line(fd, &line)) != 0)
		{
			if (ret != 1 || strcmp(line, "12345678") != 0)
			{
				printf("%sADVANCED TESTS FAIL 6\n", RED);
				printf(RESET);
				printf("Ret value = %d\nExpected = 1\n", ret);
				printf("line = |%s|\n", line);
				printf("Expected |%s|\n", "12345678");
				fail = 1;
			}
			free(line);
			line = NULL;
		}
		close(fd);
	}
	/*	empty line	*/
	fd = open("./test_files/advanced_7.txt", O_RDONLY);
	if (fd == -1)
		printf("advanced_7.txt open() ERROR\n");
	else
	{
		//printf("%s\n",line);
		while ((ret = get_next_line(fd, &line)) != 0)
		{
			if (ret != 1 || strcmp(line, "") != 0)
			{
				printf("%sADVANCED TESTS FAIL 7\n", RED);
				printf(RESET);
				printf("Ret value = %d\nExpected = 1\n", ret);
				printf("line = |%s|\n", line);
				printf("Expected |%s|\n", "");
				fail = 1;
			}
			free(line);
			line = NULL;
		}
		close(fd);
	}
	/*	1 LINE, 16 CHARS NO NL	*/
	fd = open("./test_files/advanced_6.txt", O_RDONLY);
	if (fd == -1)
		printf("advanced_6.txt open() ERROR\n");
	else
	{
		while ((ret = get_next_line(fd, &line)) != 0)
		{
			if (ret != 1 || strcmp(line, "0123456789ABCDEF") != 0)
			{
				printf("%sADVANCED TESTS FAIL 5\n", RED);
				printf(RESET);
				printf("Ret value = %d\nExpected = 1\n", ret);
				printf("line = |%s|\n", line);
				printf("Expected |%s|\n", "0123456789ABCDEF");
				fail = 1;
			}
			free(line);
			line = NULL;
		}
		close(fd);
	}
	/* STDOUT	*/
	int		p[2];
	int		out;

	/*	1 LINE WITH NEWLINE	*/
	out = dup(1);
	fd = 1;
	/*	READ p[0] - WRITE p[1]	*/
	pipe(p);
	dup2(p[1], fd);
	write(fd, "1234\n", 5);
	close(p[1]);
	dup2(out, fd);
	while ((ret = get_next_line(p[0], &line)) != 0)
	{
		//printf("%s\n", line);
		if (ret != 1 || strcmp(line, str) != 0)
		{
			printf("%sADVANCED TESTS FAIL - STDOUT 1\n", RED);
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

	/*	2 LINES WITH NEWLINE	*/
	out = dup(1);
	fd = 1;
	/*	READ p[0] - WRITE p[1]	*/
	pipe(p);
	dup2(p[1], fd);
	write(fd, "1234\n1234\n", 10);
	close(p[1]);
	dup2(out, fd);
	while ((ret = get_next_line(p[0], &line)) != 0)
	{
		//printf("%s\n", line);
		if (ret != 1 || strcmp(line, str) != 0)
		{
			printf("%sADVANCED TESTS FAIL - STDOUT 2\n", RED);
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
	/*	8 LINES WITH NEWLINE	*/
	out = dup(1);
	fd = 1;
	/*	READ p[0] - WRITE p[1]	*/
	pipe(p);
	dup2(p[1], fd);
	write(fd, "1234\n1234\n1234\n1234\n1234\n1234\n1234\n1234\n", 40);
	close(p[1]);
	dup2(out, fd);
	while ((ret = get_next_line(p[0], &line)) != 0)
	{
		//printf("%s\n", line);
		if (ret != 1 || strcmp(line, str) != 0)
		{
			printf("%sADVANCED TESTS FAIL - STDOUT 2\n", RED);
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
	return (fail);
}
