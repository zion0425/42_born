# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 14:45:11 by siokim            #+#    #+#              #
#    Updated: 2022/07/26 20:56:12 by siokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -f
CFLAGS = -Werror -Wextra -Wall -Imlx

SRCS = so_long.c map.c \
		./gnl/get_next_line_utils.c \
		./gnl/get_next_line.c

NAME = so_long
LIBS = ./libft/libft.a
LIBFT = libft
MLX = mlx
OBJS = $(SRCS:.c=.o)

.PHONY:all clean fclean re

all : $(NAME)

$(NAME): $(OBJS)
	make all -C $(LIBFT)
	make all -C $(MLX)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(LIBS) -o $(NAME)

fclean : clean
	$(RM) $(NAME) $(LIBS)

clean :
	make clean -C $(LIBFT)
	make clean -C $(MLX)
	$(RM) $(OBJS)

re :
	make fclean
	make all
