#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/01 12:24:35 by oposhiva          #+#    #+#              #
#    Updated: 2017/06/01 12:24:35 by oposhiva         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME_1 = push_swap

NAME_2 = checker

FLAGS = -Wall -Wextra -Werror

LIBFT = printflibft/libftprintf.a

HEADER = push_swap.h printflibft/get_next_line.h printflibft/ft_printf.h

SRC = body.c conjunction.c both.c instructions.c separation.c check_help.c\
top_sort.c push_help.c arguments.c checker_inst.c push_help2.c one_arg.c

OBJ = $(SRC:.c=.o)

all: $(NAME_1) $(NAME_2)

$(NAME_1): push_swap.o $(OBJ) $(LIBFT)
	gcc -o $(NAME_1) $(OBJ) push_swap.o $(LIBFT)

$(NAME_2): checker.o $(OBJ) $(LIBFT)
	gcc -o $(NAME_2) $(OBJ) checker.o $(LIBFT)

push_swap.o: push_swap.c
	gcc -c $(FLAGS) push_swap.c

checker.o: checker.c
	gcc -c $(FLAGS) checker.c

$(OBJ): %.o: %.c
	gcc -c $(FLAGS) $< -o $@

$(LIBFT):
	make -C printflibft/

libft_clean:
	make -C printflibft/ clean

libft_fclean:
	make -C printflibft/ fclean

clean: libft_clean
	rm -f $(OBJ) push_swap.o checker.o *~

fclean: clean
	rm -f $(NAME_1) $(NAME_2)
	rm -f printflibft/libftprintf.a

re: fclean all
