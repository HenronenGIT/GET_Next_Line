/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_line.c .                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:29:32 by hmaronen          #+#    #+#             */
/*   Updated: 2022/01/03 10:29:33 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	long_line()
{
	int		fd;
	int		ret;
	char	*line;
	int		pass;
	char long_str[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempusLorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus";

	pass = 0;
	//fd = open("./eval_tests/test_files/long_line.txt", O_RDONLY);
	fd = open("./test_files/long_line.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("long line open() error!\n");
		return(1);
	}
	/* Reads whole line ret should be 1	*/
	ret = get_next_line(fd, &line);
	if ((ret != 1) || strcmp(line, long_str) != 0)
	{
		printf("%slong_line [ERROR] 1\n", RED);
		printf(RESET);
		if (strcmp(line, long_str) != 0)
		{
			printf("line differs\n");
			pass = 1;
		}
		printf("gnl_ret = %d\nExpected 1\n", ret);
		pass = 1;
	}
	close(fd);
	free(line);
	return(pass);
}