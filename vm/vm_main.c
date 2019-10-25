/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:56:08 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/13 14:56:10 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		choose_winner(t_main *m)
{
	t_player	*winner;
	int 		i;

	winner = m->player;
	i = m->last_player_live;
	while (winner)
	{
		if (winner->num + 1 == i)
			break ;
		winner = winner->next;
	}
	if (winner)
		printf("Contestant %d, \"%s\", has won !\n", m->last_player_live, winner->name);
}

int 		count_players(t_main *m, t_player *p)
{
	int 	i;

	i = 0;
	m->last_player_live = p->num + 1;
	while (p)
	{
		++i;
		p = p->next;
	}
	return (i);
}

int			init_game(t_main **main)
{
	if (!(*main = (t_main *)ft_memalloc(sizeof(t_main))))
		return (0);
	if (!((*main)->field = (char *)ft_memalloc(MEM_SIZE)))
		return (0);
	(*main)->cycles_to_die = CYCLE_TO_DIE;
	(*main)->last_player_live = 1;
	(*main)->cycle = 0;
	(*main)->live_num = 0;
	(*main)->check_num = 0;
	(*main)->dump = -1;
	(*main)->n_flag = -1;
	return (1);
}

int			main(int ac, char **av)
{
	t_main		*m;

	m = 0;
	if (ac < 2)
	{
		ft_error(NO_ARG);
		return (-1);
	}
	if (!(init_game(&m)))
		return (ft_error(INVALID_MALLOC));
	if (!manage_n(m, ac, av) || !(read_files(m, ac, av)))
	{
		free_main(m);
		return (-1);
	}
	m->num_of_players = count_players(m, m->player);
	if (!(start_game(m)))
	{
		free_main(m);
		return (0);
	}
	choose_winner(m);
	free_main(m);
	return (0);
}
