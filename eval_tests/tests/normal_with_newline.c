/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_normal_with_newline.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:40:36 by hmaronen          #+#    #+#             */
/*   Updated: 2021/12/22 15:40:37 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	normal_with_newline()
{
	int		fd;
	size_t	i;
	char	*line;

	i = 0;
	//fd = open("normal_with_newline.txt", O_RDONLY);
	fd = open("./test_files/normal_with_newline.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open () error in normal_with_newline test!\n");
		return ;
	}

	while (i <= 2)
	{
		printf("RET|%d|\n",get_next_line(fd, &line));
		printf("|%s|\n\n", line);
		i++;
	}

	//printf("Normal test!\n");
	//printf("MAIN RETURN:%d\n", get_next_line(fd, &line));
	//printf("line:|%s|\n\n", line);

	//printf("MAIN RETURN:%d\n", get_next_line(fd, &line));
	//printf("line:|%s|\n\n", line);

	//printf("MAIN RETURN:%d\n", get_next_line(fd, &line));
	//printf("line:|%s|\n\n", line);

	//printf("MAIN RETURN:%d\n", get_next_line(fd, &line));
	//printf("line:|%s|\n\n", line);
	close(fd);
}