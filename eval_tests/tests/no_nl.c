/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_no_nl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:19:05 by hmaronen          #+#    #+#             */
/*   Updated: 2021/12/22 15:19:08 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	no_nl()
{
	int		fd;
	char	*line;
	int		ret;
	int		fail;

	fail = 0;
	ret = 0;
	fd = 0;
	/*	FOR DEGUGGER	*/
	//fd = open("./eval_tests/test_files/no_nl.txt", O_RDONLY);
	/*	FOR MAKEFILE */
	fd = open("./test_files/no_nl.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() error in no_nl\n");
		return (1);
	}
	/* Reading line which ends to \0 */
	ret = get_next_line(fd, &line);
	if (ret != 1 || strcmp(line, "abcd") != 0)
	{
		printf("%sno_nl FAIL 1\n", RED);
		printf(RESET);
		printf("gnl_ret = %d\nExpected 1\nline = %s\nExpected abcd\n", ret, line);
		fail = 1;
	}
	/* Reading line which ends to \0 */
	ret = get_next_line(fd, &line);
	if (ret != 0 || strcmp(line, "abcd") != 0)
	{
		printf("%sno_nl FAIL 2\n", RED);
		printf(RESET);
		printf("gnl_ret = %d\nExpected 0\nline = %s\nExpected abcd\n", ret, line);
		fail = 1;
	}
	free(line);
	line = NULL;
	/*	Reading 0	*/
	ret = get_next_line(fd, &line);
	if (ret != 0 || line)
	{
		printf("%sno_nl FAIL 3\n", RED);
		printf(RESET);
		printf("Return value = %d\nline = %s\n", ret, line);
		fail = 1;
	}
	close (fd);
	return (fail);
}
