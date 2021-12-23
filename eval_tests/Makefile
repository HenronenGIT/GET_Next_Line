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

NAME = get_next_line

#Compilation and flags
CC = gcc
FLAGS = -Wall -Wextra -Werror

#Source files
SRC = ../get_next_line.c ./main.c		\
$(TEST_PATH)/test_normal_with_newline.c	\
$(TEST_PATH)/test_no_nl.c
OBJ = $(SRC:.c=.o)
TEST_PATH = ./tests

#Includes
HEADERS = $(GNL_H) $(LIBFT_H) $(TEST_H)
GNL_H = -I ../
LIBFT_H = -I ../libft/includes
TEST_H = -I ./includes

#Library
LIB = -L ../libft -lft

#Remove
RM = /bin/rm -f

all: $(NAME)

$(NAME): $(SRC)
	@@make -C ../libft/ fclean && make -C ../libft/
	@@$(CC) $(FLAGS) $(HEADERS) $(LIB) $(SRC) -o $(NAME)

clean:
	@@$(RM) $(OBJ)

fclean: clean
	@@/bin/rm -f $(NAME)

re: fclean all

run:
	@@./$(NAME)

debug:
	$(CC) -g $(FLAGS) $(SRC) $(LIB) $(HEADERS)
	lldb

.PHONY: all clean fclean re