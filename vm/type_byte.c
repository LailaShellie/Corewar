/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_byte.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:42:33 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/23 13:42:35 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int			g_num[17] = {NUM_ARG, 1, 2, 2,
	3, 3, 3, 3, 3, 1, 3, 3, 1, 2, 3, 1, 1};

int			check_args(t_cursor *c, t_o *o)
{
	int		i;

	i = -1;
	while (++i < g_num[c->op])
	{
		if (o->t[i] == REG)
		{
			--o->x[i];
			if (!(o->x[i] >= 0 && o->x[i] < 16))
				return (0);
		}
	}
	return (1);
}

void		set_types(int *t, unsigned char types)
{
	int		i;
	int		j;
	int		k;
	char	tmp;

	k = 0;
	i = 8;
	tmp = 0;
	j = 0;
	while (--i >= 2)
	{
		if (types & (1 << i))
		{
			tmp |= (1 << k);
		}
		++k;
		if (k == 2)
		{
			t[j++] = choose_type(tmp);
			k = 0;
			tmp = 0;
		}
	}
}

void		find_step(t_cursor *c, t_o *o)
{
	int		step;
	int		i;

	i = -1;
	step = 0;
	while (++i < 3)
		o->s[i] = s(o->t[i], c->op);
	i = -1;
	while (++i < g_num[c->op])
		step += s(o->t[i], c->op);
	o->step = step + 2;
}

int			check_num(t_cursor *c, t_o *o)
{
	if (g_num[c->op] == 1 && !o->t[0])
		return (0);
	if (g_num[c->op] == 2 && (!o->t[0] || !o->t[1]))
		return (0);
	if (g_num[c->op] == 3 && (!o->t[0] || !o->t[1] || !o->t[2]))
		return (0);
	return (1);
}

t_o			*manage_type(t_main *m, t_cursor *c)
{
	t_o				*o;
	unsigned char	types;

	types = m->field[c_p(c->pos + 1)];
	if (!(o = ft_memalloc(sizeof(t_o))))
		return (0);
	if (!(o->t = ft_memalloc(sizeof(int) * 3)))
		return (free_o(o));
	if (!(o->s = ft_memalloc(sizeof(int) * 3)))
		return (free_o(o));
	if (!(o->x = ft_memalloc(sizeof(int) * 3)))
		return (free_o(o));
	set_types(o->t, types);
	find_step(c, o);
	get_args(m, c, o);
	if (!(check_args(c, o)) || !check_num(c, o))
	{
		c->pos = c_p(c->pos + o->step);
		return (free_o(o));
	}
	return (o);
}
