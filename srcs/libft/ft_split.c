/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 10:28:01 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/12 01:26:14 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"
#include "get_next_line.h"
#include "parsing.h"

int			count_word(char const *s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (i > 0 && ((*s > 8 && *s < 14) || *s == 32))
		{
			i = 0;
			count++;
		}
		else if (!((*s > 8 && *s < 14) || *s == 32))
			i++;
		s++;
	}
	if (i > 0)
		count++;
	return (count);
}

char		**free_all(char **words, int j)
{
	while (--j > 0)
		free(words[j]);
	free(words);
	return (0);
}

void		put_char(char *s, char *c, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		s[j] = c[j];
		j++;
	}
	s[j] = 0;
}

char		**put_words(char **words, char const *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (i > 0 && ((*s > 8 && *s < 14) || *s == 32))
		{
			if (!(words[j] = (char *)malloc(sizeof(char) * (i + 1))))
				return (free_all(words, j));
			put_char(words[j++], (char *)s - i, i);
			i = 0;
		}
		else if (!((*s > 8 && *s < 14) || *s == 32))
			i++;
		s++;
	}
	if (i > 0)
	{
		if (!(words[j] = (char *)malloc(sizeof(char) * (i + 1))))
			return (free_all(words, j));
		put_char(words[j], (char *)s - i, i);
	}
	return (words);
}

char		**ft_split(char const *s)
{
	int		words_c;
	char	**words;

	if (!s)
		return (0);
	words_c = count_word(s);
	if (!(words = (char **)malloc(sizeof(char *) * (words_c + 1))))
		return (0);
	if (!put_words(words, s))
		return (0);
	words[words_c] = 0;
	return (words);
}