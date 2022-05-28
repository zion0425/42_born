# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 15:13:42 by siokim            #+#    #+#              #
#    Updated: 2022/05/27 04:18:39 by sion             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CCFLAGS = -o #-Werror -Wextra -Wall
LIB_NAME = libft

SRCS = push_swap.c
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
	make fclean -C $(LIB_NAME)
	rm -f $(NAME)

clean:
	make clean -C $(LIB_NAME)
	rm -f $(OBJS)

re: fclean all
