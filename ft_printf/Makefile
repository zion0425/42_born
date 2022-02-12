# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 19:17:23 by siokim            #+#    #+#              #
#    Updated: 2022/02/12 17:39:23 by siokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = GCC
#CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rc
NAME = libftprintf.a
LIB_NAME = libft
SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

.PHONY:all clean fclean re
all: $(NAME)

$(NAME) : $(OBJS)
	make all -C $(LIB_NAME)
	cp ./libft/$(LIB_NAME).a ./$(NAME)
	#test
	#$(AR) $(ARFLAGS)
	$(CC) $(CCFLAGS) $(NAME) $(OBJS)

fclean: clean
	#test
	rm -f $(NAME)
	rm -r ./a.out

clean:
	make clean -C $(LIB_NAME)
	rm -f $(OBJS)

re: fclean all
