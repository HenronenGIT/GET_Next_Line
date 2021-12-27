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

int	check_newline(char *str)
{
	if (!(str))
		return (0);
	if (ft_strchr(str, '\n') != NOT_FOUND)
		return (1);
	else
		return (0);
}

void	set_line(int fd, char **fd_arr, char **line)
{
	char	*temp;
	int		len;
	int		line_len;

	len = ft_strlen(fd_arr[fd]);
	line_len = find_eofl(fd_arr[fd]);
	//if (fd_arr[fd][0] == '\n')
	//	return ;
	*line = ft_strndup(fd_arr[fd], find_eofl(fd_arr[fd]) - 1);
	if (**line == '\n')//
		ft_memdel((void **)line);//
	temp = ft_strndup(ft_strchr(fd_arr[fd], '\n') + 1, (len - line_len));
	free(fd_arr[fd]);
	fd_arr[fd] = ft_strdup(temp);
	free(temp);
}

	/*free all?* - LINE 43*/
void	set_last_line(int fd, char **fd_arr, char **line)
{
	*line = ft_strdup(fd_arr[fd]);
}

int	read_until_newline(int fd, char **fd_arr)
{
	char	buf[BUFF_SIZE + 1];
	int		bytes_read;

	while (check_newline(fd_arr[fd]) == NOT_FOUND)
	{
		//ft_bzero(buf, BUFF_SIZE);
		bytes_read = read(fd, buf, BUFF_SIZE);
		buf[bytes_read] = '\0';
		if (bytes_read == -1)//
			return (-1);//
		if (!(fd_arr[fd]))
			fd_arr[fd] = ft_strdup(buf);
		else
		{
			ft_realloc(&fd_arr[fd], buf);
			//fd_arr[fd] = ft_strjoin(fd_arr[fd], buf);
		}
		if (bytes_read == 0)
			return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*fd_arr[MAX_FD];
	int			read_return;

	if (fd < 0 || line == NULL)
		return (-1);
	read_return = read_until_newline(fd, fd_arr);
	if (read_return == -1)
		return (-1);
	if (read_return == 1)
		set_line(fd, fd_arr, line);
	if (read_return == 0)
	{
		set_last_line(fd, fd_arr, line);
		return (0);
		free(fd_arr[fd]);//
	}
	else
		return (1);
}
