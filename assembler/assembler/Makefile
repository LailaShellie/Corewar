# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blanna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/30 13:46:41 by blanna            #+#    #+#              #
#    Updated: 2019/09/30 13:46:43 by blanna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRC = asm.c \
into_bytecode.c \
create_file.c \
free.c \
init_data.c \
lexical_check.c \
champ_data.c \
process.c \
syntax_check.c \
support.c

OBJ = asm.o \
into_bytecode.o \
create_file.o \
free.o \
init_data.o \
lexical_check.o \
champ_data.o \
process.o \
syntax_check.o \
support.o

FLAGS = -Wall -Wextra -Werror
LIBRF = ../libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
		@make re -C ../libft/
		@gcc $(LIBRF) $(FLAGS) $(OBJ) -o $(NAME)
%.o: srcs/%.c
	gcc -c $<

clean:
		@make clean -C ../libft/
		@rm -f $(OBJ)

fclean: clean
		@make fclean -C ../libft/
		@rm -f $(NAME)

re: fclean all
