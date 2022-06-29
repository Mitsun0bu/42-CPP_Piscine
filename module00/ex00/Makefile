# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 11:45:34 by llethuil          #+#    #+#              #
#    Updated: 2022/06/29 12:04:46 by llethuil         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                              ~~~ VARIABLES ~~~                               #
#                                                                              #
# **************************************************************************** #

NAME		:=	magaphone

CC			:=	c++

CXXFLAGS	:=	-std=c++98 -Wall -Wextra -Werror

RM			:=	rm -f

OBJS_DIR	:=	.objs

SRCS_LST	:=	megaphone.cpp

OBJS_LST	:=	$(SRCS_LST:.cpp=.o)

OBJS		:=	$(addprefix $(OBJS_DIR)/, $(OBJS_LST))

# ************************************************************************** #
#                                                                            #
#                              ~~~ RULES & COMMANDS ~~~                      #
#                                                                            #
# ************************************************************************** #

# .SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	test -z '$(filter %.o,$?)' || printf "$(GREEN)> All the .c files from $(NAME) have been compiled successfully !$(END)\n"
	printf "$(BLUE)> Creating the executable file :$(END) $@\n"
	$(CC) $(CXXFLAGS) $(OBJS_LST) -o $(NAME)
	printf "$(GREEN)> Executable file has been created successfully !$(END)\n"

$(OBJS_DIR):
	mkdir -p $(addprefix $(OBJS_DIR)/, $(SUBDIRS_LST))

clean:
	printf "$(PINK)> Removing $(NAME) .o files ...$(END)\n"
	$(RM) $(OBJS)
	printf "$(PINK)> Removing .objs directory ...$(END)\n"
	$(RM) $(OBJS_DIR)
	printf "$(GREEN)> All the .o files have been removed successfully !$(END)\n"

fclean: clean
	printf "$(PINK)> Removing $(NAME) executable file ...$(END)\n"
	$(RM) $(NAME)
	printf "$(GREEN)> $(NAME) executable file has been removed successfully !$(END)\n"

re: fclean all

.PHONY: all clean fclean re