/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:54:13 by seungoh           #+#    #+#             */
/*   Updated: 2021/04/10 18:46:12 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	int		i;

	i = -1;
	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (single_str(s2));
	else if (!s2)
		return (single_str2(s1));
	if (!(temp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (s1[++i])
		temp[i] = s1[i];
	while (*s2)
		temp[i++] = *s2++;
	temp[i] = 0;
	free(s1);
	return (temp);
}

char		*single_str(char *s)
{
	char	*temp;
	int		i;

	i = 0;
	if (!(temp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	while (*s)
		temp[i++] = *s++;
	temp[i] = 0;
	return (temp);
}

char		*single_str2(char *s)
{
	char	*temp;
	int		i;

	i = 0;
	if (!(temp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (0);
	while (*s)
		temp[i++] = *s++;
	temp[i] = 0;
	free(s);
	return (temp);
}
