/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:50:54 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/12 01:50:55 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "scene.h"
#include "trace.h"
#include "print.h"
#include "parsing.h"

/* 원하는 좌표에 해당하는 주소에 color값을 넣는 함수 */
void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

/* escape key event */
int key_hook(int keycode, t_vars *vars)
{
    if(keycode == 53)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    return (0);
}

t_scene		*scene_init(t_scene *scene, char *argv)
{
	t_object	*world;
	t_object	*lights;
	double		ka;

	if (!(scene = (t_scene *)malloc(sizeof(t_scene) * 1)))
		error_message_errno("failed malloc");
	//scene->canvas = canvas(1000, 600);
	//scene->camera = cam_oadd(&scene->camera, camera(&scene->canvas, point3(0, 0, 0)));
	//scene->camera = cam_oadd(&scene->camera, camera(&scene->canvas, point3(1, 1, 1)));
	//printf("%f, %f, %f\n", scene->camera->orig.x, scene->camera->orig.y, scene->camera->orig.z);
	//printf("%f, %f, %f\n", scene->camera->next->orig.x, scene->camera->next->orig.y, scene->camera->next->orig.z);
	world = object(SQUARE, square(point3(0, 0, 0), vec3(0, 0, 0), 0), color3(0, 0, 0));
	scene->world = world;	
	
	parsing_start(argv, scene);
	oadd(&world, object(TRIANGLE, triangle(point3(-3.5, -2, -3), point3(-2.5, 3, -3), point3(-1.5, -2, -3)), color3(0.6, 0.1, 0.3)));
	/*
	oadd(&world, object(SQUARE, square(point3(3, 3, -5), vec3(0.3, 1, 0.4), 2), color3(0.5, 0, 0)));
	oadd(&world, object(SP, sphere(point3(-5, 3, -5), 1), color3(0.5, 0, 0)));
	oadd(&world, object(SP, sphere(point3(2, 0, -5), 2), color3(0, 0.3, 1)));
	oadd(&world, object(CY, cylinder(point3(0, 0, -5), vec3(0, 1, 0), 1, 1), color3(0, 1, 0.3)));
	*/
	lights = object(LIGHT_POINT, light_point(point3(5, 10, 0), color3(1, 1, 0), 0.2), color3(0, 0, 0));
	
	scene->light = lights;
	ka = 0.9;
	scene->ambient = vmult(color3(1, 1, 1), ka);
	return(scene);
}

int         main(int argc, char **argv)
{
    t_vars		vars;
    t_data		image;
	t_color3	pixel_color;
	int			i;
	int			j;
	double		u;
	double		v;
	t_scene		*scene;

	(void)argc;
	scene = (t_scene *)malloc(sizeof(t_scene));

	scene = scene_init(scene, argv[1]);

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, scene->canvas.width, scene->canvas.height, "SEUNGOH World!");
    image.img = mlx_new_image(vars.mlx, scene->canvas.width, scene->canvas.height);
    image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	j = scene->canvas.height - 1;

	while (j >= 0)
	{
		i = 0;
		while (i < scene->canvas.width)
		{
			u = (double)i / (scene->canvas.width - 1);
			v = (double)j / (scene->canvas.height - 1);
			scene->ray = ray_primary(scene->camera, u, v);
			pixel_color = ray_color(scene);
			my_mlx_pixel_put(&image, i, scene->canvas.height - 1 - j, write_color(0, pixel_color));
			++i;
		}
		--j;
	}
    mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_loop(vars.mlx);
    return (0);
}
