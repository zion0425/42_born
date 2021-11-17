# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 04:40:59 by siokim            #+#    #+#              #
#    Updated: 2021/11/16 21:36:01 by siokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_b_zero.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_memcpy.c ft_memset.c ft_strchr.c \
		ft_strjoin.c ft_strlen.c ft_strrchr.c \
		ft_substr.c ft_tolower.c ft_toupper.c \
		ft_strncmp.c ft_strchr.c

AR = ar

TARGET = libft.a
OBJS = $(SRCS:.c=.o)

NAME = libft.a

RMFLAGS = -rf

.PHONY:all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
