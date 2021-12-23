/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaronen <hmaronen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:12:49 by hmaronen          #+#    #+#             */
/*   Updated: 2021/12/09 13:12:50 by hmaronen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# define MAX_FD 4096
# define NOT_FOUND 0
# define FD_DONT_EXIST -1
# define END_OF_FILE 0
# define LINE_READ 1
# define FOUND 1
//# define EOF 2

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

int	get_next_line(const int fd, char **line);

#endif
