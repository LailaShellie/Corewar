/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:16:34 by blanna            #+#    #+#             */
/*   Updated: 2019/10/28 12:16:36 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	free_token(t_tkn **tkn)
{
	t_tkn	*temp;

	if (!tkn)
		return ;
	while ((*tkn)->prev)
		*tkn = (*tkn)->prev;
	while (*tkn)
	{
		temp = *tkn;
		*tkn = (*tkn)->next;
		(temp->cont) ? ft_strdel(&temp->cont) : 0;
		free(temp);
	}
}

static void	free_label(t_lbl **lbl)
{
	t_lbl	*temp;

	if (!lbl)
		return ;
	while (*lbl)
	{
		temp = *lbl;
		*lbl = (*lbl)->next;
		free(temp);
	}
}

void		free_all(t_ass *d_asm)
{
	if (d_asm->bytecod)
		free(d_asm->bytecod);
	if (d_asm)
	{
		(d_asm->fd) ? close(d_asm->fd) : 0;
		free_label(&d_asm->lbl);
		free_token(&d_asm->tkn);
	}
	exit(0);
}
