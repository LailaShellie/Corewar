/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:37:15 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/14 13:45:29 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int 		paste_code(t_main *main, t_player *player, int pos)
{
	int 	i;

	i = -1;
	while (++i < player->size)
		main->field[(pos + i) % MEM_SIZE] = player->code[i];
	return (1);
}

int 		set_players(t_main *main)
{
	int 	i;
	int 	pos0;
	int 	pos;

	pos = 0;
	pos0 = MEM_SIZE / main->num_of_players;
	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (main->player[i].size >= 0)
		{
			set_cursor(&(main->cursor), new_cursor());
			main->cursor->reg[0] = -(i + 1);
			main->cursor->id = main->cursor_ids++;
			paste_code(main, &(main->player[i]), pos);
			main->cursor->pos = pos;
			pos += pos0;
		}
	}
	return (1);
}

int 		introduce(t_player *player)
{
	int 	i;

	i = -1;
	ft_putendl("Introducing contestants...");
	while (++i < MAX_PLAYERS)
	{
		if (player[i].size >= 0)
		{
			ft_putstr("* Player ");
			ft_putnbr(i + 1);
			ft_putstr(", weighing ");
			ft_putnbr(player[i].size);
			ft_putstr(" bytes, \"");
			ft_putstr(player[i].name);
			ft_putstr("\" (\"");
			ft_putstr(player[i].comment);
			ft_putendl("\") !");
		}
	}
	return (1);
}

int 		start_game(t_main *main)
{
	introduce(main->player);
	set_players(main);
	start_fight(main);
	return (1);
}
