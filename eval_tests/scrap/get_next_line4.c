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

static int	check_for_newline(char *str)
{
	if(!(str))
		return (0);
	if (ft_strchr(str, '\n') == NOT_FOUND)
		return (NOT_FOUND);
	else
		return (1);
}

static int	read_until_newline(int fd, char **fd_arr)
{
	ssize_t	bytes_read;
	char	buf[BUFF_SIZE + 1];
	
	bytes_read = 1;
	while (bytes_read != END_OF_FILE)
	{
		bytes_read = read(fd, buf, BUFF_SIZE);
		buf[bytes_read] = '\0';
		if (bytes_read == FD_DONT_EXIST)
			return (-1);
		if (!(fd_arr[fd]))
			fd_arr[fd] = ft_strdup(buf);
		else
			fd_arr[fd] = ft_strjoin(fd_arr[fd], buf);
		if (check_for_newline(fd_arr[fd]) == FOUND)
			return (1);
	}
	return (0);
}


static void	set_line(char **fd_arr, char **line, int fd)
{
	char	*temp;
	size_t	endofl_i;
	endofl_i = find_eofl(fd_arr[fd]);
	*line = ft_strndup(fd_arr[fd], find_eofl(fd_arr[fd]) - 1);
	temp = ft_strndup(ft_strchr(fd_arr[fd], '\n') + 1, endofl_i);
	if (temp == NULL)
		return ;

	/* REALLOCATION FOR FD_ARR?	*/
	else
	{

	ft_strclr(fd_arr[fd]);
	fd_arr[fd] = temp;
	return ;
	}
}
void	set_last_line(char **fd_arr, char **line, int fd)
{
	*line = ft_strndup(fd_arr[fd], ft_strlen(fd_arr[fd]));
	//free(fd_arr[fd]);
	return ;
}

int	get_next_line(const int fd, char **line)
{
	static char	*fd_arr[MAX_FD];
	ssize_t	read_return;

	if (fd < 0 || line == NULL)
		return (-1);
	if(check_for_newline(fd_arr[fd]) == FOUND)
	{
		set_line(fd_arr, line, fd);
		return (1);
	}
	read_return = read_until_newline(fd, fd_arr);
	if (read_return == LINE_READ)
	{
		set_line(fd_arr, line, fd);
		return (1);
	}
	if (read_return == END_OF_FILE)
	{
		set_last_line(fd_arr, line, fd);
		//ft_strclr(*line);
		return (0);
	}
	else
		return (-1);
}
