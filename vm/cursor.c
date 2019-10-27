/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:19:31 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/14 15:19:32 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		set_cursor(t_cursor **first, t_cursor *cursor)
{
	t_cursor *tmp;

	if (!*first)
		*first = cursor;
	else
	{
		tmp = *first;
		*first = cursor;
		cursor->next = tmp;
	}
}

t_cursor	*new_cursor(void)
{
	t_cursor *new;

	if (!(new = (t_cursor *)ft_memalloc(sizeof(t_cursor))))
		return (0);
	if (!(new->reg = (int *)ft_memalloc(sizeof(int) * REG_NUMBER)))
		return (0);
	return (new);
}
