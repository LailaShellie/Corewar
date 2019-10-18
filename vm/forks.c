/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:34:15 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/18 20:34:16 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

#define T_DIR 0x40

int 			g_aff[6] = {1, 0, T_REG, 0 , 0, 4};

static int		get_dir(t_main *m, t_cursor *c, int pos)
{
	char	dir[4];
	int		i;
	int		t_dir;

	i = -1;
	while (++i < 2)
		dir[1 - i] = m->field[c_p(c->pos + pos + i)];
	t_dir = (*((int *)dir));
	return (t_dir);
}

void		do_aff(t_main *m, t_cursor *c)
{
	int 	type;
	char	r;

	type = m->field[c_p(c->pos + 1)];
	if (type == T_DIR)
	{
		r = m->field[c_p(c->pos + 2)];
		if (r > 0 && r <= 16)
			ft_putchar(c->reg[r]);
	}
	move_next(c, type, g_aff);
}

void		do_fork(t_main *m, t_cursor *c)
{
	int 		dir;
	t_cursor	*new;
	int 		i;

	i = -1;
	dir = get_dir(m, c, c_p(c->pos + 1)) % IDX_MOD;
	printf("%d\n", dir % IDX_MOD);
	new = new_cursor();
	new->pos = c_p(c->pos + dir);
	new->last_live_cycle = c->last_live_cycle;
	while (++i < 16)
		new->reg[i] = c->reg[i];
	new->id = ++m->cursor_ids;
	new->carry = c->carry;
	set_cursor(&m->cursor, new);
}

void		do_lfork(t_main *m, t_cursor *c)
{
	int 		dir;
	t_cursor	*new;
	int 		i;

	i = -1;
	dir = get_dir(m, c, c_p(c->pos + 1));
	printf("%d\n", dir);
	new = new_cursor();
	new->pos = c_p(c->pos + dir);
	new->last_live_cycle = c->last_live_cycle;
	while (++i < 16)
		new->reg[i] = c->reg[i];
	new->carry = c->carry;
	new->id = ++m->cursor_ids;
	set_cursor(&m->cursor, new);
}
