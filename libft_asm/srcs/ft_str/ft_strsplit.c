/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:46:05 by blanna            #+#    #+#             */
/*   Updated: 2018/12/15 17:38:30 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordlen(const char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && i == 0)
		{
			i = 1;
			count++;
		}
		if (*str == c && i == 1)
			i = 0;
		str++;
	}
	return (count);
}

static char	*wordcount(char const *str, char c)
{
	size_t	count;
	char	*part2;

	count = 0;
	if (!str)
		return (NULL);
	while (str[count] != c && str[count] != '\0')
		count++;
	if (!(part2 = (char *)malloc(sizeof(char) * (count + 1))))
		return (0);
	count = 0;
	while (*str && *str != c)
	{
		part2[count++] = *str;
		str++;
	}
	part2[count] = '\0';
	return (part2);
}

static void	ft_free(char **array, int len)
{
	while (--len > -1)
		free(array[len]);
	free(array);
}

char		**ft_strsplit(char const *str, char c)
{
	char	**part2;
	size_t	i;

	if (!str || !(part2 = (char **)malloc(sizeof(char *)\
					* (wordlen(str, c) + 1))))
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str != c && *str)
		{
			if (!(part2[i++] = wordcount(str, c)))
			{
				ft_free(part2, --i);
				free(part2);
				return (NULL);
			}
			while (*str != c && *str)
				str++;
		}
	}
	part2[i] = NULL;
	return (part2);
}
