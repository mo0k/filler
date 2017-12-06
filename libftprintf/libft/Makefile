# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2016/08/14 13:07:25 by jmoucade          #+#    #+#             #
#    Updated: 2017/10/01 22:07:34 by jmoucade         ###   ########.fr        #
#                                                                            #
# ************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra
CC = gcc $(CFLAGS)

INC_PATH = includes

INCS = $(INC_PATH)/libft.h				\
		$(INC_PATH)/types.h				\
		$(INC_PATH)/array.h				\
		$(INC_PATH)/charac.h			\
		$(INC_PATH)/convert.h			\
		$(INC_PATH)/integer.h			\
		$(INC_PATH)/list.h				\
		$(INC_PATH)/memory.h			\
		$(INC_PATH)/puts.h				\
		$(INC_PATH)/string.h			\
		$(INC_PATH)/wchars.h			\
		$(INC_PATH)/colors.h			\
		$(INC_PATH)/get_next_line.h		\
		$(INC_PATH)/buffer_controler.h	\

SRCS_PATH = sources

CHARAC_PATH = $(SRCS_PATH)/charac
CHARAC =		$(CHARAC_PATH)/ft_isalnum.c		\
				$(CHARAC_PATH)/ft_isalpha.c		\
				$(CHARAC_PATH)/ft_isascii.c		\
				$(CHARAC_PATH)/ft_isdigit.c		\
				$(CHARAC_PATH)/ft_isprint.c		\
				$(CHARAC_PATH)/ft_isspace.c		\
				$(CHARAC_PATH)/ft_tolower.c		\
				$(CHARAC_PATH)/ft_toupper.c

INTEGER_PATH = $(SRCS_PATH)/integer
INTEGER =		$(INTEGER_PATH)/ft_nbrlen.c		\
				$(INTEGER_PATH)/ft_swap.c

STRING_PATH = $(SRCS_PATH)/string
STRING =		$(STRING_PATH)/ft_strlen.c				\
				$(STRING_PATH)/ft_strdup.c				\
				$(STRING_PATH)/ft_strcpy.c				\
				$(STRING_PATH)/ft_strncpy.c				\
				$(STRING_PATH)/ft_strcat.c				\
				$(STRING_PATH)/ft_strncat.c				\
				$(STRING_PATH)/ft_strlcat.c				\
				$(STRING_PATH)/ft_strchr.c				\
				$(STRING_PATH)/ft_strrchr.c				\
				$(STRING_PATH)/ft_strstr.c				\
				$(STRING_PATH)/ft_strnstr.c				\
				$(STRING_PATH)/ft_strcmp.c				\
				$(STRING_PATH)/ft_strncmp.c				\
				$(STRING_PATH)/ft_strnew.c				\
				$(STRING_PATH)/ft_strdelnew.c			\
				$(STRING_PATH)/ft_strdel.c				\
				$(STRING_PATH)/ft_strclr.c				\
				$(STRING_PATH)/ft_striter.c				\
				$(STRING_PATH)/ft_striteri.c			\
				$(STRING_PATH)/ft_strmap.c				\
				$(STRING_PATH)/ft_strmapi.c				\
				$(STRING_PATH)/ft_strequ.c				\
				$(STRING_PATH)/ft_strnequ.c				\
				$(STRING_PATH)/ft_strsub.c				\
				$(STRING_PATH)/ft_strjoin.c				\
				$(STRING_PATH)/ft_strtrim.c				\
				$(STRING_PATH)/ft_strsplit.c			\
				$(STRING_PATH)/ft_stracat.c 			\
				$(STRING_PATH)/ft_strpadding_right.c 	\
				$(STRING_PATH)/ft_strpadding_left.c 	\
				$(STRING_PATH)/ft_str3join.c			\
				$(STRING_PATH)/ft_strtoupper.c			\
				$(STRING_PATH)/ft_straddc.c

ARRAY_PATH = $(SRCS_PATH)/array
ARRAY =		$(ARRAY_PATH)/ft_count_if.c				\
				$(ARRAY_PATH)/ft_foreach.c			\
				$(ARRAY_PATH)/ft_range.c			\
				$(ARRAY_PATH)/ft_double_tab.c		\
				$(ARRAY_PATH)/ft_triple_tab.c

MEMORY_PATH = $(SRCS_PATH)/memory
MEMORY =		$(MEMORY_PATH)/ft_memset.c			\
				$(MEMORY_PATH)/ft_bzero.c			\
				$(MEMORY_PATH)/ft_memcpy.c			\
				$(MEMORY_PATH)/ft_memccpy.c			\
				$(MEMORY_PATH)/ft_memmove.c			\
				$(MEMORY_PATH)/ft_memchr.c			\
				$(MEMORY_PATH)/ft_memcmp.c			\
				$(MEMORY_PATH)/ft_memalloc.c		\
				$(MEMORY_PATH)/ft_memdel.c			\
				$(MEMORY_PATH)/ft_memrcpy.c

