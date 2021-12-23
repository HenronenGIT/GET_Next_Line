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

/*	replace_newline() function iterates trough string and replaces
	all '\n' characters. If no '\n' characters was encountered return
	value is 0. If even one '\n\ characters was replaced return value
	is 1
*/

//int	replace_newline(char **line)
//{
//	size_t	i;
//	int		ret;
//
//	ret = 0;
//	i = 0;
//	printf("%c\n", *line[i]);
//	while (*line[i] != '\0')
//	{
//		if (*line[i] == '\n')
//		{
//			*line[i] = '\0';
//			ret = 1;
//		}
//		i++;
//	}
//	return (ret);
//}

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

	//ft_strclr(*line);
	len = ft_strlen(fd_arr[fd]);
	line_len = find_eofl(fd_arr[fd]);


	*line = ft_strndup(fd_arr[fd], find_eofl(fd_arr[fd]) - 1);

	//replace_newline(line);
	temp = ft_strndup(ft_strchr(fd_arr[fd], '\n') + 1, (len - line_len));
	free(fd_arr[fd]);
	fd_arr[fd] = ft_strdup(temp);
	free(temp);
}

int	read_until_newline(int fd, char **fd_arr)
{
	char	buf[BUFF_SIZE + 1];
	int		bytes_read;

	while (check_newline(fd_arr[fd]) == NOT_FOUND)
	{
		bytes_read = read(fd, buf, BUFF_SIZE);
		buf[bytes_read] = '\0';
		if (!(fd_arr[fd]))
			fd_arr[fd] = ft_strdup(buf);
		else
		{
			fd_arr[fd] = ft_strjoin(fd_arr[fd], buf);
		}
		if (bytes_read == 0)
		{
			return (0);
		}
	}
		return (1);
}

int	get_next_line(int fd, char **line)
{
	int	read_return;
	static char	*fd_arr[MAX_FD];

	if (fd < 3)
		return (-1);
	read_return = read_until_newline(fd, fd_arr);
	if (read_return == 1)
		set_line(fd, fd_arr, line);
	if (read_return == 0)
	{
		ft_strclr(*line);
		return (0);
	}
	else
		return (1);
}