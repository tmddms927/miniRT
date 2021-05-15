/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:51:13 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 10:28:36 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** 벡터3 생성자
*/

t_vec3			vec3(double x, double y, double z)
{
    t_vec3		vec;

    vec.x = x;
    vec.y =y;
    vec.z = z;
    return (vec);
}

/*
** 포인트3 생성자
*/

t_point3		point3(double x, double y, double z)
{
    t_point3	point;

    point.x = x;
    point.y =y;
    point.z = z;
    return (point);
}

/*
** 색상3 생성자
*/

t_color3		color3(double r, double g, double b)
{
    t_color3	color;

    color.x = r;
    color.y = g;
    color.z = b;
    return (color);
}

/*
** 벡터 길이 제곱
*/

double			vlength2(t_vec3 vec)
{
    return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

/*
** 벡터 길이
*/

double			vlength(t_vec3 vec)
{
    return (sqrt(vlength2(vec)));
}