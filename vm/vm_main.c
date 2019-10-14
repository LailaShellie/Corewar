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

void		count_players(t_main *main)
{
	int		i;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (main->player[i].size >= 0)
			++main->num_of_players;
	}
}

int			init_game(t_main **main)
{
	int 	i;

	i = -1;
	if (!(*main = (t_main *)ft_memalloc(sizeof(t_main))))
		return (0);
	if (!((*main)->field = (char *)ft_memalloc(MEM_SIZE)))
		return (0);
	if (!((*main)->player = (t_player *)ft_memalloc(sizeof(t_player) * MAX_PLAYERS)))
		return (0);
	while (++i < MAX_PLAYERS)
		(*main)->player[i].size = -1;
	(*main)->cycles_to_die = CYCLE_TO_DIE;
	(*main)->last_player_live = 1;
	(*main)->cycle = 0;
	(*main)->live_num = 0;
	(*main)->check_num = 0;
	return (1);
}

int			main(int ac, char **av)
{
	t_main		*main;

	main = 0;
	if (ac < 2)
		return (error(NO_ARG));
	if (!(init_game(&main)))
		return (error(INVALID_MALLOC));
	if (!(read_files(main->player, ac, av)))
	{
		free_main(main);
		return (0);
	}
	count_players(main);
	start_game(main);
	free_main(main);
	return (0);
}
