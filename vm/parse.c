/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:41:52 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/13 16:41:53 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		get_size(t_player *player, int fd)
{
	int 	i;
	char	buf[4];
	char	size[4];

	i = -1;
	if (read(fd, buf, 4) < 0)
		return (ft_error(READ_ERROR));
	while (++i < 4)
		size[i] = buf[3 - i];
	player->size = *((int *)size);
	if (player->size > CHAMP_MAX_SIZE)
		return (ft_error(INV_CHAP_SIZE));
	return (1);
}

int		get_header(int fd)
{
	int 	i;
	char	buf[4];
	char	str[4];

	i = -1;
	if (read(fd, buf, 4) < 0)
		return (ft_error(READ_ERROR));
	while (++i < 4)
		str[i] = buf[3 - i];
	if (*((int *)str) != COREWAR_EXEC_MAGIC)
		return (ft_error(BAD_HEADER));
	return (1);
}

int		get_null(int fd)
{
	char 	buf[4];

	if (read(fd, buf, 4) < 0)
		return (ft_error(READ_ERROR));
	if (*((int *)buf) != 0)
		return (ft_error(NO_NULL));
	return (1);
}

int		get_code(t_player *player, int fd)
{
	char	buf[player->size + 1];
	int 	ret;

	if ((ret = read(fd, buf, player->size)) < 0)
		return (ft_error(READ_ERROR));
	buf[ret] = 0;
	if (ret != player->size)
		return (ft_error(INV_CHAP_SIZE));
	if (!(player->code = ft_strndup(buf, ret)))
		return (ft_error(INVALID_MALLOC));
	if (read(fd, buf, 1) > 0)
		return (ft_error(INV_CHAP_SIZE));
	return (1);
}

int		get_name_or_comment(t_player *player, int fd, int fl)
{
	int 	ret;
	char 	buf1[129];
	char	buf2[2049];

	if (fl == GET_NAME)
	{
		if ((ret = read(fd, buf1, 128)) < 0)
			return (ft_error(READ_ERROR));
		buf1[ret] = 0;
		if (!(player->name = ft_strdup(buf1)))
			return (ft_error(INVALID_MALLOC));
	}
	else if (fl == GET_COMMENT)
	{
		if ((ret = read(fd, buf2, 2048)) < 0)
			return (ft_error(READ_ERROR));
		buf2[ret] = 0;
		if (!(player->comment = ft_strdup(buf2)))
			return (ft_error(INVALID_MALLOC));
	}
	return (1);
}
