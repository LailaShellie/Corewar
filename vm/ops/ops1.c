/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:49:01 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/24 12:49:02 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../corewar.h"

static int	check_ld(t_o *o)
{
	if (o->t[0] != DIR && o->t[0] != IND)
		return (0);
	if (o->t[1] != REG)
		return (0);
	return (1);
}

void		do_aff(t_main *m, t_cursor *c, t_o *o)
{
	if (o->t[0] == REG)
	{
		get_reg(c, o);
		if (AFF_OP)
			ft_putchar((char)o->x[0]);
	}
	c->op = 0;
	c->pos = c_p(c->pos + o->step);
}

void		do_ld(t_main *m, t_cursor *c, t_o *o)
{
	if (check_ld(o))
	{
		c->reg[o->x[1]] = o->x[0];
		modify_carry(c, c->reg[o->x[1]]);
	}
	c->op = 0;
	c->pos = c_p(c->pos + o->step);
}

void		do_add_sub(t_main *m, t_cursor *c, t_o *o)
{
	if (o->t[0] == REG
	&& o->t[1] == REG && o->t[2] == REG)
	{
		if (c->op == ADD)
			c->reg[o->x[2]] = c->reg[o->x[1]] + c->reg[o->x[0]];
		else if (c->op == SUB)
			c->reg[o->x[2]] = c->reg[o->x[0]] - c->reg[o->x[1]];
		modify_carry(c, c->reg[o->x[2]]);
	}
	c->op = 0;
	c->pos = c_p(c->pos + o->step);
}

void		do_and_or_xor(t_main *m, t_cursor *c, t_o *o)
{
	int		store;

	store = o->x[2];
	get_reg(c, o);
	if (o->t[2] == REG)
	{
		if (c->op == AND)
			c->reg[store] = o->x[0] & o->x[1];
		else if (c->op == OR)
			c->reg[store] = o->x[0] | o->x[1];
		else if (c->op == XOR)
			c->reg[store] = o->x[0] ^ o->x[1];
		modify_carry(c, c->reg[store]);
	}
	c->op = 0;
	c->pos = c_p(c->pos + o->step);
}
