/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:15:15 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 17:15:24 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "scene.h"

/*
** 원기둥 생성자
*/

t_cylinder			*cylinder(t_point3 point, t_vec3 normal,
								double radius, double height)
{
	t_cylinder		*cylinder;

	if (!(cylinder = (t_cylinder *)malloc(sizeof(t_cylinder) * 1)))
		error_message_errno("failed malloc");
	cylinder->point = point;
	cylinder->normal = normal;
	cylinder->radius = radius;
	cylinder->height = height;
	return (cylinder);
}

/*
** 광원 생성자
*/

t_light				*light_point(t_point3 light_origin,
						t_color3 light_color, double bright_ratio)
{
	t_light			*light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		error_message_errno("failed malloc");
	light->origin = light_origin;
	light->light_color = vmult(light_color, bright_ratio);
	light->bright_ratio = bright_ratio;
	return (light);
}
