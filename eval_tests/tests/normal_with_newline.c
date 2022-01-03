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
	//fd = open("normal_with_newline.txt", O_RDONLY);
	fd = open("./test_files/normal_with_newline.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open () error in normal_with_newline test!\n");
		return (0);
	}
	/* Reading abc\n	*/
	if ((ret = get_next_line(fd, &line)) != 1 || strcmp(line, "abc") != 0)
	{
		printf("%snormal_with_newline FAIL\n", RED);
		printf("Ret value = %d\nExpected = 1\n", ret);
		printf("line = |%s|\n", line);
		printf("Expected |abc|\n");
		printf(RESET);
		pass = 1;
	}
	if ((ret = get_next_line(fd, &line)) != 1 || strcmp(line, "defg") != 0)
	{
		printf("%snormal_with_newline FAIL\n", RED);
		printf("Ret value = %d\nExpected = 1\n", ret);
		printf("line = |%s|\n", line);
		printf("Expected |defg|\n");
		printf(RESET);
		pass = 1;
	}
	if ((ret = get_next_line(fd, &line)) != 1 || strcmp(line, "hijk") != 0)
	{
		printf("%snormal_with_newline FAIL\n", RED);
		printf("Ret value = %d\nExpected = 1\n", ret);
		printf("line = |%s|\n", line);
		printf("Expected |hijk|\n");
		printf(RESET);
		pass = 1;
	}
	if ((ret = get_next_line(fd, &line)) != 0 || strcmp(line, "") != 0)
	{
		printf("%snormal_with_newline FAIL\n", RED);
		printf("Ret value = %d\nExpected = 1\n", ret);
		printf("line = |%s|\n", line);
		printf("Expected ||\n");
		printf(RESET);
		pass = 1;
	}

	//while (i <= 3)
	//{
	//	printf("RET|%d|\n",get_next_line(fd, &line));
	//	printf("|%s|\n\n", line);
	//	i++;
	//}

	close(fd);
	free(line);
	line = NULL;
	return (pass);
}
