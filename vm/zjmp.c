/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:07:35 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/18 20:07:36 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

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

void		do_zjmp(t_main *m, t_cursor *c)
{
	if (c->carry)
		c->pos = c_p(c->pos + get_dir(m, c, 1) % IDX_MOD);
}
