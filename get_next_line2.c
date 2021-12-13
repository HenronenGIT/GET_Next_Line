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

int	get_next_line(const int fd, char **line)
{
	//static char	*sbuf[MAX_FD];
	char	temp[BUFF_SIZE + 1];
	char	*buf;
	size_t	i;

	i = 0;
	buf = ft_strnew(BUFF_SIZE);
	while (ft_strchr(temp, '\n') == '\0')
	{
		read(fd, temp, BUFF_SIZE);	
		printf("%s\n",temp);
		ft_strjoin(buf, temp);
		
		printf("%s\n", buf);
	}
	ft_strcpy(line[i], buf);
	
// Return 0, 1 or -1 depending if line was read was successful
return(fd);
}
