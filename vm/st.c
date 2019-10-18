/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:36:46 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/18 15:36:48 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

# define T_REG_REG 0x50
# define T_REG_IND 0x70

int 	g_st[6] = {2, 1, T_REG, T_REG | T_DIR, 0, 4};

int			get_ind(t_main *m, t_cursor *c, int pos)
{
	char	dir[4];
	int		i;
	int		t_dir;

	i = -1;
	while (++i < 2)
		dir[1 - i] = m->field[c_p(c->pos + pos + i)];
	t_dir = (*((short *)dir));
	return (t_dir % IDX_MOD);
}

static void			set_mem(t_main *m, t_cursor *c, int pos, int reg_i)
{
	int				i;
	unsigned char 	*reg;

	reg = (unsigned char *)(&c->reg[reg_i]);
	i = -1;
	while (++i < 4)
	{
		printf("%d\n", c_p(c->pos + pos + i));
		m->field[c_p(c->pos + pos + i)] = reg[3 - i];
	}
}

void		do_st(t_main *m, t_cursor *c)
{
	unsigned int	type;
	char 			r1;
	char 			r2;

	type = m->field[c_p(c->pos + 1)];
	if (type == T_REG_REG && c->reg[m->field[c_p(c->pos + 2)]] > 0)
	{
		r1 = m->field[c_p(c->pos + 2)];
		r2 = m->field[c_p(c->pos + 2 + REG_SIZE)];
		if (r1 > 0 && r1 <= 16 && r2 > 0 && r2 <= 16)
			c->reg[r2 - 1] = c->reg[r1 - 1];
	}
	else if (type == T_REG_IND)
	{
		r1 = m->field[c_p(c->pos + 2)];
		if (r1 > 0 && r1 <= 16)
		{
			set_mem(m, c, get_ind(m, c, 3), r1 - 1);
		}
	}
	move_next(c, type, g_st);
}