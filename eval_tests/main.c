/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:12:30 by hmaronen          #+#    #+#             */
/*   Updated: 2021/12/15 10:12:32 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "test.h"

int	main(void)
{
	int counter;

	counter = 0;
	if (arbitrary_fd() == 0)
		counter++;
	if (normal_with_newline() == 0)
		counter++;
	if (no_nl() == 0)
		counter++;
	if (double_fd() == 0)
		counter++;
	if (long_line() == 0)
		counter++;
	system("leaks get_next_line | grep LEAK");

	printf("%s [%d/%d] Tests passed\n",GREEN, counter, TEST_COUNT);
	printf(RESET);
	return(0);
}