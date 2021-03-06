/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:50:59 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 17:15:46 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "scene.h"

/*
** 리스트에 추가할 object 생성자
*/

t_object			*object(t_object_type type, void *element, t_color3 albedo)
{
	t_object		*new;

	if (!(new = (t_object *)malloc(sizeof(t_object))))
		error_message_errno("failed malloc");
	new->type = type;
	new->element = element;
	new->next = NULL;
	new->albedo = albedo;
	return (new);
}

/*
** 구 생성자
*/

t_sphere			*sphere(t_point3 center, double radius)
{
	t_sphere		*sp;

	if (!(sp = (t_sphere *)malloc(sizeof(t_sphere) * 1)))
		error_message_errno("failed malloc");
	sp->center = center;
	sp->radius = radius;
	sp->radius2 = radius * radius;
	return (sp);
}

/*
** 평면 생성자
*/

t_plane				*plane(t_point3 point, t_vec3 normal)
{
	t_plane			*pn;

	if (!(pn = (t_plane *)malloc(sizeof(t_plane) * 1)))
		error_message_errno("failed malloc");
	pn->point = point;
	pn->normal = normal;
	return (pn);
}

/*
** 사각형 생성자
*/

t_square			*square(t_point3 center, t_vec3 normal, double side_size)
{
	t_square		*sq;

	if (!(sq = (t_square *)malloc(sizeof(t_square) * 1)))
		error_message_errno("failed malloc");
	sq->center = center;
	sq->normal = normal;
	sq->side_size = side_size;
	sq->min = vec3(
		sq->center.x - side_size / 2, sq->center.y - side_size / 2,
			sq->center.z);
	sq->max = vec3(
		sq->center.x + side_size / 2, sq->center.y + side_size / 2,
			sq->center.z);
	return (sq);
}

/*
** 삼각형 생성자
*/

t_triangle			*triangle(t_point3 a, t_point3 b, t_point3 c)
{
	t_triangle		*triangle;

	if (!(triangle = (t_triangle *)malloc(sizeof(t_triangle) * 1)))
		error_message_errno("failed malloc");
	triangle->point[0] = a;
	triangle->point[1] = b;
	triangle->point[2] = c;
	triangle->normal = vunit(vcross(vminus(b, a), vminus(c, a)));
	return (triangle);
}
