/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_ops.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:16:08 by blanna            #+#    #+#             */
/*   Updated: 2019/10/28 12:16:11 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_OPS_H
# define ASM_OPS_H

# include "op.h"

typedef struct			s_op
{
	char				*name;
	uint32_t			args_n;
	uint32_t			args_typ[3];
	uint32_t			numb;
	uint32_t			cycles;
	unsigned char		description[37];
	uint32_t			typ_cod;
	uint32_t			dir_sz;
}						t_op;

static t_op				g_op_tab[16] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 4},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 4},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 4},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 4},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 4},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 4},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 4},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 4},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 2},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 2},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 2},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 2},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 4},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 2},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 2},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 4}
};

typedef enum			e_type
{
	REGISTER = 1,
	DIRECT,
	DIRECT_LABEL,
	INDIRECT,
	INDIRECT_LABEL,
	INSTRUCTION,
	LABEL,
	STRING,
	COMMAND,
	NEW_LINE,
	SEPARATOR,
	END
}						t_type;

#endif
