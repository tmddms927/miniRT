/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:51:37 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/14 11:33:16 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"
#include "get_next_line.h"
#include "parsing.h"

/*
** 문자열 비교 함수
*/

int				ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
** char *형 double로 변환
*/

double			make_double1(char *s, int minus, double a)
{
	double		b;
	int			i;

	b = 0;
	i = 0;
	while (*s && *s != '.')
	{
		if (*s < '0' || *s > '9')
			error_message_basic("file has wrong num");
		a = a * 10 + *s - '0';
		s++;
	}
	if (*s == '.')
		s++;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			error_message_basic("file has wrong num");
		b = b * 10 + *s - '0';
		s++;
		i++;
	}
	return ((a = a + b * pow(10, -i)) * minus);
}

double			make_double(char *s, double min, double max)
{
	double		num;
	int			minus;
	double		a;

	if (!s)
		error_message_basic("file has wrong num");
	a = 0;
	minus = 1;
	if (*s == '-' && s++)
		minus = -1;
	num = make_double1(s, minus, a);
	if (num > max || num < min)
		error_message_basic("file has wrong num");
	return (num);
}

/*
** 문자열 체크 후 free
*/

void			check_temp_and_free(char **temp, int i, char *s)
{
	int			j;

	j = 0;
	if (temp[i])
	{
		printf("%s", s);
		error_message_basic(" is wrong");
	}
	while (temp[j])
	{
		free(temp[j]);
		j++;
	}
	free(temp);
}

/*
** 문자열 free
*/

void			words_free(char **words)
{
	int			j;

	j = 0;
	while (words[j])
	{
		free(words[j]);
		j++;
	}
	free(words);
}
