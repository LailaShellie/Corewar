/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:16:19 by blanna            #+#    #+#             */
/*   Updated: 2019/10/28 12:16:21 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	search_string(t_ass *d_asm, t_tkn **temp, int fl)
{
	*temp = (*temp)->prev;
	if (*temp && (*temp)->type == STRING)
		*temp = (*temp)->prev;
	else if (fl)
		error(d_asm, NONAME, *temp, 0);
	else
		error(d_asm, NOCOM, *temp, 0);
}

void		champ_data_check(t_ass *d_asm, t_tkn **temp)
{
	int		i;
	int		fl[2];

	i = -1;
	ft_bzero(fl, sizeof(fl));
	while (++i < 2)
	{
		while (*temp && (*temp)->type == NEW_LINE)
			*temp = (*temp)->prev;
		if ((*temp)->type != COMMAND)
			error(d_asm, CMD_NAME_COMM, *temp, 2);
		if (ft_strequ((*temp)->cont, "name"))
		{
			search_string(d_asm, temp, 1);
			fl[0] = 1;
		}
		else if (ft_strequ((*temp)->cont, "comment"))
		{
			search_string(d_asm, temp, 0);
			fl[1] = 1;
		}
	}
	if ((*temp)->type != NEW_LINE || !fl[0] || !fl[1])
		error(d_asm, CMD_NAME_COMM2, *temp, 0);
}

t_tkn		*champ_data_record(t_ass *d_asm, t_tkn *temp)
{
	int		i;

	i = -1;
	while (++i < 2)
	{
		while (temp && temp->type == NEW_LINE)
			temp = temp->prev;
		if (ft_strequ(temp->cont, "name"))
		{
			temp = temp->prev;
			ft_memcpy(d_asm->bytecod + BEGIN_NAME, \
			temp->cont, ft_strlen(temp->cont));
		}
		else if (ft_strequ(temp->cont, "comment"))
		{
			temp = temp->prev;
			ft_memcpy(d_asm->bytecod + BEGIN_COMMENT, \
			temp->cont, ft_strlen(temp->cont));
		}
		else
			error(d_asm, CMD_NAME_COMM2, temp, 0);
		temp = temp->prev;
	}
	return (temp);
}
