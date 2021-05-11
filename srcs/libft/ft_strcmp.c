/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:26:23 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/12 00:26:43 by seungoh          ###   ########.fr       */
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
double			make_double(char *s)
{
	double		a;
	double		b;
	int			i;

	a = 0;
	i = 0;
	b = 0;
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
	return (a + b * pow(10, -i));
}
