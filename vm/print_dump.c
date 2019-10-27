/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:55:48 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/15 15:55:49 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		print_hex1(int i)
{
	char	*s;
	char	out[4];
	int		j;

	j = 0;
	s = "0123456789abcdef";
	while (j < 4)
	{
		out[j] = s[i % 16];
		++j;
		i /= 16;
	}
	j = 4;
	write(1, "0x", 2);
	while (--j >= 0)
		write(1, &out[j], 1);
	write(1, " : ", 3);
}

void		print_hex2(unsigned char octet, int i)
{
	char	*c;

	c = "0123456789abcdef";
	if (i && i % 64 == 0)
	{
		write(1, "\n", 1);
		print_hex1(i);
	}
	write(1, &c[octet / 16], 1);
	write(1, &c[octet % 16], 1);
	write(1, " ", 1);
}

int			dump_memory(char *field)
{
	int		i;

	i = 0;
	print_hex1(i);
	while (i < MEM_SIZE)
	{
		print_hex2((unsigned char)field[i], i);
		++i;
	}
	write(1, "\n", 1);
	return (1);
}
