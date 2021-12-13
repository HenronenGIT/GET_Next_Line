/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:12:40 by hmaronen          #+#    #+#             */
/*   Updated: 2021/12/09 13:12:43 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>//TEMP

int	get_next_line(const int fd, char **line)
{
	char	temp[BUFF_SIZE + 1];
	size_t	i;
	int		read_ret;

	i = 0;
	read_ret = 1;
	while (read_ret != 0)
	{
		read_ret = read(fd, temp, BUFF_SIZE);
		printf("%s\n", temp);
		printf("%d\n", read_ret);
	}
	line = 0;
	// return 0, -1 or 1
	return (0);
}
