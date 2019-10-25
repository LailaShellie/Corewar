/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:53:01 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/13 15:53:02 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int			check_file_format(char *str)
{
	int 	len;
//
//	len = ft_strlen(str);
//	if (len < 4)
//		return (0);
//	if (len == 4 && ft_strcmp(str, ".cor"))
//		return (0);
//	if (len > 4 && ft_strcmp(&str[len - 4], ".cor"))
//		return (0);
	return (1);
}

t_player		*choose_player(t_main *m)
{
	t_player	*new;

	if (m->n_flag == -1)
	{
		new = ft_memalloc(sizeof(t_player));
		new->num = -1;
		if (!(set_player(m, new)))
			return (0);
	}
	else if (m->n_flag > 0 && m->n_flag <= MAX_PLAYERS)
	{
		new = ft_memalloc(sizeof(t_player));
		new->num = m->n_flag - 1;
		m->n_flag = -1;
		if (!(set_player_fl(m, new)))
			return (0);
	}
	else
		return (0);
	return (new);
}

int			parse_all(int fd, t_main *m)
{
	t_player *new;

	if (!(new = choose_player(m)))
		return (0);
	if (!(get_header(fd)))
		return (0);
	if (!(get_name_or_comment(new, fd, GET_NAME)))
		return (0);
	if (!(get_null(fd)))
		return (0);
	if (!(get_size(new, fd)))
		return (0);
	if (!(get_name_or_comment(new, fd, GET_COMMENT)))
		return (0);
	if (!(get_null(fd)))
		return (0);
	if (!(get_code(new, fd)))
		return (0);
	return (1);
}

int			read_player(t_main *m, char *str)
{
	int 	fd;

	if ((fd = open(str, O_RDONLY)) < 0)
		return (ft_error(CANT_OPEN_FILE));
	if (!(parse_all(fd, m)))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int			read_files(t_main *m, int ac, char **av)
{
	int 	i;

	i = 0;
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "-dump") && i + 1 < ac && is_number(av[i + 1]))
		{
			m->dump = ft_atoi(av[++i]);
			continue ;
		}
		if (!ft_strcmp(av[i], "-n") && i + 2 < ac)
		{
			i += 2;
			continue ;
		}
		if (check_file_format(av[i]))
		{
			if (!(read_player(m, av[i])))
				return (0);
		}
		else
			return (ft_error(BAD_FILE_FORMAT));
	}
	return (1);
}

int 		manage_n(t_main *m, int ac, char **av)
{
	int 	i;

	i = 0;
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "-n") && i + 2 < ac && is_number(av[i + 1]))
		{
			m->n_flag = ft_atoi(av[++i]);
			if (!(m->n_flag > 0 && m->n_flag <= MAX_PLAYERS))
				return (ft_error(BAD_FLAG));
			if (check_file_format(av[++i]))
			{
				if (!(read_player(m, av[i])))
					return (0);
			}
			else
				return (ft_error(BAD_FILE_FORMAT));
		}
	}
	return (1);
}
