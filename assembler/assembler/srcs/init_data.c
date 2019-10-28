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

static void		lable_duplicates(t_ass *d_asm)
{
	char	*origin;
	t_lbl	*temp;

	origin = d_asm->lbl->locat->cont;
	temp = d_asm->lbl->next;
	while (temp)
	{
		if (ft_strequ(origin, temp->locat->cont))
			error(d_asm, LBL_NAME, temp->locat, 2);
		temp = temp->next;
	}
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
	lable_duplicates(d_asm);
}
