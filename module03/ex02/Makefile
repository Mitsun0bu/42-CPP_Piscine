# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 18:18:50 by llethuil          #+#    #+#              #
#    Updated: 2022/07/13 19:18:28 by llethuil         ###   ########lyon.fr    #
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

NAME		:=	frag_trap

CC			:=	c++

CXXFLAGS	:=	-std=c++98 -Wall -Wextra -Werror

RM			:=	rm -f

OBJS_DIR	:=	.objs

DEPS_DIR	:=	.deps

MV			:=	mv $(OBJS_DIR)/*.d ./$(DEPS_DIR)/

SRCS_LST	:=	main.cpp		\
				ClapTrap.cpp	\
				ScavTrap.cpp	\
				FragTrap.cpp	\

INCS_LST	:=	ClapTrap.hpp	\
				ScavTrap.hpp	\
				FragTrap.cpp	\

OBJS_LST	:=	$(SRCS_LST:.cpp=.o)

DEPS_LST	:=	$(OBJS_LST:.o=.d)

OBJS		:=	$(addprefix $(OBJS_DIR)/, $(OBJS_LST))

DEPS		:=	$(addprefix $(DEPS_DIR)/, $(DEPS_LST))

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

${DEPS_DIR}/%.d: ${SRCS_DIR}/%.cpp Makefile | ${DEPS_DIR}
	${CC} ${FLAGS} -MM -MF $@ -MT "${OBJS_DIR}/$*.o $@" $<

$(OBJS_DIR)/%.o: %.cpp $(INCS_LST) Makefile | $(OBJS_DIR)
	printf "$(BLUE)> Compiling :$(END) $<\n"
	$(CC) $(CXXFLAGS) -c $< -o $@

$(DEPS_DIR):
	mkdir -p $(DEPS_DIR)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)



# move:
# ifneq ($(wildcard $(DEPS_DIR)),)
# 	echo "Found"
# else
# 	echo "Not found"
# 	mkdir -p $(DEPS_DIR) && mv $(OBJS_DIR)/*.d $(DEPS_DIR)/
# endif

clean:
	printf "$(PINK)> Removing $(NAME) .o files ...$(END)\n"
	$(RM) $(OBJS)
	printf "$(PINK)> Removing .objs directory ...$(END)\n"
	rm -rf $(OBJS_DIR) $(DEPS_DIR)
	printf "$(GREEN)> All the .o files have been removed successfully !$(END)\n"

fclean: clean
	printf "$(PINK)> Removing $(NAME) executable file ...$(END)\n"
	$(RM) $(NAME)
	printf "$(GREEN)> $(NAME) executable file has been removed successfully !$(END)\n"

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)