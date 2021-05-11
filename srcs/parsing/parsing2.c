/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:52:12 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/12 05:19:48 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    scene->canvas = canvas(make_double(words[1], -DBL_MAX, DBL_MAX), make_double(words[2], -DBL_MAX, DBL_MAX));
    if (words[3])
        error_message_basic("R is wrong");
}

/*
** Ambient lightning
*/
void    create_a(t_scene *scene, char **words)
{
    char		**temp;
    t_color3	color;

    temp = ft_split2(words[2], ',');
	color = vec3(make_double(temp[0], 0, 255) / 256.0, make_double(temp[1], 0, 255) / 256.0, make_double(temp[2], 0, 255) / 256.0);
    check_temp_and_free(temp ,3, "a");
    scene->ambient = vmult(color, make_double(words[1], 0, 2));
    if (words[3])
        error_message_basic("a is wrong");
}


/*
** Camera
*/
void			create_c(t_scene *scene, char **words)
{
    char		**temp;
    t_camera	*cam;

    temp = ft_split2(words[1], ',');
    scene->camera = cam_oadd(&scene->camera, camera(&scene->canvas, point3(make_double(temp[0], -DBL_MAX, DBL_MAX), make_double(temp[1], -DBL_MAX, DBL_MAX), make_double(temp[2], -DBL_MAX, DBL_MAX))));
    check_temp_and_free(temp ,3, "c");
    temp = ft_split2(words[2], ',');
	cam = cam_olast(scene->camera);
	cam->normal = vec3(make_double(temp[0], -1, 1), make_double(temp[1], -1, 1), make_double(temp[2], -1, 1));
    check_temp_and_free(temp ,3, "c");
    cam->fov = make_double(words[3], 0, 180);
	if (words[4])
        error_message_basic("c is wrong");
}

/*
** Light
*/
void			create_l(t_scene *scene, char **words)
{
    char		**temp;
	t_vec3		point;
	t_color3	color;

	temp = ft_split2(words[1], ',');
	point = point3(make_double(temp[0], -DBL_MAX, DBL_MAX), make_double(temp[1], -DBL_MAX, DBL_MAX), make_double(temp[2], -DBL_MAX, DBL_MAX));
	check_temp_and_free(temp ,3, "l");
	temp = ft_split2(words[3], ',');
	color = vec3(make_double(temp[0], 0, 255) / 256.0, make_double(temp[1], 0, 255) / 256.0, make_double(temp[2], 0, 255) / 256.0);
	check_temp_and_free(temp ,3, "l");
    scene->light = oadd(&scene->light, object(LIGHT_POINT, light_point(point, color, make_double(words[2], 0, 1)), color3(0, 0, 0)));
    if (words[4])
        error_message_basic("l is wrong");
}

/*
** Sphere
*/
void			create_sp(t_scene *scene, char **words)
{
    char		**temp;
	t_vec3		point;
	t_color3	color;

	temp = ft_split2(words[1], ',');
	point = point3(make_double(temp[0], -DBL_MAX, DBL_MAX), make_double(temp[1], -DBL_MAX, DBL_MAX), make_double(temp[2], -DBL_MAX, DBL_MAX));
	check_temp_and_free(temp ,3, "sp");
	temp = ft_split2(words[3], ',');
	color = vec3(make_double(temp[0], 0, 255) / 256.0, make_double(temp[1], 0, 255) / 256.0, make_double(temp[2], 0, 255) / 256.0);
	check_temp_and_free(temp ,3, "sp");
    scene->world = oadd(&scene->world, object(SP, sphere(point, make_double(words[2], 0, DBL_MAX)), color));
    if (words[4])
        error_message_basic("sp is wrong");
}