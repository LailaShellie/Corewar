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

int			main(int ac, char **av)
{
	t_player	*player;
	int 		i;

	i = -1;
	if (ac < 2)
		return (error(NO_ARG));
	if (!(player = (t_player *)ft_memalloc(sizeof(t_player) * MAX_PLAYERS)))
		return (0);
	while (++i < MAX_PLAYERS)
		player[i].size = -1;
	if (!(read_files(player, ac, av)))
	{
//		show(player);
		free_player(player);
		return (0);
	}
//	show(player);
	free_player(player);
	return (0);
}
