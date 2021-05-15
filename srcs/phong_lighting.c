/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:51:05 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 10:36:05 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"
#include <unistd.h>

/*
** 광원과 그림자를 처리해주는 함수(ambient + diffuse + specular)
*/

t_color3		phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*lights;

	light_color = color3(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		if(lights->type == LIGHT_POINT)
		{
			if (in_shadow(lights->element, scene))
			{
				light_color = vplus(light_color, color3(0, 0, 0));
				lights = lights->next;
				continue ;
			}
			light_color = vplus(light_color, diffuse_light(scene, lights->element));
			light_color = vplus(light_color, specular_light(scene, lights->element));
		}
		lights = lights->next;
	}
	light_color = vplus(light_color, scene->ambient);
	return (vmin(vmult_(light_color, scene->rec.albedo), color3(1, 1, 1)));
}

/*
** diffuse color 계산
*/

t_color3			diffuse_light(t_scene *scene, t_light *light)
{
    t_color3    diffuse;
    t_vec3      light_dir;
    double      kd;

    light_dir = vunit(vminus(light->origin, scene->rec.p));
    kd = fmax(vdot(scene->rec.normal, light_dir), 0.0);
    diffuse = vmult(light->light_color, kd);
	return (diffuse);
}

/*
** specular	color 계산
*/

t_color3			specular_light(t_scene *scene, t_light *light)
{
    t_color3    specular;
    t_vec3      reflect_dir;
    double      spec;
	t_vec3      light_dir;

	light_dir = vunit(vminus(light->origin, scene->rec.p));
	reflect_dir = vunit(reflect(scene->ray.dir, scene->rec.normal));
    spec = pow(fmax(vdot(light_dir, reflect_dir), 0.0), 30);
    specular = vmult(vmult(light->light_color, 1.5), spec);
    return (specular);
}

/*
** 그림자 구현 함수
*/

t_bool				in_shadow(t_light *light, t_scene *scene)
{
	t_hit_record	rec;
    t_ray			light_ray;
	t_vec3			light_dir;

	light_dir = vminus(light->origin, scene->rec.p);
    light_ray = ray(vplus(scene->rec.p, vmult(vunit(scene->rec.normal), EPSILON)), light_dir);
	rec.tmin = 0;
	rec.tmax = vlength(light_dir);
	if (hit(scene->world, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

/*
** 반사광 계산 함수
*/

t_vec3          reflect(t_vec3 v, t_vec3 n)
{
    /*
    ** v - 2 * dot(v, n) * n;
    */
    return (vminus(v, vmult(n, vdot(v, n) * 2)));
}
