# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daelee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 17:46:51 by daelee            #+#    #+#              #
#    Updated: 2020/02/13 18:01:06 by daelee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ./srcs/
HEADER = ./includes/
FLAG = -Wall -Wextra -Werror
OUTPUT = $(SRC)ft_putchar.o $(SRC)ft_swap.o $(SRC)ft_putstr.o $(SRC)ft_strlen.o $(SRC)ft_strcmp.o

all : $(NAME)

$(NAME) :
	gcc $(FLAG) -o $(SRC)ft_putchar.o -c $(SRC)ft_putchar.c -I $(HEADER)
	gcc $(FLAG) -o $(SRC)ft_swap.o -c $(SRC)ft_swap.c -I $(HEADER)
	gcc $(FLAG) -o $(SRC)ft_putstr.o -c $(SRC)ft_putstr.c -I $(HEADER)
	gcc $(FLAG) -o $(SRC)ft_strlen.o -c $(SRC)ft_strlen.c -I $(HEADER)
	gcc $(FLAG) -o $(SRC)ft_strcmp.o -c $(SRC)ft_strcmp.c -I $(HEADER)
	ar rc $(NAME) $(OUTPUT)

clean:
	/bin/rm -f $(OUTPUT)
fclean: clean
	/bin/rm -f $(NAME)

re : fclean all
