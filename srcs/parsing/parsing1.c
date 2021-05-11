#include "structures.h"
#include "utils.h"
#include "trace.h"
#include "get_next_line.h"
#include "parsing.h"

/* parsing 시작 함수 */
void			parsing_start(char *argv, t_scene *scene)
{
	int			fd;
	char		*line;
	int			read_n;

	(void)argv;

	check_file_name(argv);
	if ((fd = open(argv, O_RDONLY)) < 0)
		error_message_errno("failed opening file");
	while (1)
	{
		read_n = get_next_line(fd, &line);
		if (read_n < 0)
			error_message_errno("failed reading file");
		else if (!*line)
			break;
		check_object(line, scene);
		free(line);
	}
	close(fd);
}

/* object 유형 체크 */
void			check_object(char *line, t_scene *scene)
{
	char		**words;

	words = ft_split(line);
	//printf("%s\n", words[0]);
	if (ft_strcmp(*words, "R") == 0)
		create_r(scene, words);
	else if (ft_strcmp(*words, "A") == 0)
		;
	else if (ft_strcmp(*words, "c") == 0)
		create_c(scene, words);
	else if (ft_strcmp(*words, "l") == 0)
		;
	else if (ft_strcmp(*words, "sp") == 0)
		;
	else if (ft_strcmp(*words, "pl") == 0)
		;
	else if (ft_strcmp(*words, "sq") == 0)
		;
	else if (ft_strcmp(*words, "cy") == 0)
		;
	else if (ft_strcmp(*words, "tr") == 0)
		;
	else
		error_message_basic("file error");
}

/* 파일 이름 체크 */
void			check_file_name(char *argv)
{
	int			i;

	i = 0;
	while (argv[i])
		i++;
	if (!(argv[--i] == 't' && argv[--i] == 'r' && argv[--i] == '.'))
		error_message_basic("wrong file name");
}

/* 에러메세지 출력(errno 값 없을 경우) */
void			error_message_basic(char *msg)
{
	write(1, "error: ", 7);
	printf("%s\n", msg);
	exit(0);
}

/* 에러메세지 출력(errno 값 있을 경우) */
void			error_message_errno(char *msg)
{
	write(1, "error: ", 7);
	perror(msg);
	exit(0);
}