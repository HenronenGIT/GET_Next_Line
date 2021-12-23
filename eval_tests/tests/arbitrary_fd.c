/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arbitrary_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:35:35 by hmaronen          #+#    #+#             */
/*   Updated: 2021/12/23 12:35:37 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void arbitrary_fd()
{
	int		fd;
	char	*line;

	line = NULL;
	fd = 21;
	printf("Return value:|%d|\n", get_next_line(fd, &line));
	printf("%s\n", line);
	return ;
}