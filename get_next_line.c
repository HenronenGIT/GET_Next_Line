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

/* CAN ADD TO LIBRARY AS WELL */
static int	find_eofl(char *s)
{
	size_t	j;

	j = 0;
	while (s[j] != '\n')
		j++;
	return (j);
}

int	get_next_line(const int fd, char **line)
{
	static char *fd_array[MAX_FD];/* Holds all fd:s */
	char	temp[BUFF_SIZE + 1]; /*read() reads here*/
	int		read_ret; /* loop end condition */
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	read_ret = 1;
	while (read_ret != 0)
	{
		if (!(fd_array[i]))
			fd_array[i] = ft_strnew(BUFF_SIZE);

		read_ret = read(fd, temp, BUFF_SIZE);
		//printf("temp after read:%s\n", temp);
		if (ft_strchr(temp, '\n') != '\0')
		{
			while (temp[j] != '\n')
				j++;			
			//printf("trimmed temp:%s\n", ft_strtrim(temp));
			//fd_array[i] = ft_strjoin(fd_array[i], ft_strtrim(temp));
			// FUNCTION TO RETURN SUB STR TO TEMP - 1
			fd_array[i] = ft_strjoin(fd_array[i], ft_strsub(temp, 0, find_eofl(temp)));
		
			/* add fd_array to line?*/
			ft_strcpy(line[i], fd_array[i]);
			i++;
			break ;
		}
		fd_array[i] = ft_strjoin(fd_array[i], temp);
		ft_strclr(temp);
	}
	printf("Final:%s| END OF THE LINE\n", fd_array[0]);
	//ft_print_array(fd_array);
	// return 0, -1 or 1
	return (0);
}
