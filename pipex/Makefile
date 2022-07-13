# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 19:39:03 by siokim            #+#    #+#              #
#    Updated: 2022/07/08 16:28:25 by siokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -f
CFLAGS = -Werror -Wextra -Wall

SRCS = pipex.c
OBJS = $(SRCS:.c=.o)

NAME = pipex
LIBS = ./libft/libft.a
LIB_NAME = libft

.PHONY:all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIB_NAME)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

fclean : clean
	$(RM) $(NAME) $(LIBS)

clean :
	make clean -C $(LIB_NAME)
	$(RM) $(OBJS)

re : fclean all
