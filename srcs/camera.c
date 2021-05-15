/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:40:55 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 18:18:08 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "scene.h"
#include "trace.h"

/*
** 카메라에 해당 이미지 넣어주기
*/

void	camera_input_image(t_vars vars, t_scene *scene)
{
	t_camera	*cam;
	int			i;
	int			j;
	double		u;
	double		v;

	cam = scene->camera;
	while (init_image(&j, vars, scene, cam))
	{
		while (--j >= 0)
		{
			i = -1;
			while (++i < scene->canvas.width)
			{
				u = (double)i / (scene->canvas.width - 1);
				v = (double)j / (scene->canvas.height - 1);
				scene->ray = ray_primary(cam, u, v);
				my_mlx_pixel_put(&cam->image, i,
					scene->canvas.height - 1 - j, wc(0, ray_color(scene)));
			}
		}
		cam = cam_onext(cam);
		if (cam == NULL)
			break ;
	}
}

/*
** 카메라 변경하기
*/

void	next_camera(t_vars vars)
{
	vars.scene->main_camera = cam_onext(vars.scene->main_camera);
	if (vars.scene->main_camera == NULL)
		vars.scene->main_camera = vars.scene->camera;
}

/*
** 원하는 좌표에 해당하는 주소에 color값을 넣는 함수
*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
** .rt 파일에서 정보 받아오기
*/

void	scene_init(t_scene *scene, char *argv, int argc)
{
	void	*temp;

	scene->camera = camera(point3(0, 0, 0));
	scene->world = object(SQUARE, square(point3(0, 0, 0),
		vec3(0, 0, 0), 0), color3(0, 0, 0));
	scene->light = object(LIGHT_POINT, light_point(point3(0, 0, 0),
		color3(0, 0, 0), 0), color3(0, 0, 0));
	scene->ambient.x = -1;
	parsing_start(argc, argv, scene);
	temp = scene->camera;
	scene->camera = scene->camera->next;
	free(temp);
	temp = scene->world;
	free(scene->world->element);
	scene->world = scene->world->next;
	free(temp);
	temp = scene->light;
	free(scene->light->element);
	scene->light = scene->light->next;
	free(temp);
	if (!(scene->camera) || scene->canvas.aspect_ratio == 0 ||
		scene->ambient.x == -1)
		error_message_basic("missing camera or canvas");
}
