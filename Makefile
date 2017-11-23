# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 17:53:51 by mo0ky             #+#    #+#              #
#    Updated: 2017/11/23 23:39:07 by mo0ky            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = players/test.filler

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3

INC_PATH = includes

INC =	$(INC_PATH)/filler.h

SRC_PATH = sources

SRC =	$(SRC_PATH)/filler.c			\
		$(SRC_PATH)/set_player.c		\
		$(SRC_PATH)/set_map.c			\
		$(SRC_PATH)/set_piece.c			\
		$(SRC_PATH)/get_number.c		\
		$(SRC_PATH)/coords.c			\
		$(SRC_PATH)/place_piece.c


OSRC = $(SRC:.c=.o)

LIBPRINT_PATH = libftprintf
LIB = $(LIBPRINT_PATH)/libftprintf.a
LIBFT_PATH = $(LIBPRINT_PATH)/libft

NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m

all: $(NAME)

$(NAME): $(LIB) $(OSRC) $(INC) Makefile
	@$(CC) $(CFLAGS) $(OSRC) -o $@ -L $(LIBPRINT_PATH) -lftprintf #-fsanitize=address
	@echo "$(OK_COLOR)$@ compiled.$(NO_COLOR)"

$(LIB):
	@echo "Compiling libftprintf..."
	@make -C $(LIBPRINT_PATH)
	@echo "Librairy compiled."

%.o: %.c
	@$(CC) $(CFLAGS) -I $(LIBPRINT_PATH)/$(INC_PATH) -I $(LIBFT_PATH)/$(INC_PATH) -I $(INC_PATH) -I ../../includes -c -o $@ $?
	@echo "Linking file $@"

clean:
	@make -C libftprintf clean
	@/bin/rm -f $(OSRC)

fclean: clean
	@make -C libftprintf fclean
	@if [ -e $(NAME) ]; \
	then echo "Delete $(NAME)"; \
	fi;
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
