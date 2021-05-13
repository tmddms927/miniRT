/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:50:54 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/12 22:29:34 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "trace.h"
#include "parsing.h"
#include "utils.h"

int         main(int argc, char **argv)
{
    t_vars		vars;
	t_scene		*scene;

	(void)argc;
	if (!(scene = (t_scene *)malloc(sizeof(t_scene) * 1)))
		error_message_errno("failed malloc");
	scene = scene_init(scene, argv[1]);
	vars.mlx = mlx_init();
	vars.scene = scene;
	vars.scene->main_camera = vars.scene->camera;
	check_window_size(vars);
    vars.win = mlx_new_window(vars.mlx, scene->canvas.width, scene->canvas.height, "SEUNGOH World!");
    camera_input_image(vars, scene);
    mlx_put_image_to_window(vars.mlx, vars.win, scene->main_camera->image.img, 0, 0);
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_loop(vars.mlx);
    return (0);
}
