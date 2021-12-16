/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:12:40 by hmaronen          #+#    #+#             */
/*   Updated: 2021/12/15 10:12:41 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(const int fd, char **line)
{
	static char	*fd_arr[100];	//ADD	MAX_FD LATER
	char	buf[BUFF_SIZE + 1];
	int		read_ret;
	size_t	i;

	i = 0;
	read_ret = 0;

	//alotus tapaus check static buffer
	// lue vain jos bufferissa ei ole mitään
		read_ret = read(fd, buf, BUFF_SIZE);
	if (read_ret == 0)
		return (-1);

	fd_arr[i] = ft_strnew(BUFF_SIZE);
	ft_strcpy(fd_arr[i], buf);
	ft_strclr(buf);
	while (read_ret != 0)
	{
		if (ft_strchr(buf, '\t') != NOT_FOUND)
		{
			//ft_strsub	
			printf("found\n");
		}
		read_ret = read(fd, buf, BUFF_SIZE);
		fd_arr[i] = ft_strjoin(fd_arr[i], buf);
		ft_strclr(buf);
		printf("%d\n", read_ret);
	}

	printf("fd_arr:\t%s\n", fd_arr[0]);
	line = 0;
	return (0);
}