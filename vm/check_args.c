/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 12:46:00 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/20 12:46:01 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int 	g_dir[17] = {DIR, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 4};

void	choose_type(char *args, unsigned char type, int num)
{
	if (type == DIR)
		args[num] = DIR;
	else if (type == REG)
		args[num] = REG;
	else if (type == IND)
		args[num] = IND;
	else
		args[num] = 0;
}

int		ft_size(char type, t_cursor *c)
{
	if (type == REG)
		return (1);
	else if (type == IND)
		return (2);
	else if (type == DIR)
		return (g_dir[c->op]);
	return (0);
}

void	get_args(char *args, unsigned char byte)
{
	unsigned char 	tmp;
	int 			i;
	int 			j;
	int 			num;

	num = 0;
	i = 8;
	tmp = 0;
	j = 0;
	while (--i >= 0)
	{
		if (byte & (1 << i))
			tmp |= 1 << j;
		++j;
		if (j == 2)
		{
			choose_type(args, tmp, num);
			++num;
			j = 0;
			tmp = 0;
		}
	}
}
