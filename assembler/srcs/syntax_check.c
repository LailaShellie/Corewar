/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:17:31 by blanna            #+#    #+#             */
/*   Updated: 2019/10/28 12:17:32 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		op_exist(t_ass *d_asm, t_tkn *operation)
{
	int			i;

	i = 0;
	while (i < 16)
		if (ft_strequ(operation->cont, g_op_tab[i].name))
			break ;
		else
			i++;
	if (i == 16)
		error(d_asm, OPER, operation, 2);
	operation->bytes = i;
	return (i);
}

static int		valid_arg(t_ass *d_asm, t_tkn *arg, int type)
{
	int			arg_type;

	arg_type = arg->type;
	if (arg->type == DIRECT_LABEL)
		arg_type = T_DIR;
	else if (arg->type == INDIRECT_LABEL)
		arg_type = T_IND;
	if (arg_type != (arg_type & type))
		error(d_asm, OPER_TYPEARG, arg, 2);
	return (arg_type);
}

static int		size_arg(int arg_type, t_ass *d_asm, int op_n, \
								t_tkn *arg)
{
	if (arg_type == T_REG)
		d_asm->code_bytes++;
	else if (arg_type == T_IND)
		d_asm->code_bytes += IND_SIZE;
	else if (arg_type == T_DIR)
		d_asm->code_bytes += g_op_tab[op_n].dir_sz;
	return (arg_type);
}

static void		check_operations_args(t_ass *d_asm, t_tkn **op, int i, int op_n)
{
	uint32_t	args;
	uint32_t	*types;
	uint32_t	b_start;
	t_tkn		*temp;
	int			arg_type;

	i = 0;
	temp = (*op);
	op_n = op_exist(d_asm, temp);
	INIT;
	b_start = d_asm->code_bytes;
	d_asm->code_bytes += 1 + (g_op_tab[op_n].typ_cod ? 1 : 0);
	while ((temp = temp->prev) && temp->type < 6 && args--)
	{
		arg_type = valid_arg(d_asm, temp, types[i++]);
		arg_type = size_arg(arg_type, d_asm, op_n, temp);
		(arg_type == T_IND || arg_type == T_DIR) ? temp->bytes = b_start : 0;
		temp = temp->prev;
		if (temp->type != SEPARATOR)
			break ;
	}
	(args != 0) ? error(d_asm, OPER_NUMARG, *op, 2) : 0;
	if (temp && !(temp->type == NEW_LINE || temp->type == END))
		error(d_asm, OPER_NOEND, *op, 2);
	*op = temp;
}

void			syntax_check(t_ass *d_asm, t_tkn *tkn)
{
	int			i;
	int			op_n;

	while (tkn)
	{
		if (tkn->type == INSTRUCTION)
			check_operations_args(d_asm, &tkn, i, op_n);
		else if (tkn->type == LABEL)
			tkn->bytes = d_asm->code_bytes;
		else if (tkn->type == NEW_LINE)
			;
		else if (tkn->type == END)
			break ;
		else
			error(d_asm, WRONG_SYM, tkn, 2);
		tkn = tkn->prev;
	}
}
