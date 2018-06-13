#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvinogra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/17 14:48:56 by vvinogra          #+#    #+#              #
#    Updated: 2017/11/17 14:48:56 by vvinogra         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC = checkmap.c fillit.c ft_arrdel.c ft_lstdel.c ft_lstlen.c \
	ft_lstnew.c ft_putstr.c ft_strdup.c ft_strlen.c \
	main.c squere.c startchecks.c binary.c ft_strcpy.c ft_strdel.c

OBJ = $(SRC:.c=.o)

HEADER = fillit.h

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -o $@ $<

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
