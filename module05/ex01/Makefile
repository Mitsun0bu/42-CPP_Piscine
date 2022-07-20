# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 18:13:55 by llethuil          #+#    #+#              #
#    Updated: 2022/07/20 14:35:01 by llethuil         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                              ~~~ COLOR CODES ~~~                             #
#                                                                              #
# **************************************************************************** #

GREEN	:=	\033[32m
BLUE	:=	\033[34m
PINK	:=	\033[35m
END		:=	\033[0m

# **************************************************************************** #
#                                                                              #
#                              ~~~ VARIABLES ~~~                               #
#                                                                              #
# **************************************************************************** #

NAME		:=	form

CC			:=	c++

CXXFLAGS	:=	-std=c++98 -Wall -Wextra -Werror

RM			:=	rm -f

OBJS_DIR	:=	.objs

SRCS_LST	:=	main.cpp		\
				Bureaucrat.cpp	\
				Form.cpp		\

INCS_LST	:=	Bureaucrat.hpp	\
				Form.hpp		\

OBJS_LST	:=	$(SRCS_LST:.cpp=.o)

OBJS		:=	$(addprefix $(OBJS_DIR)/, $(OBJS_LST))

# ************************************************************************** #
#                                                                            #
#                              ~~~ RULES & COMMANDS ~~~                      #
#                                                                            #
# ************************************************************************** #

.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	printf "$(BLUE)> Creating the executable file :$(END) $@\n"
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)
	printf "$(GREEN)> Executable file has been created successfully !$(END)\n"

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.cpp $(INCS_LST) Makefile | $(OBJS_DIR)
	printf "$(BLUE)> Compiling :$(END) $<\n"
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	printf "$(PINK)> Removing $(NAME) .o files ...$(END)\n"
	$(RM) $(OBJS)
	printf "$(PINK)> Removing .objs directory ...$(END)\n"
	rm -rf $(OBJS_DIR)
	printf "$(GREEN)> All the .o files have been removed successfully !$(END)\n"

fclean: clean
	printf "$(PINK)> Removing $(NAME) executable file ...$(END)\n"
	$(RM) $(NAME)
	printf "$(GREEN)> $(NAME) executable file has been removed successfully !$(END)\n"

re: fclean all

.PHONY: all clean fclean re