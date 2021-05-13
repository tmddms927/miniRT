/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:50:29 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/13 15:01:13 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "utils.h"
#include "trace.h"
#include "get_next_line.h"
#include "parsing.h"

/* 캔버스 생성 */
t_canvas	canvas(int width, int height)
{
	t_canvas canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

t_camera	*camera(t_point3 orig)
{
	t_camera	*cam;

	if (!(cam = (t_camera *)malloc(sizeof(t_camera))))
		error_message_errno("failed malloc");
	cam->orig = orig;
	cam->next = NULL;
	return (cam);
}

/*
** 카메라 값 설정
*/
void		set_camera(t_canvas *canvas, t_camera *cam)
{
	t_vec3	temp;
	
	temp = vec3(0, 1, 0);
	cam->horizontal = vunit(vcross(temp, cam->normal));
	cam->vertical = vunit(vcross(cam->normal, cam->horizontal));
	cam->viewport_h = 2 * tan(cam->fov / 2.0);
	cam->viewport_w = cam->viewport_w * canvas->aspect_ratio;
	cam->focal_len = 1.0;
	cam->left_bottom = vminus(vminus(vminus(cam->orig, vdivide(cam->horizontal, 2)),
								vdivide(cam->vertical, 2)), vec3(0, 0, cam->focal_len));
}
