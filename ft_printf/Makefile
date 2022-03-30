# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 19:17:23 by siokim            #+#    #+#              #
#    Updated: 2022/03/11 14:50:53 by siokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wextra -Werror -Wall
AR = ar
ARFLAGS = -rc
NAME = libftprintf.a
LIB_NAME = libft
SRCS = ft_printf.c ft_hex_print.c ft_unsigned_itoa.c

OBJS = $(SRCS:.c=.o)

.PHONY:all clean fclean re
all: $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIB_NAME)
	cp ./$(LIB_NAME)/$(LIB_NAME).a ./$(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

fclean: clean
	make fclean -C $(LIB_NAME)
	rm -f $(NAME)

clean:
	make clean -C $(LIB_NAME)
	rm -f $(OBJS)

re: fclean all
