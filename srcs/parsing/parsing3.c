/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 04:15:35 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 17:56:35 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "parsing.h"
#include "scene.h"
#include "structures.h"
#include "trace.h"
#include "utils.h"

/*
** Plane
*/

void			create_pl(t_scene *scene, char **words)
{
	char		**temp;
	t_vec3		point;
	t_vec3		normal;
	t_color3	color;

	temp = ft_split2(words[1], ',');
	point = point3(make_double(temp[0], -DBL_MAX, DBL_MAX),
					make_double(temp[1], -DBL_MAX, DBL_MAX),
					make_double(temp[2], -DBL_MAX, DBL_MAX));
	check_temp_and_free(temp, 3, "pl");
	temp = ft_split2(words[2], ',');
	normal = vec3(make_double(temp[0], -1, 1),
					make_double(temp[1], -1, 1),
					make_double(temp[2], -1, 1));
	check_temp_and_free(temp, 3, "pl");
	temp = ft_split2(words[3], ',');
	color = vec3(make_double(temp[0], 0, 255) / 256.0,
					make_double(temp[1], 0, 255) / 256.0,
					make_double(temp[2], 0, 255) / 256.0);
	check_temp_and_free(temp, 3, "pl");
	scene->world = oadd(&scene->world,
		object(PLANE, plane(point, vunit(normal)), color));
	if (words[4])
		error_message_basic("pl is wrong");
}

/*
** Square
*/

void			create_sq(t_scene *scene, char **words)
{
	char		**temp;
	t_vec3		point;
	t_vec3		normal;
	t_color3	color;

	temp = ft_split2(words[1], ',');
	point = point3(make_double(temp[0], -DBL_MAX, DBL_MAX),
					make_double(temp[1], -DBL_MAX, DBL_MAX),
					make_double(temp[2], -DBL_MAX, DBL_MAX));
	check_temp_and_free(temp, 3, "sq");
	temp = ft_split2(words[2], ',');
	normal = vec3(make_double(temp[0], -1, 1),
					make_double(temp[1], -1, 1),
					make_double(temp[2], -1, 1));
	check_temp_and_free(temp, 3, "sq");
	temp = ft_split2(words[4], ',');
	color = vec3(make_double(temp[0], 0, 255) / 256.0,
					make_double(temp[1], 0, 255) / 256.0,
					make_double(temp[2], 0, 255) / 256.0);
	check_temp_and_free(temp, 3, "sq");
	scene->world = oadd(&scene->world, object(SQUARE, square(point,
					vunit(normal), make_double(words[3], 0, DBL_MAX)), color));
	if (words[5])
		error_message_basic("sq is wrong");
}

/*
** Cylinder
*/

void			create_cy(t_scene *scene, char **words)
{
	char		**temp;
	t_vec3		point;
	t_vec3		normal;
	t_color3	color;

	temp = ft_split2(words[1], ',');
	point = point3(make_double(temp[0], -DBL_MAX, DBL_MAX),
					make_double(temp[1], -DBL_MAX, DBL_MAX),
					make_double(temp[2], -DBL_MAX, DBL_MAX));
	check_temp_and_free(temp, 3, "cy");
	temp = ft_split2(words[2], ',');
	normal = vec3(make_double(temp[0], -1, 1),
					make_double(temp[1], -1, 1),
					make_double(temp[2], -1, 1));
	check_temp_and_free(temp, 3, "cy");
	temp = ft_split2(words[5], ',');
	color = vec3(make_double(temp[0], 0, 255) / 256.0,
					make_double(temp[1], 0, 255) / 256.0,
					make_double(temp[2], 0, 255) / 256.0);
	check_temp_and_free(temp, 3, "cy");
	scene->world = oadd(&scene->world, object(CY, cylinder(point,
						vunit(normal), make_double(words[3], 0, DBL_MAX),
						make_double(words[4], 0, DBL_MAX)), color));
	if (words[6])
		error_message_basic("cy is wrong");
}

/*
** Triangle
*/

void			create_tr(t_scene *scene, char **words)
{
	char		**temp;
	t_vec3		p1;
	t_vec3		p2;
	t_vec3		p3;
	t_color3	color;

	temp = ft_split2(words[1], ',');
	p1 = point3(make_double(temp[0], -DBL_MAX, DBL_MAX),
				make_double(temp[1], -DBL_MAX, DBL_MAX),
				make_double(temp[2], -DBL_MAX, DBL_MAX));
	check_temp_and_free(temp, 3, "tr");
	temp = ft_split2(words[2], ',');
	p2 = point3(make_double(temp[0], -DBL_MAX, DBL_MAX),
				make_double(temp[1], -DBL_MAX, DBL_MAX),
				make_double(temp[2], -DBL_MAX, DBL_MAX));
	check_temp_and_free(temp, 3, "tr");
	create_tr_sub(words, &p3, &color);
	check_tri(p1, p2, p3);
	scene->world = oadd(&scene->world, object(TRIANGLE,
					triangle(p1, p2, p3), color));
	if (words[5])
		error_message_basic("tr is wrong");
}

void			create_tr_sub(char **words, t_vec3 *p3, t_color3 *color)
{
	char		**temp;

	temp = ft_split2(words[3], ',');
	*p3 = point3(make_double(temp[0], -DBL_MAX, DBL_MAX),
					make_double(temp[1], -DBL_MAX, DBL_MAX),
					make_double(temp[2], -DBL_MAX, DBL_MAX));
	check_temp_and_free(temp, 3, "tr");
	temp = ft_split2(words[4], ',');
	*color = vec3(make_double(temp[0], 0, 255) / 256.0,
					make_double(temp[1], 0, 255) / 256.0,
					make_double(temp[2], 0, 255) / 256.0);
	check_temp_and_free(temp, 3, "tr");
}
