 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: y0ja <y0ja@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/05 03:36:55 by y0ja              #+#    #+#              #
#    Updated: 2014/12/15 06:12:13 by y0ja             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEBUG	= no
ifeq ($(DEBUG),no)
	CFLAGS=-Wall -Wextra -Werror
else
	CFLAGS= -g
endif
NAME	= FdF
LDFLAGS = -L/usr/X11/lib -lmlx -lXext -lX11 -I./includes/ -L./libft/ -lft
SRC 	= main.c draw_lign.c file2map.c \
			get_isomap.c misc.c colors.c iso_rot.c \
			display_and_keyhook.c moves.c get_all_files.c \
			stock_img.c 
OBJ		= $(SRC:.c=.o)
INC		= fdf.h img_n_colors.h keys_n_error.h
SRCDIR	= ./srcs/
OBJDIR	= ./objs/
INCDIR	= ./includes/
SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(OBJ))
INCS	= $(addprefix $(INCDIR), $(INC))

all: $(NAME)

$(NAME): $(OBJS) $(INCS)
	make -C libft/
	@gcc $(FLAGS) -o $@ $^ $(LDFLAGS)
	@echo "\\033[1;32mSuccess.\\033[0;39m"

$(OBJS): $(SRCS)
ifeq ($(DEBUG),yes)
		@echo "\\033[1;31mDEBUG COMPILATION.. (no flags except -g)\\033[0;39m"
else
		@echo "\\033[1;31mCompilation with -Wall -Wextra -Werror...\\033[0;39m"
endif
	@echo "\\033[1;34mGenerating objects... Please wait.\\033[0;39m"
	@gcc $(FLAGS) -c $(SRCS) $(LDFLAGS)
	@mv $(OBJ) $(OBJDIR)

.PHONY: clean fclean re

clean:
	@echo "\\033[1;34mDeleting objects...\\033[0;39m"
	@rm -f $(OBJS)

fclean: clean
	@echo "\\033[1;34mDeleting binary...\\033[0;39m"
	@rm -f $(NAME)

re: fclean all