# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 14:45:11 by siokim            #+#    #+#              #
#    Updated: 2022/07/20 17:29:13 by siokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -f
CFLAGS = -Werror -Wextra -Wall -Imlx 

SRCS = so_long.c

NAME = so_long
LIBS = ./libft/libft.a
LIB_NAME = libft

OBJS = $(SRCS:.c=.o)

.PHONY:all clean fclean re

all : $(NAME)

$(NAME): $(OBJS)
	make all -C $(LIB_NAME)
	$(CC) $(OBJS) -L./mlx -lmlx -framework OpenGL -framework AppKit $(LIBS) -o $(NAME)

fclean : clean
	$(RM) $(NAME) $(LIBS)

clean :
	make clean -C $(LIB_NAME)
	$(RM) $(OBJS)

re :
	make fclean
	make all