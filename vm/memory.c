/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:48:42 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/20 15:48:43 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int 	read_mem(t_main *m, int pos, int size)
{
	char	*dir;
	int 	i;
	int 	ret;

	dir = ft_memalloc(4);
	i = -1;
	while (++i < size)
	{
		dir[size - i - 1] = m->field[i];
	}
	if (size == 2)
		ret = *((short *)dir);
	else if (size == 4)
		ret = *((int *)dir);
	return (ret);
}
