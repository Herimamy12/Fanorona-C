# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 13:12:26 by nirirako@         #+#    #+#              #
#    Updated: 2024/03/08 13:12:45 by nirirako@        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

SRC = get_next_line.c get_next_line_utils.c


OBJ = $(SRC:.c=.o)

RM = rm -f

CC = gcc

AR = ar -rc


CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ) 

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean clean $(NAME)

