/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   into_bytecode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:16:50 by blanna            #+#    #+#             */
/*   Updated: 2019/10/28 12:16:52 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			c_h(t_ass *d_asm, int32_t dec, int d_sz, uint32_t *beg)
{
	int			move;
	int			buf;

	buf = d_sz;
	move = 0;
	while (d_sz)
	{
		d_asm->bytecod[*beg + d_sz - 1] = (uint8_t)((dec >> move) & 0xFF);
		move += 8;
		d_sz--;
	}
	*beg += buf;
}

void			types_arg_record(t_ass *d_asm, t_tkn *op,
		uint32_t *ptr, uint8_t n_arg)
{
	int8_t		bin;
	int			arg;

	bin = 0;
	arg = 0;
	while (arg < n_arg)
	{
		if (op->type == REGISTER)
			bin |= REG_CODE << 2 * (3 - arg++);
		else if (op->type == DIRECT\
				|| op->type == DIRECT_LABEL)
			bin |= DIR_CODE << 2 * (3 - arg++);
		else if (op->type == INDIRECT\
				|| op->type == INDIRECT_LABEL)
			bin |= IND_CODE << 2 * (3 - arg++);
		op = op->prev;
	}
	c_h(d_asm, bin, 1, ptr);
}

int32_t			c(t_ass *d_asm, uint32_t bytes, t_tkn *lbl)
{
	int32_t		move;
	t_lbl		*temp;

	temp = d_asm->lbl;
	while (temp)
	{
		if (ft_strequ(lbl->cont, temp->locat->cont))
			break ;
		temp = temp->next;
	}
	(!temp) ? error(d_asm, NO_LBL, lbl, 2) : 0;
	move = temp->locat->bytes - bytes;
	return (move);
}

void			oper_record(t_ass *d_asm, t_tkn **op,
		uint32_t *ptr, uint8_t type)
{
	uint8_t		n_arg;
	uint8_t		d_s;

	c_h(d_asm, g_op_tab[type].numb, 1, ptr);
	n_arg = g_op_tab[type].args_n;
	if (g_op_tab[type].typ_cod)
		types_arg_record(d_asm, *op, ptr, n_arg);
	*op = (*op)->prev;
	while (n_arg--)
	{
		while ((*op)->type == SEPARATOR)
			*op = (*op)->prev;
		d_s = g_op_tab[type].dir_sz;
		if ((*op)->type == REGISTER)
			c_h(d_asm, ft_atoi_size((*op)->cont + 1, 1), 1, ptr);
		else if ((*op)->type == DIRECT)
			c_h(d_asm, ft_atoi_size((*op)->cont, d_s), d_s, ptr);
		else if ((*op)->type == INDIRECT)
			c_h(d_asm, ft_atoi_size((*op)->cont, IND_SIZE), IND_SIZE, ptr);
		else if ((*op)->type == DIRECT_LABEL)
			c_h(d_asm, c(d_asm, (*op)->bytes, *op), d_s, ptr);
		else if ((*op)->type == INDIRECT_LABEL)
			c_h(d_asm, c(d_asm, (*op)->bytes, *op), IND_SIZE, ptr);
		*op = (*op)->prev;
	}
}

void			into_bytecode(t_ass *d_asm)
{
	t_tkn		*temp;
	uint32_t	ptr;

	ptr = 0;
	c_h(d_asm, d_asm->magic, 4, &ptr);
	temp = champ_data_record(d_asm, d_asm->tkn);
	ptr = BEGIN_EXEC_SIZE;
	c_h(d_asm, d_asm->code_bytes, 4, &ptr);
	ptr = BEGIN_EXEC;
	while (temp)
	{
		if (temp->type == INSTRUCTION)
			oper_record(d_asm, &temp, &ptr, temp->bytes);
		temp = temp->prev;
	}
}
