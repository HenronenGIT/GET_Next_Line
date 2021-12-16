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

static int	find_eofl(char *s)	//COULD ADD TO LIBFT
{
	size_t	j;

	j = 0;
	while (s[j] != '\n')
		j++;
	return (j);
}

int	check_for_newline(char *str)
{
	if (ft_strchr(str, '\n') == NOT_FOUND)
		return (NOT_FOUND);
	else
		return (1);
}

void	read_until_newline(int fd, char *buf, char **fd_arr)
{
	ft_strclr(buf);
	//printf("newline return:|%d|\n", check_buf_newline(buf));
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

static char	**last_buffer(char **fd_arr, char **line, char *buf, int fd)
{
	
	fd_arr[fd] = ft_strjoin(fd_arr[fd], ft_strsub(buf, 0, find_eofl(buf)));
	
	//printf("%sbuf in last_buffer:|%s|\n", GREEN, buf);
	//printf("%sfd_arr[fd] in last_buffer:|%s|\n",GREEN, fd_arr[fd]);
	printf(RESET);

	*line = ft_strdup(fd_arr[fd]);
	ft_strclr(fd_arr[fd]);
	printf("%s\n", buf);
	fd_arr[fd] = ft_strsub(buf, 0, BUFF_SIZE);


	//printf("last_buff() fd_arr[fd]:|%s|\n", fd_arr[fd]);
	return(line);
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
	}
	//HERE
	if (check_for_newline(buf))
	{
		printf("%sfirst buf had NL\n", GREEN);
		printf(RESET);

		line = last_buffer(fd_arr, line, buf, fd);
		return (1);
	}
	else
		ft_strcpy(fd_arr[fd], buf);
	read_until_newline(fd, buf, fd_arr);
	line = last_buffer(fd_arr, line, buf, fd);
	
	return (1);
}
