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

int 	g_price[17] = {PRICE, 10, 5, 5, 10, 10 , 6, 6, 6, 20, 25, 25, 800, 10, 50, 1000, 2};


void		do_or_wait(t_main *main, t_cursor *c)
{
	if (c->action == -1)
	{
		c->pos = c_p(c->pos + 1);
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
		c->action = g_price[c->op];
	else
		c->action = -1;
}

void		do_cursor(t_main *main, t_cursor *c)
{
	if (c->action == 0)
		read_byte(main, c);
	do_or_wait(main, c);
}

int 		cursor_num(t_cursor *c)
{
	int 	num;
	int 	i;

	num = 0;
	while (c)
	{
		i = -1;
		++num;
		if (c->action == 1)
		{
			printf("%d  %d    %d - op   %d -action ", c->id, c->pos, c->op, c->action);
			while (++i < 16)
				printf("r%d = %u ", i + 1, c->reg[i]);
			printf("\n");
		}
		c = c->next;
	}
	return (num);
}

void		do_cycle(t_main *main)
{
	t_cursor	*cur;

	cur = main->cursor;
	while (cur)
	{
		do_cursor(main, cur);
		if (main->total_cycle == 10114)
		{
			cursor_num(main->cursor);
			dump_memory_64(main->field, main->cursor);
		}
		cur = cur->next;
	}
}



int			start_fight(t_main *m)
{
	while (m->cursor)
	{
		++m->cycle;
		++m->total_cycle;
		if (m->v_flag)
			printf("It is now cycle %d\n", m->total_cycle);
		do_cycle(m);
		if (m->cycle == m->cycles_to_die || m->cycles_to_die <= 0)
			check(m);
		if (m->dump == m->total_cycle)
		{
//			printf("%d - cycle\n", m->total_cycle);
			dump_memory(m->field);
			return (0);
		}
//		if (!m->v_flag)
//		{
////			printf("%d - cycle %d\n", m->total_cycle, cursor_num(m->cursor));
//			dump_memory_64(m->field, m->cursor);
////			dump_memory(m->field);
//		}
	//	cursor_num(m->cursor);
		if (m->total_cycle == 10114)
			m->total_cycle = m->total_cycle;
//		sleep(1);
	}
	return (1);
}
