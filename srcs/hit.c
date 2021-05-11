/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:50:51 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/12 01:50:53 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

/* 각 오브젝트를 순회하며 ray가 맞았는지 확인하는 함수 */
t_bool              hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
    t_bool          hit_anything;
    t_hit_record    temp_rec;

    temp_rec = *rec;
    hit_anything = FALSE;

    while (world)
    {
        if (hit_obj(world, ray, &temp_rec))
        {
            hit_anything = TRUE;
            temp_rec.tmax = temp_rec.t;
            *rec = temp_rec;
        }
        world = world->next;
    }
    return (hit_anything);
}

/* 각 오브젝트에 맞는 hit함수로 연결 */
t_bool              hit_obj(t_object *world, t_ray *ray, t_hit_record *rec)
{
    t_bool          hit_result;

    hit_result = FALSE;
    if (world->type == SP)
        hit_result = hit_sphere(world, ray, rec);
    else if (world->type == PLANE)
        hit_result = hit_plane(world, ray, rec);
    else if (world->type == SQUARE)
        hit_result = hit_spuare(world, ray, rec);
    else if (world->type == TRIANGLE)
        hit_result = hit_triangle(world, ray, rec);
    else if (world->type == CY)
       hit_result = hit_cylinder(world, ray, rec);
    return (hit_result);
}