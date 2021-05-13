/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:40:55 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/13 15:01:30 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "trace.h"
#include "parsing.h"

/*
** 카메라에 해당 이미지 넣어주기
*/
void		camera_input_image(t_vars vars, t_scene *scene)
{
	t_camera	*cam;
	int			i;
	int			j;
	double		u;
	double		v;

	cam = scene->camera;
	while (1)
	{
		cam->image.img = mlx_new_image(vars.mlx, scene->canvas.width, scene->canvas.height);
		cam->image.addr = mlx_get_data_addr(cam->image.img, &cam->image.bits_per_pixel, &cam->image.line_length, &cam->image.endian);
		j = scene->canvas.height;
		while (--j >= 0)
		{
			i = -1;
			while (++i < scene->canvas.width)
			{
				u = (double)i / (scene->canvas.width - 1);
				v = (double)j / (scene->canvas.height - 1);
				scene->ray = ray_primary(cam, u, v);
				my_mlx_pixel_put(&cam->image, i, scene->canvas.height - 1 - j, write_color(0, ray_color(scene)));
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
void			next_camera(t_vars vars)
{
	vars.scene->main_camera = cam_onext(vars.scene->main_camera);
	if (vars.scene->main_camera == NULL)
		vars.scene->main_camera = vars.scene->camera;
}

/*
** 원하는 좌표에 해당하는 주소에 color값을 넣는 함수
*/
void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

/*
** escape 키로 윈도우 창 종료
*/
int key_hook(int keycode, t_vars *vars)
{
    if (keycode == 53)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
	if (keycode == 8)
	{
		next_camera(*vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->scene->main_camera->image.img, 0, 0);
	}
    return (0);
}

/*
** .rt 파일에서 정보 받아오기
*/
t_scene		*scene_init(t_scene *scene, char *argv)
{
	void	*temp;

	scene->camera = camera(point3(0, 0, 0));
	scene->world = object(SQUARE, square(point3(0, 0, 0),
		vec3(0, 0, 0), 0), color3(0, 0, 0));
	scene->light = object(LIGHT_POINT, light_point(point3(0, 0, 0),
		color3(0, 0, 0), 0), color3(0, 0, 0));
	parsing_start(argv, scene);
	temp = scene->camera;
	scene->camera = scene->camera->next;
	free(temp);
	temp = scene->world;
	scene->world = scene->world->next;
	free(temp);
	temp = scene->light;
	scene->light = scene->light->next;
	free(temp);
	if (!(scene->camera) || scene->canvas.aspect_ratio == 0)
		error_message_basic("missing camera or canvas");
	return(scene);
}