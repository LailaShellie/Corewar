/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 14:51:18 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/13 14:51:19 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COREWAR_H
# define _COREWAR_H

# include "op.h"
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define GET_COMMENT 0
# define GET_NAME 1

# define NO_ARG "No arguments"
# define BAD_FLAG "Wrong -n flag"
# define BAD_FILE_FORMAT "Bad format"
# define CANT_OPEN_FILE "Can't open file"
# define WRONG_NUM "Bad num of players"
# define BAD_HEADER "Bad header"
# define READ_ERROR "Read error"
# define INVALID_MALLOC "Malloc error"
# define NO_NULL "No null bytes"
# define INV_CHAP_SIZE "Too big champion"

typedef struct		s_player
{
	char			*header;
	char 			*name;
	char 			*comment;
	int				size;
	char 			*code;
}					t_player;

int					error(char *str);
void				free_player(t_player *player);
void				show(t_player *player);

int					read_files(t_player *player, int ac, char **av);

int					get_header(t_player *player, int fd);
int					get_null(t_player *player, int fd);
int					get_name_or_comment(t_player *player, int fd, int fl);
int					get_size(t_player *player, int fd);
int					get_code(t_player *player, int fd);

#endif
