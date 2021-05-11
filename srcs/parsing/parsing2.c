#include "structures.h"
#include "utils.h"
#include "trace.h"
#include "get_next_line.h"
#include "parsing.h"
#include "scene.h"

/*
** Resolution
*/
void    create_r(t_scene *scene, char **words)
{
    scene->canvas = canvas(make_double(words[1]), make_double(words[2]));
    //printf("%d, %d\n", scene->canvas.height, scene->canvas.width);
    if (words[3])
        error_message_basic("R has many arguments");
}

/*
** Camera
*/
void		create_c(t_scene *scene, char **words)
{
    char	**temp;

    temp = ft_split2(words[1], ',');
    scene->camera = cam_oadd(&scene->camera, camera(&scene->canvas, point3(make_double(temp[0]), make_double(temp[1]), make_double(temp[2]))));
    printf("%f, %f, %f\n", scene->camera->orig.x, scene->camera->orig.y, scene->camera->orig.z);
    if (words[3])
        error_message_basic("R has many arguments");
}