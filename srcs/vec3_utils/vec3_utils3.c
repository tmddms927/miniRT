/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 10:25:48 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 10:26:30 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** 벡터 곱(벡터 * 벡터)
*/

t_vec3          vmult_(t_vec3 vec1, t_vec3 vec2)
{
    vec1.x *= vec2.x;
    vec1.y *= vec2.y;
    vec1.z *= vec2.z;
    return (vec1);
}

/*
** 벡터 스칼라 나누기
*/

t_vec3          vdivide(t_vec3 vec, double t)
{
    vec.x *= 1 / t;
    vec.y *= 1 / t;
    vec.z *= 1 / t;
    return (vec);
}

/*
** 벡터 내적
*/

double          vdot(t_vec3 vec1, t_vec3 vec2)
{
    return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

/*
** 벡터 외적
*/

t_vec3          vcross(t_vec3 vec1, t_vec3 vec2)
{
    t_vec3 new;

    new.x = vec1.y * vec2.z - vec1.z * vec2.y;
    new.y = vec1.z * vec2.x - vec1.x * vec2.z;
    new.z = vec1.x * vec2.y - vec1.y * vec2.x;
    return (new);
}

/*
** 단위 벡터
*/

t_vec3          vunit(t_vec3 vec)
{
    double      len;

    len = vlength(vec);
    if (len == 0)
    {
        printf("Error\nDevidef is 0\n");
        exit(1);
    }
    vec.x /= len;
    vec.y /= len;
    vec.z /= len;
    return (vec);
}
