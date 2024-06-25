# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 13:12:26 by nirirako@         #+#    #+#              #
#    Updated: 2024/05/01 07:54:40 by nirirako@        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fanorona

SRC = ./src/map.c ./src/structure.c ./src/structure1.c ./src/main.c \
		./src/fillwindow.c ./src/mouse.c ./src/check.c ./src/verif_win.c \
		./src/fill_last_window.c ./src/put_path.c ./src/first_window.c \
		./src/ia.c ./src/handle_mouse_computer.c 
OBJ = $(SRC:.c=.o)

RM = rm -f

CC = gcc

SRC1 = ./lib/ft_printf/

SRC2 = ./lib/gnl/

SRC3 = ./lib/libft/

SRC4 = ./lib/minilibx-linux/

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -I $(SRC1) -I $(SRC2) -I $(SRC3) -I $(SRC4) \
	-c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	make -C $(SRC1)
	make -C $(SRC2)
	make -C $(SRC3)
	make -C $(SRC4)
	$(CC) -g -o $(NAME) $(OBJ) -L $(SRC1) -L $(SRC2) -L $(SRC3) \
	-L $(SRC4) -lftprintf -lgnl -lft -lmlx -lXext -lX11 -lm

all: $(NAME)

clean:
	make -C $(SRC1) clean
	make -C $(SRC2) clean
	make -C $(SRC3) clean
	make -C $(SRC4) clean
	$(RM) $(OBJ)
	$(RM) $(BOBJ)

fclean: clean
	make -C $(SRC1) fclean
	make -C $(SRC2) fclean
	make -C $(SRC3) fclean
	$(RM) $(NAME)

re: fclean clean $(NAME)

.PHONY: all
