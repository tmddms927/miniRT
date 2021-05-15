/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:50:42 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 17:23:31 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "trace.h"
#include "utils.h"

/*
** 좌표가 원 안에 있나 확인하는 함수
*/

double			hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec)
{
	double		half_b;
	double		discriminant;
	double		root;
	t_sphere	*sp;

	sp = world->element;
	half_b = vdot(vminus(ray->orig, sp->center), ray->dir);
	discriminant = half_b * half_b -
		vlength2(ray->dir) * (vlength2(vminus(ray->orig, sp->center)) -
		sp->radius2);
	if (discriminant < 0)
		return (FALSE);
	root = (-half_b - sqrt(discriminant)) / vlength2(ray->dir);
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrt(discriminant)) / vlength2(ray->dir);
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(*ray, root);
	rec->normal = vunit(vminus(rec->p, sp->center));
	rec->albedo = world->albedo;
	set_face_normal(ray, rec);
	return (TRUE);
}
