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
	ssize_t	read_ret;
	char	buf[BUFF_SIZE + 1];
	
	if (!(fd_arr[fd]))
		fd_arr[fd] = ft_strnew(BUFF_SIZE);
	read_ret = read(fd, buf, BUFF_SIZE);
	buf[read_ret] = '\0';
	if (read_ret == -1)
		return (-1);
	if (check_for_newline(buf) == NOT_FOUND)
		fd_arr[fd] = ft_strjoin(fd_arr[fd], buf);
	/*	COULD ADD SOMETHING ELSE HERE */
	if (read_ret == 0)
		return (0);
	if (check_for_newline(buf) != NOT_FOUND)
	{
		fd_arr[fd] = ft_strjoin(fd_arr[fd], buf);
		return (1);
	}
	ft_strclr(buf);
	return (read_until_newline(fd, fd_arr));
	//while (check_for_newline(buf) == NOT_FOUND)
	//{
		//read_ret = read(fd, buf, BUFF_SIZE);
		//buf[read_ret] = '\0';
		//if (read_ret == -1)
			//return(-1);
		//if (read_ret == 0)
			//return (0);
		//if (check_for_newline(buf) != NOT_FOUND)
			//break ;
		//fd_arr[fd] = ft_strjoin(fd_arr[fd], buf);
		//ft_strclr(buf);
	//}
	//fd_arr[fd] = ft_strjoin(fd_arr[fd], buf);
	//return (1);
}

static void	set_line(char **fd_arr, char **line, int fd)
{
	// test without clear line
	//ft_strclr(*line);
	
	char	*temp;
	size_t	nl_index;
	size_t	fd_len;
	size_t	temp_len;

	fd_len = ft_strlen(fd_arr[fd]);
	nl_index = find_eofl(fd_arr[fd]);

	// causes error//
	*line = ft_strnew(nl_index);
	temp_len = (fd_len - nl_index);
	
	ft_memmove(*line, fd_arr[fd], nl_index);
	/*	DO WE NEED TEMP TO MOVE WHAT IS LEFT?	*/
	temp = ft_strnew(temp_len);
	ft_memmove(temp, (ft_strchr(fd_arr[fd], '\n') + 1), fd_len);
	ft_strclr(fd_arr[fd]);
	/*	MIGHT NEED REALLOCATION - make seperate func?	*/
	fd_arr[fd] = temp;
	return ;
}

int	get_next_line(const int fd, char **line)
{
	static char	*fd_arr[MAX_FD];
	size_t	fd_len;
	ssize_t	read_return;

	if (fd < 3)
		return (-1);
	fd_len = 0;
	if(check_for_newline(fd_arr[fd]))
	{
		set_line(fd_arr, line, fd);
		return (1);
	}
	read_return = read_until_newline(fd, fd_arr);
	if (read_return == -1)
		return (-1);
	else if(read_return == 1)
	{
		set_line(fd_arr, line, fd);
		return (1);
	}
	/*	END OF THE FILE	*/
	else
	{
		//sub func "end of file"
		fd_len = ft_strlen(fd_arr[fd]);
		*line = ft_strnew(fd_len);
		ft_memmove(*line, fd_arr[fd], fd_len);
		ft_memdel((void **)&fd_arr[fd]);
		return (0);
	}
}
