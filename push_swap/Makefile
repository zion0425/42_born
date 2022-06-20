# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 15:13:42 by siokim            #+#    #+#              #
#    Updated: 2022/06/20 01:19:50 by siokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

LIBS = ./libft/libft.a
LIB_NAME = libft
CFLAGS = -Werror -Wextra -Wall -g

OBJS = $(SRCS:.c=.o)
SRCS = push_swap.c input_check.c sort_stack.c \
		find_pivot.c real_sorting.c reverse_rotate_argv.c

#reverse_rotate_argv.c \
#		sort_five_or_less.c
NAME = push_swap

.PHONY:all clean fclean re

all: $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIB_NAME)
	make bonus -C $(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

fclean: clean
	rm -f $(NAME) $(LIBS)

clean:
	make clean -C $(LIB_NAME)
	rm -f $(OBJS)

re: fclean all
