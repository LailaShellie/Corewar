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

typedef struct		s_cursor
{
	int				id;
	int 			pos;
	int				carry;
	int				op;
	int				last_live_cycle;
	int				cycles_to_op;
	int				bytes_to_next;
	int				*reg;
	struct s_cursor	*next;

}					t_cursor;

typedef struct		s_player
{
	int 			num;
	char 			*name;
	char 			*comment;
	int				size;
	char 			*code;
}					t_player;

typedef struct		s_main
{
	t_player		*player;
	t_cursor		*cursor;
	int 			cursor_ids;
	char 			*field;
	int 			num_of_players;
	int				last_player_live;
	int				live_num;
	int				check_num;
	int				cycle;
	int				cycles_to_die;
}					t_main;

int					error(char *str);
void				free_main(t_main *main);
void				show(t_player *player);

int					read_files(t_player *player, int ac, char **av);

int					get_header(int fd);
int					get_null(int fd);
int					get_name_or_comment(t_player *player, int fd, int fl);
int					get_size(t_player *player, int fd);
int					get_code(t_player *player, int fd);

int					start_game(t_main *main);

void				set_cursor(t_cursor **first, t_cursor *cursor);
t_cursor			*new_cursor();
void				show_cursors(t_cursor *cursor);

#endif
