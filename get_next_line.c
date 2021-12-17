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

int	read_until_newline(int fd, char *buf, char **fd_arr)
{
	int	read_ret;
		//test without
	//ft_strclr(buf);
	while (check_for_newline(buf) == NOT_FOUND)
	{
		read_ret = read(fd, buf, BUFF_SIZE);
		if (read_ret == 0)
			return (0);
		if (check_for_newline(buf) != NOT_FOUND)
			break ;
		fd_arr[fd] = ft_strjoin(fd_arr[fd], buf);
		ft_strclr(buf);
	}
	fd_arr[fd] = ft_strjoin(fd_arr[fd], buf);
	return (1);
	
}

static void	set_line(char **fd_arr, char **line, int fd)
{
	// test without clear line
	ft_strclr(*line);
	char	*temp;
	size_t	new_line;
	size_t	len;	

	temp = NULL;
	len = ft_strlen(fd_arr[fd]);
	new_line = find_eofl(fd_arr[fd]);

	//*line = ft_strsub(fd_arr[fd], 0, new_line);
	//*line = ft_memalloc(new_line);
	ft_memmove(*line, fd_arr[fd] ,new_line);
	if ((len - new_line) != 1)
	{
		temp = ft_strsub(fd_arr[fd], new_line + 1, (len - new_line));
		ft_strclr(fd_arr[fd]);
		fd_arr[fd] = temp;
		free(temp);
		return ;
	}

	ft_bzero(fd_arr[fd], len);
	return ;
}

int	get_next_line(const int fd, char **line)
{
	static char	*fd_arr[MAX_FD];	//ADD	MAX_FD LATER
	char	buf[BUFF_SIZE + 1];
	int		read_ret;
	size_t	i;

	ft_bzero(buf, BUFF_SIZE + 1);
	i = 0;
	read_ret = 0;
	
	if (!(fd_arr[fd]))
		fd_arr[fd] = ft_strnew(BUFF_SIZE);
	if(check_for_newline(fd_arr[fd]))
	{
		set_line(fd_arr, line, fd);
		return (1);
	}

	if(read_until_newline(fd, buf, fd_arr))
	{
		set_line(fd_arr, line, fd);
		return (1);
	}
	else
		return(0);
}
