# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 04:40:59 by siokim            #+#    #+#              #
#    Updated: 2021/12/15 10:10:36 by siokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = -rc
NAME = libft.a

SRCS = ft_bzero.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c \
		 ft_memset.c ft_strchr.c ft_calloc.c\
		ft_strjoin.c ft_strlen.c ft_strrchr.c \
		ft_substr.c ft_tolower.c ft_toupper.c \
		ft_strncmp.c ft_strchr.c ft_atoi.c \
		ft_memcpy.c ft_memmove.c

OBJS = $(SRCS:.c=.o)

.PHONY:all clean fclean re

all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all



