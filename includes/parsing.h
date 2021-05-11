#ifndef PARSING_H
# define PARSING_H

#include "structures.h"
#include "utils.h"
#include <float.h>

void		parsing_start(char *argv, t_scene *scene);
void		check_object(char *line, t_scene *scene);

void		check_file_name(char *argv);
void		error_message_basic(char *msg);
void		error_message_errno(char *msg);


void		create_r(t_scene *scene, char **words);
void		create_a(t_scene *scene, char **words);
void		create_c(t_scene *scene, char **words);
void		create_l(t_scene *scene, char **words);
void		create_sp(t_scene *scene, char **words);
void		create_pl(t_scene *scene, char **words);
void		create_sq(t_scene *scene, char **words);
void		create_cy(t_scene *scene, char **words);
void		create_tr(t_scene *scene, char **words);

int			ft_strcmp(const char *s1, const char *s2);
char		**ft_split(char const *s);
char		**ft_split2(char const *s, char c);
double		make_double(char *s, double min, double max);
void		check_temp_and_free(char **temp, int i, char *s);
#endif