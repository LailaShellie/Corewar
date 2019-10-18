/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:35:33 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/17 17:35:34 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

#define T_DIR_REG 144
#define T_IND_REG 0x0d

int			g_ld[6] = {2, 1, T_DIR | T_IND, T_DIR, 0, 4};

static int		get_dir(t_main *m, t_cursor *c, int pos)
{
	char	dir[4];
	int		i;
	int		t_dir;

	i = -1;
	while (++i < 4)
		dir[3 - i] = m->field[c_p(c->pos + pos + i)];
	t_dir = (*((int *)dir));
	return (t_dir);
}

static int		get_ind(t_main *m, t_cursor *c, int pos)
{
	char	dir[4];
	int		i;
	int		t_dir;

	i = -1;
	while (++i < 2)
		dir[1 - i] = m->field[c_p(c->pos + pos + i)];
	t_dir = (*((short *)dir));
	return (t_dir % IDX_MOD);
}

void		do_ld(t_main *m, t_cursor *c)
{
	unsigned char	type;

	type = m->field[c_p(c->pos + 1)];
	if (type == T_DIR_REG && m->field[c_p(c->pos + 2 + g_ld[T_DIR_SIZE])] > 0
		&& m->field[c->pos + 2 + g_ld[T_DIR_SIZE]] <= 16)
	{
		if (!(c->reg[m->field[c_p(c->pos + 2 + g_ld[T_DIR_SIZE])]] = get_dir(m, c, 2)))
			c->carry = 0;
		else
			c->carry = 1;
	}
	else if (type == T_IND_REG && m->field[c_p(c->pos + 2 + IND_SIZE)] > 0
	&& m->field[c_p(c->pos + 2 + IND_SIZE)] <= 16)
	{
		if (!(c->reg[c_p(m->field[c->pos + 2 + IND_SIZE])] = get_dir(m, c, get_ind(m, c, 2))))
			c->carry = 0;
		else
			c->carry = 1;
	}
	move_next(c, type, g_ld);
}
