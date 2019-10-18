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

int 		choose_pos(int tmp, int dir_size)
{
	if (tmp == M_REG)
		return (1);
	else if (tmp == M_DIR)
		return (dir_size);
	else if (tmp == M_IND)
		return (2);
	return (0);
}

void		move_next(t_cursor *c, unsigned char type, int *global)
{
	int 	pos;
	int 	i;
	int 	k;
	char	tmp;

	k = 0;
	i = 7;
	pos = 2;
	tmp = 0;
	while (i >=  8 - 2 * global[NUM_ARG])
	{
		if (type & (1 << i))
			tmp |= 1 << k;
		++k;
		if (k == 2)
		{
			pos += choose_pos(tmp, global[T_DIR_SIZE]);
			tmp = 0;
			k = 0;
		}
		--i;
	}
	c->pos = c_p(c->pos + pos);
}

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
	else if (c->op == 2)
		do_ld(m, c);
	else if (c->op == 3)
		do_st(m, c);
	else if (c->op == 4)
		do_add(m, c);
	else if (c->op == 5)
		do_sub(m, c);
	else if (c->op == 9)
		do_zjmp(m, c);
	else if (c->op == 12)
		do_fork(m, c);
	else if (c->op == 15)
		do_lfork(m, c);

}