/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_with_newline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:40:36 by hmaronen          #+#    #+#             */
/*   Updated: 2021/12/27 13:58:28 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	normal_with_newline()
{
	int		fd;
	size_t	i;
	char	*line;
	int		ret;
	int		pass;

	pass = 0;
	ret = 0;
	i = 0;
	//fd = open("./eval_tests/test_files/normal_with_newline.txt", O_RDONLY);
	fd = open("./test_files/normal_with_newline.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open () error in normal_with_newline test!\n");
		return (0);
	}
	/* Reading abc\n	*/
	ret = get_next_line(fd, &line);
	if (ret != 1 || strcmp(line, "abc") != 0)
	{
		printf("%snormal_with_newline FAIL 1\n", RED);
		printf(RESET);
		printf("Ret value = %d\nExpected = 1\n", ret);
		printf("line = |%s|\n", line);
		printf("Expected |abc|\n");
		pass = 1;
	}
	free(line);
	/*	Read defg\n	*/
	ret = get_next_line(fd, &line);
	if (ret != 1 || strcmp(line, "defg") != 0)
	{
		printf("%snormal_with_newline FAIL 2\n", RED);
		printf(RESET);
		printf("Ret value = %d\nExpected = 1\n", ret);
		printf("line = |%s|\n", line);
		printf("Expected |defg|\n");
		pass = 1;
	}
	free(line);
	/*	Read hijk\n	*/
	ret = get_next_line(fd, &line);
	if (ret != 1 || strcmp(line, "hijk") != 0)
	{
		printf("%snormal_with_newline FAIL 3\n", RED);
		printf(RESET);
		printf("Ret value = %d\nExpected = 1\n", ret);
		printf("line = |%s|\n", line);
		printf("Expected |hijk|\n");
		pass = 1;
	}
	free(line);
	/*	Reads '\0'	*/
	ret = get_next_line(fd, &line);
	if (ret != 0 || strcmp(line, "") != 0)
	{
		printf("%snormal_with_newline FAIL 4\n", RED);
		printf(RESET);
		printf("Ret value = %d\nExpected = 0\n", ret);
		printf("line = |%s|\n", line);
		printf("Expected ||\n");
		pass = 1;
	}
	ret = get_next_line(fd, &line);
	if (ret != 0 || strcmp(line, "") != 0)
	{
		printf("%snormal_with_newline FAIL 5\n", RED);
		printf(RESET);
		printf("Ret value = %d\nExpected = 0\n", ret);
		printf("line = |%s|\n", line);
		printf("Expected ||\n");
		pass = 1;
	}
	close(fd);
	return (pass);
}
