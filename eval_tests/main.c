/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:12:30 by hmaronen          #+#    #+#             */
/*   Updated: 2021/12/15 10:12:32 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//int double_fd();

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("./file.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open () error!\n");
		return (1);
	}

	//normal_test();
	//double_fd();

	//char	*line2;

	//line = NULL;
	//printf("MAIN RETURN:%d\n", get_next_line(-5, &line2));
	//printf("line:|%s|\n\n", line2);

	//printf("MAIN RETURN:%d\n", get_next_line(4, &line2));
	//printf("line:|%s|\n\n", line2);

	printf("MAIN RETURN:%d\n", get_next_line(fd, &line));
	printf("line:|%s|\n\n", line);

	printf("MAIN RETURN:%d\n", get_next_line(fd, &line));
	printf("line:|%s|\n\n", line);

	printf("MAIN RETURN:%d\n", get_next_line(fd, &line));
	printf("line:|%s|\n\n", line);

	printf("MAIN RETURN:%d\n", get_next_line(fd, &line));
	printf("line:|%s|\n\n", line);

	printf("MAIN RETURN:%d\n", get_next_line(fd, &line));
	printf("line:|%s|\n\n", line);
	return (0);
}