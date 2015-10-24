# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 00:27:00 by jripoute          #+#    #+#              #
#    Updated: 2015/01/17 21:52:54 by jripoute         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEBUG=yes
NAME=libft.a
ifeq ($(DEBUG),yes)
	FLAGS=-Wall -Wextra -Werror
else
	FLAGS=
endif
FILES_C=ft_putstr.c  ft_strrev.c  ft_putendl.c  ft_putchar.c  ft_putnbr.c  ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_bzero.c ft_memccpy.c ft_memcpy.c \
ft_memset.c ft_memmove.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_tolower.c ft_toupper.c ft_strlen.c ft_strnstr.c ft_strclen.c \
ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strstr.c \
ft_strchr.c ft_strrchr.c ft_strmap.c ft_strmapi.c ft_strcmp.c ft_strncmp.c \
ft_atoi.c ft_itoa.c ft_memalloc.c ft_memdel.c ft_memchr.c ft_memcmp.c ft_strnew.c \
ft_strdel.c ft_strsplit.c ft_strtrim.c ft_strclr.c ft_striter.c ft_striteri.c ft_strequ.c \
ft_strnequ.c ft_strsub.c ft_strjoin.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
ft_lstadd_end.c ft_lstiter.c ft_lstmap.c ft_printlist.c ft_strlcat.c ft_dlstadd.c \
ft_dlstadd_end.c ft_dlstnew.c ft_dlstdel.c ft_dlstdelone.c ft_printdlist.c ft_strndup.c \
ft_isspace.c ft_lstlen.c ft_dlstlen.c ft_lstati.c ft_lstlast.c ft_lstadd_i.c ft_strchrstr.c \
ft_dlstati.c ft_dlstlast.c ft_dlstadd_i.c ft_rotn.c ft_isupper.c ft_islower.c ft_realloc.c \
ft_strcasecmp.c ft_dlstrev.c ft_swap_contents.c ft_print_n_spaces.c get_next_line.c \
ft_intlen.c ft_dlst_insert.c ft_dlstfirst.c ft_rand_a_b.c
FILES_O=$(FILES_C:.c=.o)

all: $(NAME)

$(NAME): make_obj do_lib
	@echo "\\033[1;32mSuccess.\\033[0;39m"

do_lib: make_obj
	@echo "\\033[1;34mIndexing the lib...\\033[0;39m"
	@ar rc $(NAME) $(FILES_O)
	@ranlib $(NAME)

make_obj:
ifeq ($(DEBUG),yes)
	@echo "\\033[1;31mDebug compilation.. (-Wall -Wextra -Werror)\\033[0;39m"
else
	@echo "\\033[1;31mNo flags.\\033[0;39m"
endif
	@echo "\\033[1;34mGenerating objects... Please wait.\\033[0;39m"
	@gcc $(FLAGS) -c $(FILES_C)

.PHONY: clean fclean re

clean:
	@echo "\\033[1;34mDeleting objects...\\033[0;39m"
	@rm -f $(FILES_O)

fclean: clean
	@echo "\\033[1;34mDeleting libft.a...\\033[0;39m"
	@rm -f $(NAME)

re: fclean all