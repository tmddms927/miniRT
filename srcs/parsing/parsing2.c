/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:52:12 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/12 03:47:03 by seungoh          ###   ########.fr       */
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
    //printf("%d, %d\n", scene->canvas.height, scene->canvas.width);
    if (words[3])
        error_message_basic("R is wrong");
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
    if (temp[3])
        error_message_basic("c is wrong");
    free(temp);
    temp = ft_split2(words[2], ',');
	cam = cam_olast(scene->camera);
	cam->normal = vec3(make_double(temp[0], -1, 1), make_double(temp[1], -1, 1), make_double(temp[2], -1, 1));
    if (temp[3])
        error_message_basic("c is wrong");
	free(temp);
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
	if (temp[3])
        error_message_basic("l is wrong");
	free(temp);
	temp = ft_split2(words[3], ',');
	color = vec3(make_double(temp[0], 0, 255) / 256.0, make_double(temp[1], 0, 255) / 256.0, make_double(temp[2], 0, 255) / 256.0);
	if (temp[3])
        error_message_basic("l is wrong");
	free(temp);
    scene->light = oadd(&scene->light, object(LIGHT_POINT, light_point(point, color, make_double(words[2], 0, 1)), color3(0, 0, 0)));
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
	if (temp[3])
        error_message_basic("sp is wrong");
	free(temp);
	temp = ft_split2(words[3], ',');
	color = vec3(make_double(temp[0], 0, 255) / 256.0, make_double(temp[1], 0, 255) / 256.0, make_double(temp[2], 0, 255) / 256.0);
	if (temp[3])
        error_message_basic("sp is wrong");
	free(temp);
    scene->world = oadd(&scene->world, object(SP, sphere(point, make_double(words[2], 0, DBL_MAX)), color));
}