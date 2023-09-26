# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 09:58:39 by qdenizar          #+#    #+#              #
#    Updated: 2023/09/19 09:59:33 by qdenizar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Brain

FILES = main

SRCS = $(FILES:=.cpp)

OBJS = ${SRCS:.cpp=.o}

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	@$(RM)  $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all