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

void		print_hex_int(int i)
{
	char	*s;
	char 	out[4];
	int 	j;

	j = 0;
	s = "0123456789abcdef";
	while (j < 4)
	{
		out[j] = s[i % 16];
		++j;
		i /= 16;
	}
	j = 4;
	printf("0x");
	while (--j >= 0)
		printf("%c", out[j]);
	printf(" : ");
}

int 	find_cursor(t_cursor *c, int i)
{
	while (c)
	{
		if (c->pos == i)
			return (1);
		c = c->next;
	}
	return (0);
}

void		print_hex_char(unsigned char octet, int i, t_cursor *c)
{
	char	*s;

	s = "0123456789abcdef";
	if (i && i % 64 == 0)
	{
		printf("\n");
		print_hex_int(i);
	}
	if (!(find_cursor(c, i)))
	{
		if (s[octet / 16] == '0')
			printf("0");
		printf("%x ", octet);
	}
	else
	{
		if (s[octet / 16] == '0')
			printf("\033[031;43m0\033[0m");
		printf("\033[031;43m%x\033[0m ", octet);
	}
	//write(1, &c[octet % 16], 1);
}

int 		dump_memory_64(char *field, t_cursor *c)
{
	int 	i;

	i = 0;
	print_hex_int(i);
	while (i < MEM_SIZE)
	{
		print_hex_char((unsigned char)field[i], i, c);
		++i;
	}
//	write(1, "\n", 1);
	printf("\n");
	return (1);
}

