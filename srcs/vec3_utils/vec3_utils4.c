/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 10:25:26 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 10:25:31 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** 두 벡터의 원소를 비교하여 작은 값들만 반환
*/

t_vec3          vmin(t_vec3 vec1, t_vec3 vec2)
{
    if (vec1.x > vec2.x)
         vec1.x = vec2.x;
    if (vec1.y > vec2.y)
        vec1.y = vec2.y;
    if (vec1.z > vec2.z)
         vec1.z = vec2.z;
    return (vec1);
}

/*
** 벡터 값 설정
*/

void            v_set(t_vec3 *vec, double x, double y, double z)
{
    vec->x = x;
    vec->y = y;
    vec->z = z;
}
