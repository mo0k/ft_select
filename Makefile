# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2016/08/14 13:07:25 by jmoucade          #+#    #+#             #
#   Updated: 2016/08/17 03:05:31 by jmoucade         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME = ft_select

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC_PATH = includes

SRC_PATH = sources

SRC =	$(SRC_PATH)/ft_select.c			\
		$(SRC_PATH)/input.c				\
		$(SRC_PATH)/error.c			\
		$(SRC_PATH)/init.c			\
		$(SRC_PATH)/actions/delete.c	\
		$(SRC_PATH)/actions/esc.c	\
		$(SRC_PATH)/actions/jump.c	\
		$(SRC_PATH)/actions/move.c	\
		$(SRC_PATH)/actions/return.c	\
		$(SRC_PATH)/actions/select.c	\
		$(SRC_PATH)/display/print.c				\
		$(SRC_PATH)/display/display.c			\
		$(SRC_PATH)/keyboard/handler.c				\
		$(SRC_PATH)/keyboard/termios.c				\
		$(SRC_PATH)/search/do_search.c	\
		$(SRC_PATH)/search/del_char.c				\
		$(SRC_PATH)/search/quit_mode.c				\
		$(SRC_PATH)/signals/handler.c				\
		$(SRC_PATH)/signals/catch.c				\
		$(SRC_PATH)/utils/my_isprint.c			\
		$(SRC_PATH)/utils/my_putchar.c			\
		$(SRC_PATH)/utils/stock.c

OSRC = $(SRC:.c=.o)

LIB_PATH = libft
LIB = libft/libft.a

NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m

all: $(NAME)

$(NAME): $(LIB) $(OSRC)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OSRC) -o $@ -L $(LIB_PATH) -lft -lncurses
	@echo "$(OK_COLOR)$@ compiled.$(NO_COLOR)"

$(LIB):
	@echo "Compiling libft..."
	@make -C $(LIB_PATH)
	@echo "Librairy compiled."

%.o: %.c
	@$(CC) $(CFLAGS) -I $(LIB_PATH)/$(INC_PATH) -I $(INC_PATH) -c -o $@ $?
	@echo "Linking file $@"

clean:
	@make clean -C $(LIB_PATH)
	@/bin/rm -f $(OSRC)
	@echo "Cleaning temporary files."

fclean: clean
	@make fclean -C $(LIB_PATH)
	@/bin/rm -f $(NAME)
	@echo "Delete $(NAME) file."

re: fclean all

.PHONY: all clean fclean re