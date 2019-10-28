/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 01:30:39 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/14 19:17:43 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"
# define TYPELIST "%fdiouxXcsp"
# define SIZE_TYPE "lhL"
# define ALL "%fdiouxXcsplLh#0-+ 123456789."

typedef struct				s_printf
{
	int						sh;
	int						sp;
	int						z;
	int						min;
	int						pl;
	int						f_width;
	int						z_width;
	int						prec;
	char					*tp;
	char					*s_tp;
	int						fl_zsh;
	int						isnan;
	int						isinf;
}							t_printf;

typedef struct				s_float
{
	unsigned long long int	whole;
	char					*drb;
	int						neg_fl;
	int						count;
}							t_float;

int							ft_printf(const char *format_str, ...);
size_t						final_process(const char *format_str, va_list ap,
char **res);
char						*ft_power_rangers(char *str, const char *src,
size_t len1, size_t len2);
size_t						format_final(const char **format_str, char **res,
va_list ap);

int							ft_check_type(const char *form, char **typestr);
char						*check_undefined_type(char *s);
int							check_typelist(char c, char *s);
int							ft_if_notmod(int tag, char **typestr,
const char *form);

t_printf					*ft_parsing(char *mods, t_printf *data,
va_list ap);
void						ft_initial_struct(t_printf *data);
void						ft_parsing_flags(t_printf *data, char mod);
int							ft_precision_struct(t_printf *data, char *mods);
int							ft_width_struct(char *mods, t_printf *data,
va_list ap);

char						*result_without_flags(t_printf *data, va_list ap);
char						*ft_type_d_i(va_list ap, char *modi);
char						*ft_type_o(va_list ap, char *modi);
char						*ft_type_u(va_list ap, char *modi);
char						*ft_type_x(va_list ap, char *modi);
char						*ft_type_upper_x(va_list ap, char *modi);
char						*ft_type_c(va_list ap, char *modi);
char						*ft_type_s(va_list ap);
char						*ft_type_p(va_list ap);
long double					ft_type_f(va_list ap, char *modi);

char						*ft_float_process(double begin_n, t_printf *form);
char						*ft_sborka(char *drob_part,
unsigned long long int whole, int flag, double begin_n);
char						*ft_output_zero_prec(char *drob_part,
unsigned long long int whole, int flag, double begin_n);
char						*ft_rounding(char *str, int len, int flag,
double begin_n);
char						*round_and_output(char *rounding_num,
unsigned long long int whole, int flag);

char						*ft_strnmalloc(char *s, unsigned int start,
size_t len);
char						*ft_symcat(char c, char *str);
char						*ft_strjoin_plus(char *str1, char *str2);
char						*ft_inf_nan(t_printf *data, double len);

char						*add_flags(t_printf *data, char *src);
char						*ft_precision(t_printf *data, char *str);
void						ft_sub_precision(char *res, char *src, int len,
int precision);
char						*ft_zero_size(t_printf *data, char *s1);
void						ft_sub_zero_size(t_printf *data, char *res,
char *src, int len);
char						*ft_sharp(t_printf *data, char *str);
char						*ft_plus(int plus, char *s1);
char						*ft_space(char *str);
char						*ft_width(t_printf *data, char *s1);

char						*check_zero(t_printf *d, char *src);
void						ft_cat_and_free(char **res, char *temp,
size_t summ_len, size_t len);
char						*ft_pres_norm(t_printf *data, char *str, int prec);
char						*ft_res_prec(double n, t_float f_d);

#endif