LIST_PATH = $(SRCS_PATH)/list
LIST =			$(LIST_PATH)/ft_lstnew.c			\
				$(LIST_PATH)/ft_lstdelone.c			\
				$(LIST_PATH)/ft_lstdel.c			\
				$(LIST_PATH)/ft_lstdelfirst.c		\
				$(LIST_PATH)/ft_lstdelnext.c		\
				$(LIST_PATH)/ft_lstadd_start.c		\
				$(LIST_PATH)/ft_lstadd_end.c		\
				$(LIST_PATH)/ft_lstrev.c			\
				$(LIST_PATH)/ft_lstiter.c			\
				$(LIST_PATH)/ft_lstselect.c			\
				$(LIST_PATH)/ft_lstlen.c			\
				$(LIST_PATH)/ft_lstmap.c

PUTS_PATH = $(SRCS_PATH)/puts
PUTSCOLOR_PATH =  $(PUTS_PATH)/color
PUTS =			$(PUTS_PATH)/ft_putchar.c				\
				$(PUTS_PATH)/ft_putchar_fd.c			\
				$(PUTS_PATH)/ft_putstr.c				\
				$(PUTS_PATH)/ft_putstr_fd.c				\
				$(PUTS_PATH)/ft_putendl.c				\
				$(PUTS_PATH)/ft_putendl_fd.c			\
				$(PUTS_PATH)/ft_putnbr.c				\
				$(PUTS_PATH)/ft_putnbr_fd.c				\
				$(PUTS_PATH)/ft_putnbr_base.c			\
				$(PUTS_PATH)/ft_putstrtab.c				\
				$(PUTSCOLOR_PATH)/ft_putcharcolor.c		\
				$(PUTSCOLOR_PATH)/ft_putcharcolor_fd.c	\
				$(PUTSCOLOR_PATH)/ft_putstrcolor.c		\
				$(PUTSCOLOR_PATH)/ft_putstrcolor_fd.c	\
				$(PUTSCOLOR_PATH)/ft_putendlcolor.c		\
				$(PUTSCOLOR_PATH)/ft_putendlcolor_fd.c	\
				$(PUTSCOLOR_PATH)/ft_putnbrcolor.c		\
				$(PUTSCOLOR_PATH)/ft_putnbrcolor_fd.c

READLINE_PATH = $(SRCS_PATH)/readline
READLINE =			$(READLINE_PATH)/get_next_line.c		\
					$(READLINE_PATH)/gnl.c

CONTROLER_PATH = $(SRCS_PATH)/controler
CONTROLER=			$(CONTROLER_PATH)/buffer_malloc.c		\
					$(CONTROLER_PATH)/static/init.c			\
					$(CONTROLER_PATH)/static/fill_buffer.c	\
					$(CONTROLER_PATH)/static/filln_buffer.c	\
					$(CONTROLER_PATH)/static/print_buffer.c	\
					$(CONTROLER_PATH)/available_space.c		\

CONVERT_PATH = $(SRCS_PATH)/convert
CONVERT =		$(CONVERT_PATH)/ft_atoi.c					\
				$(CONVERT_PATH)/ft_itoa.c					\
				$(CONVERT_PATH)/ft_itoa_base.c

WCHAR_PATH = $(SRCS_PATH)/wchar
WCHAR =			$(WCHAR_PATH)/ft_wcharlen.c				\
				$(WCHAR_PATH)/ft_wstrlen.c				\
				$(WCHAR_PATH)/ft_wstrnlen.c

SRCS = 	$(CHARAC) $(INTEGER) $(STRING) $(ARRAY) $(MEMORY) $(LIST) $(PUTS) \
		$(READLINE) $(CONTROLER) $(CONVERT) $(WCHAR)

OBJS	= $(SRCS:%.c=%.o)
C_LGREEN = "\033[92m"
C_LRED = "\033[91m"
C_RED = "\033[31m"
C_DFL	="\033[0m"

ECHO = echo -n

all: $(NAME)

$(NAME): $(INCS) $(OBJS_PATH) $(OBJS) Makefile
	@ar rcs $(NAME) $(OBJS)
	@echo $(C_LGREEN)"$(NAME) compiled"$(C_DFL)

%.o: %.c
	@$(CC) -I $(INC_PATH) -c -o $@ $<
	@echo "Linking file" $@

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@if [ -e $(NAME) ]; \
	then echo $(C_RED)"Delete $(NAME)."$(C_DFL); \
	fi;
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: objects OBJS clean fclean