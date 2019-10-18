/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cursors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:07:16 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/17 13:07:17 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int 	check_cursors(t_main *main)
{
	t_cursor	*c;
	t_cursor	*prev;

	prev = 0;
	c = main->cursor;
	if (main->cycles_to_die <= 0)
	{
		free_cursor(main);
		return (1);
	}
	while (c)
	{
		if (main->total_cycle - c->last_live_cycle >= main->cycles_to_die)
		{
			if (!prev)
			{
				main->cursor = c->next;
				free(c->reg);
				free(c);
				c = main->cursor;
				continue ;
			}
			else
			{
				prev->next = c->next;
				free(c->reg);
				free(c);
				c = prev;
			}
		}
		prev = c;
		c = c->next;
	}
	return (1);
}

int 	check(t_main *main)
{
	++main->check_num;
	check_cursors(main);
	if (main->live_num >= NBR_LIVE)
	{
		main->cycles_to_die -= CYCLE_DELTA;
		main->check_num = 0;
		main->cycle = 0;
//		main->live_num = 0;
	}
	else if (main->check_num >= MAX_CHECKS)
	{
		main->cycles_to_die -= CYCLE_DELTA;
		main->check_num = 0;
		main->cycle = 0;
		main->live_num = 0;
	}
	return (1);
}
