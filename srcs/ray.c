/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:51:10 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 17:52:35 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

/*
** ray 생성자 (정규화 된 ray)
*/

t_ray				ray(t_point3 orig, t_vec3 dir)
{
	t_ray			ray;

	ray.orig = orig;
	ray.dir = vunit(dir);
	return (ray);
}

/*
** ray origin point부터 방향벡터 ray dir * t 만큼 떨어진 점
*/

t_point3			ray_at(t_ray ray, double t)
{
	t_point3		at;

	at = vplus(ray.orig, vmult(ray.dir, t));
	return (at);
}

/*
** primary_ray 생성자
*/

t_ray				ray_primary(t_camera *cam, double u, double v)
{
	t_ray			ray;

	ray.orig = cam->orig;
	ray.dir = vunit(vminus(vplus(vplus(cam->left_bottom,
									vmult(cam->horizontal, u)),
									vmult(cam->vertical, v)),
							cam->orig));
	return (ray);
}

/*
** 광선이 최종적으로 얻게된 픽셀의 색상 값을 리턴
*/

t_color3			ray_color(t_scene *scene)
{
	scene->rec = record_init();
	if (hit(scene->world, &scene->ray, &scene->rec))
		return (phong_lighting(scene));
	return (vec3(0, 0, 0));
}

/*
** record 값 초기화
*/

t_hit_record		record_init(void)
{
	t_hit_record	record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}
