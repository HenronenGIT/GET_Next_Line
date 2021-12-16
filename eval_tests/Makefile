# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmaronen <hmaronen@student.Hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 11:57:35 by hmaronen          #+#    #+#              #
#    Updated: 2021/12/15 13:55:05 by hmaronen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRC = ../get_next_line.c ./main.c
O_FILES = $(SRCS:.c=.o)
GCC = gcc
FLAGS = -Wall -Wextra -Werror
HEADERS = -I ./includes -I ../libft/includes -I ../
LIB = ../libft/libft.a


all:
	@@$(GCC) $(FLAGS) $(SRC) $(LIB) $(HEADERS)

clean:
	/bin/rm -f $(O_FILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

run:
	@@./$(NAME)

debug:
	$(GCC) -g $(FLAGS) $(SRC) $(LIB) $(HEADERS)
	lldb

#debug clean:
#	/bin/rm -rf a.out.dSYM

.PHONY: all clean fclean re