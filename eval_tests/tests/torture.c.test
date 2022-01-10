/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:17:24 by hmaronen          #+#    #+#             */
/*   Updated: 2021/12/29 22:17:26 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "test.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("./test_files/torture.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() failed torture.c");
		return (1);
	}
	while (get_next_line(fd, &line) != 2)
	{
		get_next_line(fd, &line);
		printf("%s\n", line);
		if ((get_next_line(fd, &line) == 0))
		{
			close (fd);
			fd = open("./test_files/torture.txt", O_RDONLY);
		}
	}
}