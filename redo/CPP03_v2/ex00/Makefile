# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbolon <kbolon@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/05 19:15:00 by kbolon            #+#    #+#              #
#    Updated: 2025/03/28 15:34:42 by kbolon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap

SRCS = 	main.cpp ClapTrap.cpp

CC = c++
OBJS = $(SRCS:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re