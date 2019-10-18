/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:53:05 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/15 17:53:06 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

//int		g_ops[17][7] =
//		{
//				{NUM_ARG, TYPE_BYTE, ARG1, ARG2, ARG3, T_DIR_SIZE, PRICE},
//				{1, 0, T_DIR, 0, 0, 4, 10}, ////live
//				{2, 1, T_DIR | T_IND, T_DIR, 0, 4, 5}, ////ld
//				{2, 1, T_REG, T_REG | T_DIR, 0, 4, 5}, ////st
//				{3, 1, T_REG, T_REG, T_REG, 4, 10}, ////add
//				{3, 1, T_REG, T_REG, T_REG, 4, 10}, ////sub
//				{3, 1, T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG, 4, 6}, ////and
//				{3, 1, T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG, 4, 6}, ////or
//				{3, 1, T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG, 4, 6}, ////xor
//				{1, 0, T_DIR, 0, 0, 2, 20}, ////zjmp
//				{2, 1, T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG, 2, 25}, ////ldi
//				{3, 1, T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR, 2, 25}, ////sti
//				{1, 0, T_DIR, 0, 0, 2, 800}, ////fork
//				{2, 1, T_DIR | T_IND, T_REG, 0, 4, 10}, ////lld
//				{3, 1, T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG, 2, 50}, ////lldi
//				{1, 0, T_REG, 0, 0, 2, 1000}, ////lfork
//				{1, 0, T_REG, 0 , 0, 4, 2}, ////aff
//		};

int 	g_len[17] = {PRICE, 10, 5, 5, 10, 10 , 6, 6, 6, 25, 25, 800, 10, 50, 1000, 2};


void		do_op_or_wait(t_main *main, t_cursor *c)
{
	if (c->action == -1)
	{
		c->pos = (c->pos + 1) % MEM_SIZE;
		c->action = 0;
		c->op = 0;
	}
	else
	{
		--c->action;
		if (c->action == 0)
			do_op(main, c);
	}
}

void		read_byte(t_main *main, t_cursor *c)
{
	c->op = main->field[c->pos];
	if (c->op > 0 && c->op <= MAX_OPS)
		c->action = g_len[c->op];
	else
		c->action = -1;
}

void		do_cursor(t_main *main, t_cursor *c)
{
	if (c->action == 0)
		read_byte(main, c);
	do_op_or_wait(main, c);
}

void		do_cycle(t_main *main)
{
	t_cursor	*cur;

	cur = main->cursor;
	while (cur)
	{
		do_cursor(main, cur);
		cur = cur->next;
	}
}

void		start_fight(t_main *main)
{
	while (main->cursor)
	{
		++main->cycle;
		++main->total_cycle;
		do_cycle(main);
		if (main->cycle >= main->cycles_to_die || main->cycles_to_die <= 0)
			check(main);
	}
}
