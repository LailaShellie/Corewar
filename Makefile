# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lshellie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 17:06:50 by lshellie          #+#    #+#              #
#    Updated: 2019/10/13 17:06:51 by lshellie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC1 = error.c parse.c read_files.c vm_main.c start_game.c cursor.c print_dump.c check_cursors.c fight.c do_op.c live_forks_zjmp.c \
		players.c type_byte.c get_args.c manage_type.c

SRC2 = ops1.c ops2.c

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)

NAME = corewar

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ1) $(OBJ2)
	@gcc -Wall -Wextra -Werror -o $(NAME) $(LIB) $(OBJ1) $(OBJ2)
$(LIB):
	@make -C ./libft
%.o: vm/%.c corewar.h
	@gcc -c -I corewar.h $<
%.o: vm/ops/%.c corewar.h
	@gcc -c -I corewar.h $<
clean:
	@make clean -C ./libft
	@rm -rf $(OBJ1) $(OBJ2)
fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME)
re: fclean all