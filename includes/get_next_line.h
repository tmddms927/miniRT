/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:54:42 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/14 11:16:11 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10

# include "minirt.h"

int		get_next_line(int fd, char **line);
int		check_line(char *backup);
int		split_line(char **backup, char **line, int end_index);
int		check_return(char **backup, char **line, int read_size);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*single_str(char *s);
char	*single_str2(char *s);
#endif
