/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:50:29 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/12 02:14:34 by seungoh          ###   ########.fr       */
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

t_camera	*camera(t_canvas *canvas, t_point3 orig)
{
	t_camera	*cam;
	double		viewport_height;

	if (!(cam = (t_camera *)malloc(sizeof(t_camera))))
		error_message_errno("failed malloc");
	viewport_height = 2.0;
	cam->orig = orig;
	cam->viewport_h = viewport_height;
	cam->viewport_w = viewport_height * canvas->aspect_ratio;
	cam->focal_len = 1.0;
	cam->horizontal = vec3(cam->viewport_w, 0, 0);
	cam->vertical = vec3(0, cam->viewport_h, 0);
	cam->left_bottom = vminus(vminus(vminus(cam->orig, vdivide(cam->horizontal, 2)),
								vdivide(cam->vertical, 2)), vec3(0, 0, cam->focal_len));
	return (cam);
}