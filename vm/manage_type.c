/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:48:49 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/27 15:48:50 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int			g_dir[17] = {T_DIR_SIZE,
	4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 4};

int			s(int t, int op)
{
	if (t == REG)
		return (1);
	else if (t == IND)
		return (2);
	else if (t == DIR)
		return (g_dir[op]);
	return (0);
}

void		*free_o(t_o *o)
{
	free(o->x);
	free(o->s);
	free(o->t);
	free(o);
	return (0);
}

int			choose_type(char tmp)
{
	if (tmp == REG)
		return (REG);
	else if (tmp == IND)
		return (IND);
	else if (tmp == DIR)
		return (DIR);
	return (0);
}
