/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:50:49 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/13 22:25:26 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"
#include "parsing.h"

/* 삼각형 판별 함수 */
double			hit_triangle(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_triangle	*triangle;

    triangle = (t_triangle *)world->element;
	rec->t = -vdot(vminus(ray->orig, triangle->point[0]), triangle->normal) / vdot(triangle->normal, ray->dir);
    rec->p = ray_at(*ray, rec->t);
	if (rec->t <= EPSILON || rec->t > rec->tmax)
		return (FALSE);
    if (!(is_inside_tri(triangle->point[0], triangle->point[1], triangle->point[2], rec->p)))
        return (FALSE);
	rec->normal = triangle->normal;
	rec->albedo = world->albedo;
	set_face_normal(ray, rec);
    return (TRUE);
}

/* 좌표가 삼각형 안에 있나 확인 */
t_bool			is_inside_tri(t_point3 p1, t_point3 p2, t_point3 p3, t_point3 p)
{
	if (vdot(vcross(vminus(p3, p1), vminus(p2, p1)), vcross(vminus(p, p1), vminus(p2, p1))) < 0)
		return (FALSE);
	if (vdot(vcross(vminus(p2, p1), vminus(p3, p1)), vcross(vminus(p, p1), vminus(p3, p1))) < 0)
		return (FALSE);
	if (vdot(vcross(vminus(p3, p2), vminus(p1, p2)), vcross(vminus(p, p2), vminus(p1, p2))) < 0)
		return (FALSE);
	if (vdot(vcross(vminus(p1, p2), vminus(p3, p2)), vcross(vminus(p, p2), vminus(p3, p2))) < 0)
		return (FALSE);
	if (vdot(vcross(vminus(p2, p3), vminus(p1, p3)), vcross(vminus(p, p3), vminus(p1, p3))) < 0)
		return (FALSE);
	if (vdot(vcross(vminus(p1, p3), vminus(p2, p3)), vcross(vminus(p, p3), vminus(p2, p3))) < 0)
		return (FALSE);
	return (TRUE);
}

/*
** 삼각형이 맞나 확인
*/
void			check_tri(t_point3 p1, t_point3 p2, t_point3 p3)
{
	double		len1;
	double		len2;
	double		len3;

	len1 = vlength(vminus(p1, p2));
	len2 = vlength(vminus(p2, p3));
	len3 = vlength(vminus(p1, p3));
	if (len1 < len2 && len2 > len3)
	{
		if (len2 > len1 + len3)
			error_message_basic("tr is wrong");
	}
	else if (len1 < len3 && len2 < len3)
	{
		if (len3 > len1 + len2)
			error_message_basic("tr is wrong");
	}
	else
	{
		if (len1 > len1 + len2)
			error_message_basic("tr is wrong");
	}
}