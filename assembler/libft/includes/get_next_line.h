/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:59:16 by blanna            #+#    #+#             */
/*   Updated: 2019/01/27 17:49:40 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define TMPLC tmplist->content
# define LSTLC (*list)->content
# define MAX_FD 4864

# include "libft.h"

# if (BUFF_SIZE <= 0)
#  error BUFF_SIZE must be > 0
# endif

int		get_next_line(const int fd, char **line);
int		read_line(const int fd, char **row);

#endif
