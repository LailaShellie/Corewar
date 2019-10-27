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

void		set_mem(char *f, int reg, int pos)
{
	int		i;
	char	*store;

	store = (char *)(&reg);
	i = -1;
	while (++i < 4)
		f[c_p(pos + i)] = store[3 - i];
}

int			c_p(int pos)
{
	pos %= MEM_SIZE;
	if (pos >= MEM_SIZE)
		return (pos);
	else if (pos < 0)
		return (MEM_SIZE - ft_abs(pos));
	else
		return (pos);
}

void		do_op1(t_main *m, t_cursor *c, t_o *o)
{
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
		do_op1(m, c, o);
		free_o(o);
	}
}
