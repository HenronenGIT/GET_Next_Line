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

void	test_no_nl()
{
	int		fd;
	char	*line;

	fd = 0;
	fd = open("no_nl.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() error in test_no_nl\n");
		return ;
	}

	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	close (fd);
}
