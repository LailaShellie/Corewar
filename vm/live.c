/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:34:56 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/17 17:34:59 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int 	g_live[6] = {1, 0, T_DIR, 0, 0, 4};

void		do_live(t_main *m, t_cursor *c)
{
	char	dir[4];
	int 	i;
	int 	t_dir;

	i = -1;
	while (++i < g_live[T_DIR_SIZE])
		dir[3 - i] = m->field[c_p(c->pos + 1 + i)];
	t_dir = ft_abs(*((int *)dir));
	++m->live_num;
	c->last_live_cycle = m->total_cycle;
	if (t_dir > 0 && t_dir <= m->num_of_players)
		m->last_player_live = t_dir;
	c->pos = c_p(c->pos + g_live[T_DIR_SIZE] + 1);
}
