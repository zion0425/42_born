# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 19:17:23 by siokim            #+#    #+#              #
#    Updated: 2022/02/10 20:26:03 by siokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = GCC
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rc
NAME = ft_printf.a

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

.PHONY:all clean fclean re
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all
