# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 09:23:22 by qdenizar          #+#    #+#              #
#    Updated: 2023/11/03 14:32:18 by qdenizar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Convertor

FILES = main ScalarConverter

SRCS = $(FILES:=.cpp)

OBJS = ${SRCS:.cpp=.o}

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
	@$(RM)  $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
