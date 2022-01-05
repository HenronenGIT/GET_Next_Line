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
	int		pass;
	
	pass = 0;
	ret = 0;
	line = NULL;
	fd = 21;
	ret = get_next_line(fd, &line);
	if (line != NULL)
	{
		printf("%sarbitrary test FAIL\tline = %s\n", RED, line);
		printf(RESET);
		pass = 1;
	}
	if (ret != -1)
	{
		printf("%sarbitrary test FAIL\n", RED);
		printf("Return value was:|%d|\n", ret);
		printf(RESET);
		pass = 1;
	}
	free(line);
	line = NULL;
	return (pass);
}