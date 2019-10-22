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

SRC = error.c parse.c read_files.c vm_main.c start_game.c cursor.c print_dump.c check_cursors.c fight.c do_op.c live_forks_zjmp.c check_args.c \
		players.c

OBJ = $(SRC:.c=.o)

NAME = corewar

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	@gcc -Wall -Wextra -Werror -o $(NAME) $(LIB) $(OBJ)
$(LIB):
	@make -C ./libft
%.o: vm/%.c corewar.h
	@gcc -c -I corewar.h $<
clean:
	@make clean -C ./libft
	@rm -rf $(OBJ)
fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME)
re: fclean all