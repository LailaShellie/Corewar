/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:00:18 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/22 16:00:19 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

static void		set_a(t_player *player, int *a)
{
	while (player)
	{
		a[player->num] = 1;
		player = player->next;
	}
}

int				set_player(t_main *m, t_player *new)
{
	t_player	*tmp;
	int 		*a;
	int 		i;

	i = -1;
	a = ft_memalloc(sizeof(int) * 4);
	set_a(m->player, a);
	while (++i < MAX_PLAYERS)
	{
		if (!a[i])
		{
			new->num = i;
			break ;
		}
	}
	free(a);
	tmp = m->player;
	m->player = new;
	new->next = tmp;
	if (new->num < 0)
		return (ft_error(WRONG_NUM));
	return (1);
}

static int 		check_a(t_player *player, t_player *new)
{
	while (player)
	{
		if (player->num == new->num)
			return (ft_error(BAD_FLAG));
		player = player->next;
	}
	return (1);
}

int				set_player_fl(t_main *m, t_player *new)
{
	t_player *tmp;

	if (!(check_a(m->player, new)))
	{
		tmp = m->player;
		m->player = new;
		new->next = tmp;
		return (0);
	}
	tmp = m->player;
	m->player = new;
	new->next = tmp;
	return (1);
}

void			swap_players(t_player *a, t_player *b)
{
	t_player	tmp;

	tmp.num = a->num;
	tmp.code = a->code;
	tmp.comment = a->comment;
	tmp.name = a->name;
	tmp.size = a->size;
	a->num = b->num;
	a->code = b->code;
	a->comment = b->comment;
	a->name = b->name;
	a->size = b->size;
	b->num = tmp.num;
	b->code = tmp.code;
	b->comment = tmp.comment;
	b->name = tmp.name;
	b->size = tmp.size;
}