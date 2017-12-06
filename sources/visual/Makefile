# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 17:53:51 by mo0ky             #+#    #+#              #
#    Updated: 2017/12/06 15:45:27 by jmoucade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../../visual

CC = clang

CFLAGS = -Wall -Wextra -Werror

INC_PATH = .

INC =	$(INC_PATH)/win.h

SRC_PATH = .

SRC =	$(SRC_PATH)/visual.c			\
		$(SRC_PATH)/update_screen.c		\
		$(SRC_PATH)/win.c

OSRC = $(SRC:.c=.o)

LIBPRINT_PATH = ../../libftprintf
LIB = $(LIBPRINT_PATH)/libftprintf.a
LIBFT_PATH = $(LIBPRINT_PATH)/libft

NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m

all: $(NAME)

$(NAME): $(LIB) $(OSRC) $(INC) Makefile
	@$(CC) $(CFLAGS) $(OSRC) -o $@ -L $(LIBPRINT_PATH) -lftprintf -lncurses
	@echo "$(OK_COLOR)$@ compiled.$(NO_COLOR)"

%.o: %.c
	@$(CC) $(CFLAGS) -I $(LIBPRINT_PATH)/includes -I $(LIBFT_PATH)/includes -I $(INC_PATH) -c -o $@ $?
	@echo "Linking file $@"

$(LIB):
	@echo "Compiling libftprintf..."
	@make -C $(LIBPRINT_PATH)
	@echo "Librairy compiled."

clean:
	@/bin/rm -f $(OSRC)

fclean: clean
	@if [ -e $(NAME) ]; \
	then echo "Delete $(NAME)"; \
	fi;
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
