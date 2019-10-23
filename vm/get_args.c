/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:47:32 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/23 14:47:33 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int 		read_mem(char *f, int pos, int size)
{
	int 	i;
	char 	ret[4];

	i = -1;
	while (++i < 4)
		ret[i] = 0;
	i = -1;
	while (++i < size)
		ret[size - i - 1] = f[c_p(pos + i)];
	if (size == 1)
		return (ret[0]);
	else if (size == 2)
		return (*((short *)ret));
	else if (size == 4)
		return (*((int *)ret));
	return (0);
}

void		get_ind(t_main *m, t_cursor *c, t_o *o)
{
	int 	i;

	i = -1;
	while (++i < 3)
	{
		if (o->t[i] == IND)
			o->x[i] = read_mem(m->field, c->pos + o->x[i] % IDX_MOD, 4);
	}
}

void		get_args(t_main *m, t_cursor *c, t_o *o)
{
	if (o->t[0])
		o->x[0] = read_mem(m->field, c->pos + 2, o->s[0]);
	if (o->t[1])
		o->x[1] = read_mem(m->field, c->pos + 2 + o->s[0], o->s[1]);
	if (o->t[2])
		o->x[2] = read_mem(m->field, c->pos + 2 + o->s[0] + o->s[1], o->s[2]);
	if (c->op != 3)
		get_ind(m, c, o);
}
