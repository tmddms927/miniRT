/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:51:05 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/12 01:51:06 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

/* 광원과 그림자를 처리해주는 함수(ambient + diffuse + specular) */
t_color3		phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*lights;

	light_color = color3(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		if(lights->type == LIGHT_POINT)
			light_color = vplus(light_color, point_light_get(scene, lights->element));
		lights = lights->next;
	}
	light_color = vplus(light_color, scene->ambient);
	return (vmin(vmult_(light_color, scene->rec.albedo), color3(1, 1, 1)));
}

/* diffuse light의 강도(kd) 구한 후 교점에 도달한 빛의 양 계산 */
t_color3        point_light_get(t_scene *scene, t_light *light)
{
    t_color3    diffuse;
    t_vec3      light_dir;
    double      kd;
    /* 그림자 */
    double      light_len;
    t_ray       light_ray;
    /* 반사광 요소 */
    t_color3    specular;
    t_vec3      view_dir;
    t_vec3      reflect_dir;
    double      spec;
    double      ksn;
    double      ks;
    /* 광원 밝기 */
    //double      brightness;

    /* 그림자 처리 */
    light_dir = vminus(light->origin, scene->rec.p);
    light_len = vlength(light_dir);
    light_ray = ray(vplus(scene->rec.p, vmult(scene->rec.normal, EPSILON)), light_dir);
    if (in_shadow(scene->world, light_ray, light_len))
        return (color3(0, 0, 0));
    light_dir = vunit(light_dir);

    /* diffuse light */
    kd = fmax(vdot(scene->rec.normal, light_dir), 0.0);
    diffuse = vmult(light->light_color, kd);

    /* specular light */
    view_dir = vunit(vmult(scene->ray.dir, -1));
    reflect_dir = reflect(vmult(light_dir, -1), scene->rec.normal);
    ksn = 99; // shininess value
    ks = 0.9; // specular strength
    spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), ksn);
    specular =  vmult(vmult(light->light_color, ks), spec);
    //specular = vmult(light->light_color, ks);
    return (vplus(diffuse, specular));
    //return (  vmult( vplus(specular, diffuse), brightness), color3(0,0,0)  );
}

/* 반사광 계산 함수 */
t_vec3			reflect(t_vec3 v, t_vec3 n)
{
	//v - 2 * dot(v, n) * n;
	return (vminus(v, vmult(n, vdot(v, n) * 2)));
}

/* 그림자 구현 함수 */
t_bool		in_shadow(t_object *objs, t_ray ligth_ray, double light_len)
{
	t_hit_record rec;

	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(objs, &ligth_ray, &rec))
		return (TRUE);
	return (FALSE);
}