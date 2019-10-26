/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:54:05 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/17 14:54:06 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int 		c_p(int pos)
{
	pos %= MEM_SIZE;
	if (pos >= MEM_SIZE)
		return (pos);
	else if (pos < 0)
		return (MEM_SIZE - ft_abs(pos));
	else
		return (pos);
}

void		do_op(t_main *m, t_cursor *c)
{
	t_o		*o;

	o = 0;
	if (c->op == LIVE)
		do_live(m, c);
	else if (c->op == ZJMP)
		do_zjmp(m, c);
	else if (c->op == FORK || c->op == LFORK)
		do_fork(m, c);
	else
	{
		if (!(o = manage_type(m, c)))
			return ;
		if (c->op == LD || c->op == LLD)
			do_ld(m, c, o);
		else if (c->op == ADD || c->op == SUB)
			do_add_sub(m, c, o);
		else if (c->op == AND || c->op == OR || c->op == XOR)
			do_and_or_xor(m, c, o);
		else if (c->op == ST)
			do_st(m, c, o);
		else if (c->op == STI)
			do_sti(m, c, o);
		else if (c->op == AFF)
			do_aff(m, c, o);
		else if (c->op == LDI || c->op == LLDI)
			do_ldi(m, c, o);
		free_o(o);
	}
}