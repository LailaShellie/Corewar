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

SRC_COR = error.c parse.c read_files.c vm_main.c start_game.c cursor.c print_dump.c check_cursors.c fight.c do_op.c live_forks_zjmp.c \
		players.c type_byte.c get_args.c manage_type.c ops1.c ops2.c

OBJ_COR = $(SRC_COR:.c=.o)

SRC_ASM = asm.c into_bytecode.c create_file.c free.c init_data.c lexical_check.c champ_data.c process.c syntax_check.c support.c

OBJ_ASM = $(SRC_ASM:.c=.o)

COR = corewar

ASM = asm

LIB_C = libft_cor/libft.a
LIB_A = libft_asm/libft.a

all: $(COR) $(ASM)

$(COR): $(LIB_C) $(OBJ_COR)
	gcc -Wall -Wextra -Werror -o $(COR) $(LIB_C) $(OBJ_COR)
$(ASM): $(LIB_A) $(OBJ_ASM)
	@gcc -Wall -Wextra -Werror -o $(ASM) $(LIB_A) $(OBJ_ASM)
$(LIB_C):
	make -C ./libft_cor
$(LIB_A):
	@make -C ./libft_asm
$(OBJ_COR) :%.o: vm/%.c corewar.h
	gcc -c -I corewar.h $<
$(OBJ_ASM) :%.o: assembler/srcs/%.c assembler/srcs/asm.h assembler/srcs/asm_ops.h assembler/srcs/op.h
	@gcc -c -I assembler/srcs/asm.h $<
clean:
	@make clean -C ./libft_asm
	@make clean -C ./libft_cor
	@rm -rf $(OBJ_COR)
	@rm -rf $(OBJ_ASM)
fclean: clean
	@make fclean -C ./libft_asm
	@make fclean -C ./libft_cor
	@rm -rf $(COR)
	@rm -rf $(ASM)
re: fclean all