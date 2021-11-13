# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 04:40:59 by siokim            #+#    #+#              #
#    Updated: 2021/11/09 21:25:44 by siokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
SRCS = 
TARGET = 

OBJS = $(SRCS:.c=.o)

.PHONY:all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
