# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbamping <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/17 15:31:21 by kbamping          #+#    #+#              #
#    Updated: 2016/07/17 16:56:53 by kbamping         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG		= ft_select
FLAGS		= -Wall -Wextra -Werror -g3
LIBS		= -L ./libft -lft -ltermcap
INCLUDES	= -I ./include -I ./libft/include

SRCS		=	src/ft_select.c		\
				src/init.c			\
				src/terminal.c		\
				src/cursor.c		\
				src/error.c			\
				src/input.c			\
				src/output.c		\
				src/remove.c		\
				src/signals.c		\
				src/utils.c			\
				src/options.c		\
				src/key_funcs.c		\
				src/ft_nstrjoin.c	\

all: $(PROG)

$(PROG):
	@make -s -C libft all
	@gcc $(FLAGS) $(INCLUDES) $(SRCS) $(LIBS) -o $(PROG)
	@echo "\033[01;36m$(PROG) -- \033[00;32mMade '$(PROG)'\033[0m"

clean:
	@make -s -C libft clean

fclean: clean
	@make -s -C libft fclean
	@rm -f $(PROG)
	@echo "\033[01;36m$(PROG) -- \033[00;32mRemoved '$(PROG)'\033[0m"

re: fclean all

run:
	@rm -f $(PROG)
	@echo "\033[01;36m$(PROG) -- \033[00;32mRemoved '$(PROG)'\033[0m"
	@$(MAKE) -s all
