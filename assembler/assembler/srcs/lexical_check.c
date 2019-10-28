/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:16:57 by blanna            #+#    #+#             */
/*   Updated: 2019/10/28 12:16:59 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		add_text(t_ass *d_asm, char *line, t_type type)
{
	int		temp;
	int		lenres;

	temp = J;
	add_token(d_asm, type);
	while (line[J] && ft_findchar(LABEL_CHARS, line[J]))
		J++;
	lenres = J - temp;
	d_asm->tkn->cont = ft_strsub(line, temp, lenres);
	if (lenres && line[J] == LABEL_CHAR)
		add_label(d_asm);
	else if (lenres && (SPACER1(line[J]) || SPACER2(line[J])))
	{
		if (type == INDIRECT)
			d_asm->tkn->type = (check_reg(line + temp, lenres))
			? REGISTER : INSTRUCTION;
	}
	else
		error(d_asm, TEXT, 0, 0);
}

static void	add_string(t_ass *d_asm, char **line)
{
	int		len;
	int		size;
	char	*str;
	char	*temp;

	temp = 0;
	str = *line;
	while (++ST && !(len = ft_findchar(str + J, '\"'))\
	&& (size = read_line(d_asm->fd, &temp)))
		ft_strmerge(&str, &temp);
	if (!len)
		error(d_asm, STR_STOP, 0, 1);
	if (len > PROG_NAME_LENGTH && \
	ft_strequ(d_asm->tkn->cont, "name"))
		error(d_asm, CHAMP_NAME, 0, 0);
	else if (len > COMMENT_LENGTH && \
	ft_strequ(d_asm->tkn->cont, "comment"))
		error(d_asm, COM, 0, 0);
	*line = str;
	add_token(d_asm, STRING);
	d_asm->tkn->cont = ft_strsub(str, J, len - 1);
	J += len;
}

void		add_number(t_ass *d_asm, char *line, t_type type)
{
	int		temp;
	int		lenres;

	temp = J;
	(line[J] == '-') ? J++ : 0;
	(line[J] == '+') ? error(d_asm, PLUS, 0, 1) : 0;
	while (ft_isdigit(line[J]))
		J++;
	lenres = J - temp;
	if (lenres && (type == DIRECT || SPACER1(line[J]) || SPACER2(line[J])))
	{
		add_token(d_asm, type);
		d_asm->tkn->cont = ft_strsub(line, temp, lenres);
	}
	else if (type == INDIRECT)
	{
		J = temp;
		add_text(d_asm, line, INDIRECT);
	}
	else
		error(d_asm, TEXT, 0, 0);
}

static void	break_into_pieces(t_ass *d_asm, char **str)
{
	char	*line;

	line = *str;
	if (line[J] == '\"' && ++J)
		add_string(d_asm, &line);
	else if (line[J] == '\n' && ++J)
		add_token(d_asm, NEW_LINE);
	else if (line[J] == '.' && ++J)
		add_text(d_asm, line, COMMAND);
	else if (line[J] == SEPARATOR_CHAR && ++J)
		add_token(d_asm, SEPARATOR);
	else if (line[J] == LABEL_CHAR && ++J)
		add_text(d_asm, line, INDIRECT_LABEL);
	else if (line[J] == DIRECT_CHAR && ++J)
		get_direct(d_asm, line);
	else
		add_number(d_asm, line, INDIRECT);
	*str = line;
}

void		lexical_check(t_ass *d_asm)
{
	int		size;
	char	*line;

	while ((size = read_line(d_asm->fd, &line)))
	{
		while (line[J])
		{
			skip_spaces(d_asm, line);
			skip_comm(d_asm, line);
			if (line[J])
				break_into_pieces(d_asm, &line);
		}
		ft_strdel(&line);
		J = 0;
		ST++;
	}
	(size == -1) ? error(d_asm, READ, 0, 0) : 0;
	add_token(d_asm, END);
}
