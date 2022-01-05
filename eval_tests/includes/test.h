/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:03:40 by hmaronen          #+#    #+#             */
/*   Updated: 2021/12/09 15:03:52 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"
# include "colors.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>

# define TEST_COUNT 8

int		double_fd();
int		normal_with_newline();
int		no_nl();
int		arbitrary_fd();
int		long_line();

int		basic_tests();
int		basic_tests();
int		middle_tests();
int		advanced_tests();

#endif