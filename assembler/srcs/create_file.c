/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:16:28 by blanna            #+#    #+#             */
/*   Updated: 2019/10/28 12:16:29 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*new_fname(char *name)
{
	char		*ext_ptr;

	ext_ptr = &name[ft_strlen(name) - 1];
	ext_ptr = ft_strcpy(ext_ptr, "cor");
	return (name);
}

void			code_to_file(t_ass *d_asm)
{
	int			fd;
	char		*new_name;

	new_name = new_fname(d_asm->f_name);
	if ((fd = open(new_name, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		error(d_asm, NOCREATE, 0, 0);
	if (write(fd, d_asm->bytecod, BEGIN_EXEC + d_asm->code_bytes) == -1)
	{
		close(fd);
		error(d_asm, NOWRITE, 0, 0);
	}
	ft_printf("Writing output program to %s\n", new_name);
	close(fd);
}
