/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:15:58 by blanna            #+#    #+#             */
/*   Updated: 2019/10/28 12:16:02 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../libft/includes/libft.h"
# include "../../libft/includes/get_next_line.h"
# include "../../libft/includes/ft_printf.h"
# include "asm_ops.h"
# include "op.h"

# define ST	d_asm->i
# define J	d_asm->j

# define SPACER1(c) (c == '\0' || (c == '\n') || c == '\"' || c == ' ')
# define SPACER2(c) (c == '\t' || c == '%' || c == ',' || c == '#' || c == ';')

# define INIT {args = g_op_tab[op_n].args_n; types = g_op_tab[op_n].args_typ;}

# define BEGIN_NAME 4
# define BEGIN_EXEC_SIZE (4 + PROG_NAME_LENGTH + 4)
# define BEGIN_COMMENT (4 + PROG_NAME_LENGTH + 4 + 4)
# define BEGIN_EXEC (BEGIN_COMMENT + COMMENT_LENGTH + 4)
# define LIMIT_BYTE (BEGIN_EXEC + CHAMP_MAX_SIZE)

# define READ "ERROR: File unreadable"
# define MEM "ERROR: Failed to allocate memory"
# define TEXT "ERROR: Can not read token"
# define LBL_NAME "ERROR: The label name is repeated"
# define CHAMP_NAME "ERROR: The champion's name is too big"
# define NONAME "ERROR: The name of the champion is not detected"
# define COM "ERROR: The champion's comment is too big"
# define NOCOM "ERROR: The comment of the champion is not detected"
# define CMD_NAME_COMM "ERROR: No .name or/and .comment."
# define CMD_NAME_COMM2 "ERROR: Invalid name or comment format"
# define WRONG_SYM "ERROR: Unknown operator"
# define OPER "ERROR: The operator is not detected"
# define OPER_NUMARG "ERROR: Invalid number of operation arguments"
# define OPER_TYPEARG "ERROR: Invalid type of operation arguments"
# define PLUS "ERROR: The use of the + sign is not allowed"
# define NO_LBL "ERROR: The label is not detected"
# define BIGEX "ERROR: Executable code has size bigger than a limit"
# define NOCREATE "ERROR: Can not to create bytecode file"
# define NOWRITE "ERROR: Can not to write bytecode file"
# define OPER_NOEND "ERROR: EOF not detected"
# define STR_STOP "ERROR: End of line not found"

typedef struct			s_tkn
{
	int					y;
	int					x;
	t_type				type;
	uint32_t			bytes;
	struct s_tkn		*next;
	struct s_tkn		*prev;
	char				*cont;
}						t_tkn;

typedef struct			s_lbl
{
	t_tkn				*locat;
	struct s_lbl		*next;
	struct s_lbl		*prev;
}						t_lbl;

typedef struct			s_ass
{
	int					i;
	int					j;
	int					fd;
	char				*f_name;
	int					magic;
	char				*bytecod;
	uint32_t			code_bytes;
	t_lbl				*lbl;
	t_tkn				*tkn;
}						t_ass;

/*
** main
*/
int						main(int ac, char **av);
void					my_asm(char *f_name);

/*
** lexic
*/
void					lexical_check(t_ass	*d_asm);
void					get_direct(t_ass *d_asm, char	*line);
void					add_number(t_ass *d_asm, char *line, t_type type);
void					add_text(t_ass *d_asm, char *line, t_type type);

void					champ_data_check(t_ass *d_asm, t_tkn **temp);

/*
** syntax
*/
void					syntax_check(t_ass *d_asm, t_tkn *tkn);

/*
** bytecode
*/
void					into_bytecode(t_ass *d_asm);
t_tkn					*champ_data_record(t_ass *d_asm, t_tkn *temp);
void					c_h(t_ass *d_asm, int32_t dec, int d_sz, uint32_t *beg);
void					types_arg_record(t_ass *d_asm, t_tkn *op,
				uint32_t *ptr, uint8_t n_arg);
int32_t					c(t_ass *d_asm, uint32_t bytes, t_tkn *lbl);
void					oper_record(t_ass *d_asm, t_tkn **op,
				uint32_t *ptr, uint8_t type);

void					code_to_file(t_ass *d_asm);

/*
** support
*/
void					free_all(t_ass *d_asm);

void					add_label(t_ass *d_asm);
void					add_token(t_ass *d_asm, t_type type);

void					error(t_ass *d_asm, char *str, t_tkn *tkn, int fl);
void					skip_spaces(t_ass	*d_asm, char *line);
void					skip_comm(t_ass	*d_asm, char *line);
int32_t					ft_atoi_size(const char *str, uint8_t size);
int						check_reg(char *line, int len);

#endif
