/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:51:32 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/14 11:29:33 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"
#include "get_next_line.h"
#include "parsing.h"

int			count_word2(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (i > 0 && *s == c)
		{
			i = 0;
			count++;
		}
		else if (*s != c)
			i++;
		s++;
	}
	if (i > 0)
		count++;
	return (count);
}

char		**free_all2(char **words, int j)
{
	while (--j > 0)
		free(words[j]);
	free(words);
	return (0);
}

void		put_char2(char *s, char *c, int i)
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

char		**put_words2(char **words, char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (i > 0 && *s == c)
		{
			if (!(words[j] = (char *)malloc(sizeof(char) * (i + 1))))
				return (free_all2(words, j));
			put_char2(words[j++], (char *)s - i, i);
			i = 0;
		}
		else if (*s != c)
			i++;
		s++;
	}
	if (i > 0)
	{
		if (!(words[j] = (char *)malloc(sizeof(char) * (i + 1))))
			return (free_all2(words, j));
		put_char2(words[j], (char *)s - i, i);
	}
	return (words);
}

char		**ft_split2(char const *s, char c)
{
	int		words_c;
	char	**words;

	if (!s)
		error_message_basic("file has wrong num");
	words_c = count_word2(s, c);
	if (!(words = (char **)malloc(sizeof(char *) * (words_c + 1))))
		return (0);
	if (!put_words2(words, s, c))
		return (0);
	words[words_c] = 0;
	return (words);
}
