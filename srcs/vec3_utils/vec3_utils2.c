/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 10:26:36 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 16:31:07 by hyson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** 벡터 합(벡터 + 벡터)
*/

t_vec3	vplus(t_vec3 vec1, t_vec3 vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	vec1.z += vec2.z;
	return (vec1);
}

/*
** 벡터 합(벡터 + 좌표값)
*/

t_vec3	vplus_(t_vec3 vec, double x, double y, double z)
{
	vec.x += x;
	vec.y += y;
	vec.z += z;
	return (vec);
}

/*
** 벡터 차(벡터 - 벡터)
*/

t_vec3	vminus(t_vec3 vec1, t_vec3 vec2)
{
	vec1.x -= vec2.x;
	vec1.y -= vec2.y;
	vec1.z -= vec2.z;
	return (vec1);
}

/*
** 벡터 차(벡터 - 좌표값)
*/

t_vec3	vminus_(t_vec3 vec, double x, double y, double z)
{
	vec.x -= x;
	vec.y -= y;
	vec.z -= z;
	return (vec);
}

/*
** 벡터 곱(벡터 * 스칼라)
*/

t_vec3	vmult(t_vec3 vec, double t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;
	return (vec);
}
