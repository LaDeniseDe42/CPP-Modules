# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdenizar <qdenizar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 11:38:07 by qdenizar          #+#    #+#              #
#    Updated: 2023/10/18 11:44:57 by qdenizar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AMateria

FILES = main AMateria Ice Cure

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