/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:52:08 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 17:54:13 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "parsing.h"
#include "structures.h"
#include "trace.h"
#include "utils.h"

/*
** parsing 시작 함수
*/

void			parsing_start(int argc, char *argv, t_scene *scene)
{
	int			fd;
	char		*line;
	int			read_n;

	if (argc > 3)
		error_message_errno("too many argument");
	else if (argc == 1)
		error_message_errno("too few argument");
	check_file_name(argv);
	if ((fd = open(argv, O_RDONLY)) < 0)
		error_message_errno("failed opening file");
	while ((read_n = get_next_line(fd, &line)))
	{
		check_object(line, scene);
		free(line);
	}
	if (read_n < 0)
		error_message_errno("failed reading file");
	close(fd);
}

/*
** object 유형 체크
*/

void			check_object(char *line, t_scene *scene)
{
	char		**words;

	words = ft_split(line);
	if (*words)
		printf("make object : %s\n", *words);
	if ((words = ft_split(line)) && !*words)
		return ;
	if (ft_strcmp(*words, "R") == 0)
		create_r(scene, words);
	else if (ft_strcmp(*words, "A") == 0)
		create_a(scene, words);
	else if (ft_strcmp(*words, "c") == 0)
		create_c(scene, words);
	else if (ft_strcmp(*words, "l") == 0)
		create_l(scene, words);
	else
		check_object2(scene, words);
	words_free(words);
}

/*
** 파일 이름 체크
*/

void			check_file_name(char *argv)
{
	int			i;

	i = 0;
	while (argv[i])
		i++;
	if (!(argv[--i] == 't' && argv[--i] == 'r' && argv[--i] == '.'))
		error_message_basic("wrong file name");
}

/*
** 에러메세지 출력(errno 값 없을 경우)
*/

void			error_message_basic(char *msg)
{
	write(1, "error: ", 7);
	printf("%s\n", msg);
	exit(1);
}

/*
** 에러메세지 출력(errno 값 있을 경우)
*/

void			error_message_errno(char *msg)
{
	write(1, "error: ", 7);
	perror(msg);
	exit(1);
}
