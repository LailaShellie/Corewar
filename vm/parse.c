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
		return (error(READ_ERROR));
	while (++i < 4)
		size[i] = buf[3 - i];
	player->size = *((int *)size);
	printf("%d\n", player->size);
//	if (player->size > CHAMP_MAX_SIZE)
//		return (error(INV_CHAP_SIZE));
	return (1);
}

int		get_header(t_player *player, int fd)
{
	int 	i;
	char	buf[4];

	i = -1;
	if (!(player->header = (char *)ft_memalloc(4)))
		return (0);
	if (read(fd, buf, 4) < 0)
	{
		free(player->header);
		return (error(READ_ERROR));
	}
	while (++i < 4)
		player->header[i] = buf[3 - i];
	if (*((int *)player->header) != COREWAR_EXEC_MAGIC)
		return (error(BAD_HEADER));
	return (1);
}

int		get_null(t_player *player, int fd)
{
	char 	buf[4];

	if (read(fd, buf, 4) < 0)
		return (error(READ_ERROR));
	if (*((int *)buf) != 0)
		return (error(NO_NULL));
	return (1);
}

int		get_code(t_player *player, int fd)
{
	char	buf[player->size + 1];
	int 	ret;

	if ((ret = read(fd, buf, player->size)) < 0)
		return (error(READ_ERROR));
	buf[ret] = 0;
	if (ret != player->size)
		return (error(INV_CHAP_SIZE));
	if (!(player->code = ft_strdup(buf)))
		return (error(INVALID_MALLOC));
	if (read(fd, buf, 1) > 0)
		return (error(INV_CHAP_SIZE));
	return (1);
}

int		get_name_or_comment(t_player *player, int fd, int fl)
{
	int 	i;
	int 	ret;
	char 	buf1[129];
	char	buf2[2049];

	if (fl == GET_NAME)
	{
		if ((ret = read(fd, buf1, 128)) < 0)
			return (error(READ_ERROR));
		buf1[ret] = 0;
		if (!(player->name = ft_strdup(buf1)))
			return (error(INVALID_MALLOC));
		printf("%s\n", player->name);
	}
	else if (fl == GET_COMMENT)
	{
		if ((ret = read(fd, buf2, 2048)) < 0)
			return (error(READ_ERROR));
		buf2[ret] = 0;
		if (!(player->comment = ft_strdup(buf2)))
			return (error(INVALID_MALLOC));
		printf("%s\n", player->comment);
	}
	return (1);
}
