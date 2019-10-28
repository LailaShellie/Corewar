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
# include "libft_cor/libft.h"
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

# define AFF_OP 1
# define LLD_READ_SIZE 2
# define DUMP_LEN 64
# define LIVE 1
# define LD 2
# define ST 3
# define ADD 4
# define SUB 5
# define AND 6
# define OR 7
# define XOR 8
# define ZJMP 9
# define LDI 10
# define STI 11
# define FORK 12
# define LLD 13
# define LLDI 14
# define LFORK 15
# define AFF 16

# define MAX_OPS 16

# define DIR 1
# define REG 2
# define IND 3

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
	int				pos;
	int				carry;
	int				op;
	int				last_live_cycle;
	int				action;
	int				*reg;
	struct s_cursor	*next;

}					t_cursor;

typedef struct		s_player
{
	int				num;
	char			*name;
	char			*comment;
	int				size;
	char			*code;
	struct s_player	*next;
}					t_player;

typedef struct		s_main
{
	t_player		*player;
	t_cursor		*cursor;
	int				cursor_ids;
	int				dump;
	int				n_flag;
	char			*field;
	int				num_of_players;
	int				last_player_live;
	int				live_num;
	int				check_num;
	int				cycle;
	int				total_cycle;
	int				cycles_to_die;
	int				v_flag;
}					t_main;

typedef struct		s_o
{
	int				*t;
	int				step;
	int				*s;
	int				*x;
}					t_o;

int					set_player_fl(t_main *m, t_player *new);
int					set_player(t_main *m, t_player *new);
void				swap_players(t_player *a, t_player *b);
int					ft_error(char *str);
void				free_main(t_main *main);
int					is_number(char *str);
void				free_cursor(t_main *main);
int					read_files(t_main *m, int ac, char **av);
int					manage_n(t_main *m, int ac, char **av);
int					get_header(int fd);
int					get_null(int fd);
int					get_name_or_comment(t_player *player, int fd, int fl);
int					get_size(t_player *player, int fd);
int					get_code(t_player *player, int fd);
int					start_game(t_main *main);
void				set_cursor(t_cursor **first, t_cursor *cursor);
t_cursor			*new_cursor();
int					dump_memory(char *field);
void				*free_o(t_o *o);
int					check(t_main *main);
int					start_fight(t_main *main);
void				do_op(t_main *m, t_cursor *c);
int					c_p(int pos);
int					s(int t, int op);
t_o					*manage_type(t_main *m, t_cursor *c);
void				get_args(t_main *m, t_cursor *c, t_o *o);
void				do_live(t_main *m, t_cursor *c);
void				do_zjmp(t_main *m, t_cursor *c);
void				do_fork(t_main *m, t_cursor *c);
void				set_mem(char *f, int reg, int pos);
int					read_mem(char *f, int pos, int size);
void				modify_carry(t_cursor *c, int reg);
void				get_reg(t_cursor *c, t_o *o);
t_player			*choose_player(t_main *m);
void				do_ld(t_main *m, t_cursor *c, t_o *o);
void				do_add_sub(t_main *m, t_cursor *c, t_o *o);
void				do_sti(t_main *m, t_cursor *c, t_o *o);
void				do_st(t_main *m, t_cursor *c, t_o *o);
void				do_ldi(t_main *m, t_cursor *c, t_o *o);
void				do_aff(t_main *m, t_cursor *c, t_o *o);
void				do_and_or_xor(t_main *m, t_cursor *c, t_o *o);
int					choose_type(char tmp);
int					is_player_num(int i, t_player *p);

#endif
