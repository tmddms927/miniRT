#ifndef PARSING_H
# define PARSING_H

#include "structures.h"
#include "utils.h"

void      parsing_start(char *argv, t_scene *scene);
void      check_object(char *line, t_scene *scene);


void        check_file_name(char *argv);
void        error_message_basic(char *msg);
void        error_message_errno(char *msg);


void        create_r(t_scene *scene, char **words);


int			ft_strcmp(const char *s1, const char *s2);
char		**ft_split(char const *s);
double		make_double(char *s);
#endif