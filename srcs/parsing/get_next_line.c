/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:52:03 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 17:47:01 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line(int fd, char **line)
{
	static char	*backup[OPEN_MAX];
	int			read_size;
	int			end_index;
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = 0;
		backup[fd] = ft_strjoin(backup[fd], buf);
		if ((end_index = check_line(backup[fd])) > -1)
			return (split_line(&backup[fd], line, end_index));
	}
	return (check_return(&backup[fd], line, read_size));
}

int				check_line(char *backup)
{
	int			i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int				split_line(char **backup, char **line, int end_index)
{
	int			i;

	i = -1;
	if (!(*line = (char *)malloc(sizeof(char) * (end_index + 1))))
		return (-1);
	while (++i < end_index)
		(*line)[i] = (*backup)[i];
	(*line)[i] = 0;
	i = 0;
	end_index++;
	while ((*backup)[end_index])
		(*backup)[i++] = (*backup)[end_index++];
	(*backup)[i] = 0;
	return (1);
}

int				check_return(char **backup, char **line, int read_size)
{
	int			end_index;

	if (read_size < 0)
		return (-1);
	else if (*backup && (end_index = check_line(*backup)) > -1)
		return (split_line(backup, line, end_index));
	else if (*backup)
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	if (!(*line = (char *)malloc(sizeof(char) * 1)))
		return (-1);
	**line = 0;
	return (0);
}
