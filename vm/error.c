/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:06:17 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/13 15:06:18 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	show(t_player *player)
{
	int 	i;

	i = -1;
	while (++i < 4)
	{
		if (player[i].name)
			printf("%s\n", player[i].name);
		if (player[i].comment)
			printf("%s\n", player[i].comment);
	}
}

void	free_cursor(t_main *main)
{
	t_cursor	*tmp;
	t_cursor	*c;

	c = main->cursor;
	while (c)
	{
		tmp = c->next;
		free(c->reg);
		free(c);
		c = tmp;
	}
	main->cursor = 0;
}

void	free_player(t_player *player)
{
	int 	i;

	i = -1;
	while (++i < 4)
	{
		if (player[i].name)
			free(player[i].name);
		if (player[i].comment)
			free(player[i].comment);
		if (player[i].code)
			free(player[i].code);
	}
	free(player);
}

void	free_main(t_main *main)
{
	free_player(main->player);
	free_cursor(main);
	free(main->field);
	free(main);
}

int		ft_error(char *str)
{
	ft_putendl(str);
	return (0);
}