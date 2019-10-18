/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:46:24 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/18 19:46:25 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

#define T_REG_REG_REG 0x54

int 		g_add_sub[6] = {3, 1, T_REG, T_REG, T_REG, 4};

void		do_add(t_main *m, t_cursor *c)
{
	unsigned int	type;
	int 			r[3];

	type = m->field[c_p(c->pos + 1)];
	if (type == T_REG_REG_REG)
	{
		r[0] = m->field[c_p(c->pos + 2)];
		r[1] = m->field[c_p(c->pos + 3)];
		r[2] = m->field[c_p(c->pos + 4)];
		if (r[0] > 0 && r[0] <= 16
		&& r[1] > 0 && r[1] <= 16 && r[2] > 0 && r[2] <= 16)
		{
			c->reg[r[2] - 1] = c->reg[r[0] - 1] + c->reg[r[1] - 1];
			if (c->reg[r[2] - 1] == 0)
				c->carry = 1;
			else
				c->carry = 0;
		}
	}
	move_next(c, type, g_add_sub);
}

void		do_sub(t_main *m, t_cursor *c)
{
	unsigned int	type;
	int 			r[3];

	type = m->field[c_p(c->pos + 1)];
	if (type == T_REG_REG_REG)
	{
		r[0] = m->field[c_p(c->pos + 2)];
		r[1] = m->field[c_p(c->pos + 3)];
		r[2] = m->field[c_p(c->pos + 4)];
		if (r[0] > 0 && r[0] <= 16
			&& r[1] > 0 && r[1] <= 16 && r[2] > 0 && r[2] <= 16)
		{
			c->reg[r[2] - 1] = c->reg[r[0] - 1] - c->reg[r[1] - 1];
			if (c->reg[r[2] - 1] == 0)
				c->carry = 1;
			else
				c->carry = 0;
		}
	}
	move_next(c, type, g_add_sub);
}
