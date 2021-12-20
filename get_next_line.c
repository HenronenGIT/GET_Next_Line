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
		buf[read_ret] = '\0';

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
	size_t	nl_index;
	size_t	fd_len;
	size_t	temp_len;

	fd_len = ft_strlen(fd_arr[fd]);
	nl_index = find_eofl(fd_arr[fd]);
	printf("%zu\n", nl_index);

	// causes error//
	*line = ft_strnew(nl_index);
	temp_len = (fd_len - nl_index);
	temp = ft_strnew(temp_len);
	
	ft_memmove(*line, fd_arr[fd], nl_index);
	/*	DO WE NEED TEMP TO MOVE WHAT IS LEFT?	*/
	ft_memmove(temp, (ft_strchr(fd_arr[fd], '\n') + 1), fd_len);
	ft_strclr(fd_arr[fd]);
	/*	MIGHT NEED REALLOCATION - make seperate func?	*/
	fd_arr[fd] = temp;
	return ;
}

int	get_next_line(const int fd, char **line)
{
	static char	*fd_arr[MAX_FD];	//ADD	MAX_FD LATER
	char	buf[BUFF_SIZE + 1];
	size_t	i;

	i = 0;	
	ft_bzero(buf, BUFF_SIZE + 1);
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
	if (!(fd_arr[fd]))
		return (0);
	else
	{

		set_line(fd_arr, line, fd);
		//ft_memmove(*line, fd_arr[fd], ft_strlen(fd_arr[fd]));
	}
	return(0);
}
