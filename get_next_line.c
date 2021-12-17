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

int	check_for_newline(char *str)
{
	if (ft_strchr(str, '\n') == NOT_FOUND)
		return (NOT_FOUND);
	else
		return (1);
}

void	read_until_newline(int fd, char *buf, char **fd_arr)
{
		//test without
	ft_strclr(buf);
	while (check_for_newline(buf) == NOT_FOUND)
	{
		read(fd, buf, BUFF_SIZE);
		//printf("%s\n", buf);
		if (check_for_newline(buf) != NOT_FOUND)
			break ;

		//fd_arr[fd] = ft_strjoin(fd_arr[fd], ft_strtrim(buf));
		fd_arr[fd] = ft_strjoin(fd_arr[fd], buf);
		//printf("|%s|\n", fd_arr[fd]);
		ft_strclr(buf);
	}	
}

static char	**set_line(char **fd_arr, char **line, char *buf, int fd)
{
	ft_strclr(*line);
	if (check_for_newline(fd_arr[fd]))
		ft_memmove(*line, fd_arr[fd], find_eofl(fd_arr[fd]));
	else
	{
	*line = ft_strjoin(fd_arr[fd], ft_strsub(buf, 0, find_eofl(buf)));
	//fd_arr[fd] = ft_strjoin(fd_arr[fd], ft_strsub(buf, 0, find_eofl(buf)));
	}

		ft_strclr(fd_arr[fd]);
		fd_arr[fd] = ft_strsub(buf, find_eofl(buf) + 1, (BUFF_SIZE - find_eofl(buf)) );
		return (line);
	//printf("last_buff() fd_arr[fd]:|%s|\n", fd_arr[fd]);
}

int	get_next_line(const int fd, char **line)
{
	static char	*fd_arr[MAX_FD];	//ADD	MAX_FD LATER
	char	buf[BUFF_SIZE + 1];
	int		read_ret;
	size_t	i;

	i = 0;
	read_ret = 0;
	// If fd array dont exist - read first time - check if read is empty - 
	if (!(fd_arr[fd]))
	{
		//need to strnew for strjoin to work - add to declaration?
		fd_arr[fd] = ft_strnew(BUFF_SIZE);
		read_ret = read(fd, buf, BUFF_SIZE);
		if (read_ret == 0)
			return (-1);
	if (check_for_newline(buf))
	{
		line = set_line(fd_arr, line, buf, fd);
		return (1);
	}
		else// pilataan toisen kierroksen jatetyt luvut talla
			ft_strcpy(fd_arr[fd], buf);
	}
	if (check_for_newline(fd_arr[fd]))
	{
		set_line(fd_arr, line, buf, fd);
		return (1);
	}

	
	read_until_newline(fd, buf, fd_arr);
	line = set_line(fd_arr, line, buf, fd);
	
	return (1);
}
