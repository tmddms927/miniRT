#include "structures.h"
#include "utils.h"
#include "trace.h"
#include "get_next_line.h"
#include "parsing.h"
#include "scene.h"

void    create_r(t_scene *scene, char **words)
{
    scene->canvas = canvas(make_double(words[1]), make_double(words[2]));
    if (words[3])
        error_message_basic("R has many arguments");
}