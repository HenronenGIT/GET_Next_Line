# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 11:57:35 by hmaronen          #+#    #+#              #
#    Updated: 2021/12/15 11:57:37 by hmaronen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ../get_next_line.c ./main.c
O_FILES = $(SRCS:.c=.o)
GCC = gcc
FLAGS = -Wall -Wextra -Werror
HEADERS = -I ../ -I ../libft/includes
LIB = ../libft/libft.a


all: 
	
	@@$(GCC) $(FLAGS) $(SRC) $(LIB) $(HEADERS)
clean:
	/bin/rm -f $(O_FILES)
fclean: clean
	/bin/rm a.out

re: fclean all
