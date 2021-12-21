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

#include "get_next_line.h"
#include <stdio.h>

int	double_fd()
{
	int		fd;
	int		fd2;
	char	*line;

	fd = open("./files/file.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open () error!\n");
		return (1);
	}
	printf("MAIN RETURN:%d\n", get_next_line(fd, &line));
	printf("line:|%s|\n\n", line);

	fd2 = open("./files/file2.txt", O_RDONLY);
	if (fd2 == -1)
	{
		printf("open () error!\n");
		return (1);
	}
	printf("MAIN RETURN:%d\n", get_next_line(fd2, &line));
	printf("line:|%s|\n\n", line);

	printf("MAIN RETURN:%d\n", get_next_line(fd, &line));
	printf("line:|%s|\n\n", line);

	printf("MAIN RETURN:%d\n", get_next_line(fd, &line));
	printf("line:|%s|\n\n", line);

	printf("MAIN RETURN:%d\n", get_next_line(fd, &line));
	printf("line:|%s|\n\n", line);

	close(fd);
	close(fd2);
	return (0);
	
}