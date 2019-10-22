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
	if (c->op == 1)
		do_live(m, c);
	else if (c->op == 9)
		do_zjmp(m, c);
	else if (c->op == 12 || c->op == 15)
		do_fork(m, c);
//	else
//	{
//		o = init_o(m, c);
//		if (c->op == 2)
//			do_ld(m, c, o);
//	}
//	free_o(o);
}