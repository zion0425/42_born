# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 14:44:33 by siokim            #+#    #+#              #
#    Updated: 2022/07/30 15:49:48 by siokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

NAME = philo

SRCS = philo.c
OBJS = $(SRCS:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJS)

re :
	make fclean
	make all