/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:16:42 by blanna            #+#    #+#             */
/*   Updated: 2019/10/28 12:16:44 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			add_token(t_ass *d_asm, t_type type)
{
	t_tkn	*new;

	if (!(new = (t_tkn*)ft_memalloc(sizeof(t_tkn))))
		error(d_asm, MEM, 0, 0);
	ft_bzero(new, sizeof(new));
	new->y = ST;
	new->x = J;
	new->type = type;
	if (d_asm->tkn)
		d_asm->tkn->prev = new;
	new->next = d_asm->tkn;
	d_asm->tkn = new;
}

void			add_label(t_ass *d_asm)
{
	t_lbl	*new;

	if (!(new = (t_lbl*)ft_memalloc(sizeof(t_lbl))))
		error(d_asm, MEM, 0, 0);
	ft_bzero(new, sizeof(new));
	J++;
	d_asm->tkn->type = LABEL;
	new->locat = d_asm->tkn;
	if (d_asm->lbl)
		d_asm->lbl->prev = new;
	new->next = d_asm->lbl;
	d_asm->lbl = new;
}

int				nbrlen(unsigned long long num, int neg)
{
	int i;

	i = num == 0 ? 1 : 0;
	while (num)
	{
		i++;
		num /= 10;
	}
	if (neg)
		i++;
	return (i);
}

void			sila(const char *str, int *i, int *neg, int *h)
{
	int		neg1;
	int		i1;
	int		h1;

	i1 = 0;
	neg1 = 0;
	h1 = 0;
	while (str[i1] == ' ' || str[i1] == '\n' || str[i1] == '\t')
		i1++;
	if (str[i1] == '-')
		neg1 = 1;
	if ((str[i1] == '-') || (str[i1] == '+'))
		i1++;
	while (str[i1] == '0')
	{
		h1++;
		i1++;
	}
	*i = i1;
	*neg = neg1;
	*h = h1;
}
