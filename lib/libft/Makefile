# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nirirako@42antananarivo.mg <nirirako@      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 10:20:40 by nirirako@         #+#    #+#              #
#    Updated: 2024/02/21 10:20:43 by nirirako@        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c\
	 ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
	 ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c\
	 ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c\
	 ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c\
	 ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c\
	 ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
	 ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
	 ft_putendl_fd.c ft_putnbr_fd.c
	 
B_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c ft_lstiter_bonus.c

OBJS = $(SRC:.c=.o)
B_OBJS = $(B_SRC:.c=.o)

CC = gcc

RM = rm -f

AR = ar -rc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean clean $(NAME)

bonus: $(B_OBJS)
	$(AR) $(NAME) $(B_OBJS)
