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

# define MAX_OPS 16

# define M_REG 2
# define M_DIR 1
# define M_IND 3

# define NUM_ARG 0
# define TYPE_BYTE 1
# define ARG1 2
# define ARG2 3
# define ARG3 4
# define T_DIR_SIZE 5
# define PRICE 6

typedef struct		s_cursor
{
	int				id;
	int 			pos;
	int				carry;
	int				op;
	int				last_live_cycle;
	int				action;
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
	int 			total_cycle;
	int				cycles_to_die;
}					t_main;

int					ft_error(char *str);
void				free_main(t_main *main);
void				show(t_player *player);
void				free_cursor(t_main *main);

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

int 				dump_memory_64(char *field);

int 				check(t_main *main);
void				start_fight(t_main *main);

void				do_op(t_main *m, t_cursor *c);
int 				c_p(int pos);
int 				choose_pos(int tmp, int dir_size);
void				move_next(t_cursor *c, unsigned char type, int *global);

void				do_live(t_main *main, t_cursor *c);
void				do_ld(t_main *main, t_cursor *c);
void				do_st(t_main *m, t_cursor *c);
void				do_add(t_main *m, t_cursor *c);
void				do_sub(t_main *m, t_cursor *c);
void				do_zjmp(t_main *m, t_cursor *c);
void				do_lfork(t_main *m, t_cursor *c);
void				do_fork(t_main *m, t_cursor *c);
void				do_aff(t_main *m, t_cursor *c);

#endif
