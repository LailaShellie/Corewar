/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:17:11 by blanna            #+#    #+#             */
/*   Updated: 2019/10/28 12:17:12 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			get_direct(t_ass *d_asm, char *line)
{
	if (line[J] == LABEL_CHAR && ++J)
		add_text(d_asm, line, DIRECT_LABEL);
	else
		add_number(d_asm, line, DIRECT);
}

static void		check_fname(t_ass *d_asm, char *fname)
{
	if (!((fname[ft_strlen(fname) - 2] == '.') && \
	(fname[ft_strlen(fname) - 1] == 's')))
	{
		ft_printf("%s\n", "ERROR: Invalid file format");
		exit(EXIT_FAILURE);
	}
}

static t_tkn	*begin_of_list(t_ass *d_asm)
{
	t_tkn		*code;

	code = d_asm->tkn;
	while (code->next)
		code = code->next;
	d_asm->tkn = code;
	return (code);
}

void			my_asm(char *f_name)
{
	t_ass		d_asm;
	t_tkn		*code;

	ft_bzero(&d_asm, sizeof(d_asm));
	check_fname(&d_asm, f_name);
	d_asm.magic = COREWAR_EXEC_MAGIC;
	d_asm.fd = ft_read_file(f_name);
	d_asm.f_name = f_name;
	lexical_check(&d_asm);
	code = begin_of_list(&d_asm);
	champ_data_check(&d_asm, &code);
	syntax_check(&d_asm, code);
	if (!(d_asm.bytecod = (char*)malloc(sizeof(char) * \
	(BEGIN_EXEC + d_asm.code_bytes))))
		error(&d_asm, MEM, 0, 0);
	ft_bzero(d_asm.bytecod, BEGIN_EXEC + d_asm.code_bytes);
	into_bytecode(&d_asm);
	code_to_file(&d_asm);
	free_all(&d_asm);
}
