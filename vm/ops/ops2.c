/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:34:38 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/24 13:34:39 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

static int	check_sti(t_o *o)
{
	if ((o->t[2] == REG || o->t[2] == DIR) && o->t[0] == REG)
		return (1);
	return (0);
}

static int	check_ldi(t_o *o)
{
	if ((o->t[1] == REG || o->t[1] == DIR) && o->t[2] == REG)
		return (1);
	return (0);
}

void		set_mem(char *f, int reg, int pos)
{
	int 	i;
	char 	*store;

	store = (char *)(&reg);
	i = -1;
	while (++i < 4)
	{
		f[c_p(pos + i)] = store[3 - i];
	}
}

void		do_ldi(t_main *m, t_cursor *c, t_o *o)
{
	int 	store;
	int 	a;

	store = o->x[2];
	get_reg(c, o);
	if (check_ldi(o))
	{
		if (c->op == 10)
			a = c->pos + (o->x[0] + o->x[1]) % IDX_MOD;
		else if (c->op == 14)
			a = c->pos + o->x[0] + o->x[1];
		c->reg[store] = read_mem(m->field, a, 4);
		modify_carry(c, c->reg[store]);
	}
	c->pos = c_p(c->pos + o->step);
}

void		do_st(t_main *m, t_cursor *c, t_o *o)
{
	int 	a;

	if (o->t[0] == REG && o->t[1] == REG)
		c->reg[o->x[1]] = c->reg[o->x[0]];
	else if (o->t[0] == REG && o->t[1] == IND)
	{
		a = c->pos + o->x[1] % IDX_MOD;
		set_mem(m->field, c->reg[o->x[0]], a);
	}
	c->pos = c_p(c->pos + o->step);
}

void		do_sti(t_main *m, t_cursor *c, t_o *o)
{
	int 	store;
	int 	a;

	store = o->x[0];
	get_reg(c, o);
	if (check_sti(o))
	{
		a = c->pos + (o->x[1] + o->x[2]) % IDX_MOD;
		set_mem(m->field, c->reg[store], a);
	}
	c->pos = c_p(c->pos + o->step);
}