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
	int pass;

	pass = 0;
	if (arbitrary_fd() == 0)
		pass++;
	if (normal_with_newline() == 0)
		pass++;
	if (no_nl() == 0)
		pass++;
	if (long_line() == 0)
		pass++;
	if (basic_tests() == 0)
		pass++;
	if(middle_tests() == 0)
		pass++;
	if(advanced_tests() == 0)
		pass++;
	if (double_fd() == 0)
		pass++;
	system("leaks get_next_line | grep LEAK");
	printf("%s [%d/%d] Tests passed\n",GREEN, pass, TEST_COUNT);
	printf(RESET);
	return(0);
}