/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:50:35 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/14 11:37:32 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"

/*
** 좌표가 원기둥 안에 있나 확인하는 함수
*/

double				hit_cylinder(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_cylinder		*cylinder;

	cylinder = (t_cylinder *)world->element;
	if (cylinder_discriminant(cylinder, ray, rec) == FALSE)
		return (FALSE);
	rec->p = ray_at(*ray, rec->t);
	rec->normal = vunit(vdivide(vminus(vminus(rec->p, cylinder->point),
					vmult(cylinder->normal,
					vdot(cylinder->normal, vminus(rec->p, cylinder->point)))),
						cylinder->radius));
	rec->albedo = world->albedo;
	if (!cylinder_height_check(cylinder, ray, rec))
		return (FALSE);
	set_face_normal(ray, rec);
	return (TRUE);
}

/*
** 판별식으로 point가 원기둥을 hit하나 확인
*/

t_bool				cylinder_discriminant(t_cylinder *cylinder,
											t_ray *ray, t_hit_record *rec)
{
	double			a;
	double			b;
	double			c;
	double			d;

	a = vlength2(vminus(ray->dir, vmult(cylinder->normal,
			vdot(cylinder->normal, ray->dir))));
	b = vdot(vminus(ray->dir, vmult(cylinder->normal,
			vdot(cylinder->normal, ray->dir))),
			vminus(vminus(ray->orig, cylinder->point),
			vmult(cylinder->normal, vdot(cylinder->normal,
			vminus(ray->orig, cylinder->point)))));
	c = vlength2(vminus(vminus(ray->orig, cylinder->point),
			vmult(cylinder->normal, vdot(cylinder->normal,
			vminus(ray->orig, cylinder->point))))) -
			cylinder->radius * cylinder->radius;
	d = b * b - a * c;
	rec->t = (-b - sqrt(d)) / a;
	rec->t2 = (-b + sqrt(d)) / a;
	if (d < 0)
		return (FALSE);
	if (rec->t < rec->tmin || rec->t > rec->tmax)
		if (rec->t2 < rec->tmin || rec->t2 > rec->tmax)
			return (FALSE);
	return (TRUE);
}

/*
** 원기둥 길이 제한 함수
*/

t_bool				cylinder_height_check(t_cylinder *cylinder,
												t_ray *ray, t_hit_record *rec)
{
	double			h;

	h = vlength2(vminus(rec->p, cylinder->point)) -
			cylinder->radius * cylinder->radius;
	if (sqrt(h) > cylinder->height)
	{
		rec->p = ray_at(*ray, rec->t2);
		h = vlength2(vminus(rec->p, cylinder->point)) -
				cylinder->radius * cylinder->radius;
		rec->normal = vunit(vdivide(vminus(
						vminus(rec->p, cylinder->point), vmult(cylinder->normal,
					vdot(cylinder->normal, vminus(rec->p, cylinder->point)))),
						cylinder->radius));
		if (sqrt(h) > cylinder->height)
			return (FALSE);
	}
	return (TRUE);
}
