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

int	arbitrary_fd()
{
	int		fd;
	char	*line;
	int		ret;
	int		fail;
	
	fail = 0;
	ret = 0;
	line = NULL;
	fd = 21;
	ret = get_next_line(fd, &line);
	if (line != NULL || ret != -1)
	{
		printf("%sarbitrary test FAIL\tline = %s\n", RED, line);
		printf(RESET);
		fail = 1;
	}
	free(line);
	line = NULL;

	/*	MAX_FD TEST	*/
	fd = 999999;
	ret = get_next_line(fd, &line);
	if (ret != -1)
	{
		printf("%sarbitrary test FAIL\nline = |%s|\ngnl_ret = %d",RED, line, ret);
		printf(RESET);
	}
	return (fail);
}