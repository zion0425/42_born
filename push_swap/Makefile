# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 15:13:42 by siokim            #+#    #+#              #
#    Updated: 2022/06/02 14:01:44 by siokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CCFLAGS = -o #-Werror -Wextra -Wall
LIB_NAME = libft

SRCS = push_swap.c input_check.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap

.PHONY:all clean fclean re
all: $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIB_NAME)
	mv $(LIB_NAME)/$(LIB_NAME).a ./
	$(CC) $(CCFLAGS) $(NAME) $(OBJS) $(LIB_NAME).a
	chmod 755 $(NAME)

fclean: clean
	rm -f $(NAME) $(LIB_NAME).a

clean:
	make clean -C $(LIB_NAME)
	rm -f $(OBJS)

re: fclean all
