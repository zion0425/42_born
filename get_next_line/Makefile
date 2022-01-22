# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 14:59:31 by siokim            #+#    #+#              #
#    Updated: 2022/01/22 19:58:29 by siokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
BUFFER = 42
NAME = ./a.out

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

.PHONY:all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER) $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

