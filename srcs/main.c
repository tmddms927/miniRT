/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:50:54 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 17:13:07 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"
#include "parsing.h"
#include "structures.h"
#include "utils.h"

int				main(int argc, char **argv)
{
	t_vars		vars;
	t_scene		*scene;

	if (!(scene = (t_scene *)malloc(sizeof(t_scene) * 1)))
		error_message_errno("failed malloc");
	scene_init(scene, argv[1], argc);
	vars.mlx = mlx_init();
	vars.scene = scene;
	vars.scene->main_camera = vars.scene->camera;
	check_window_size(vars);
	vars.win = mlx_new_window(
		vars.mlx, scene->canvas.width, scene->canvas.height, "SEUNGOH World!");
	camera_input_image(vars, scene);
	check_save(argv[2], scene);
	mlx_put_image_to_window(vars.mlx, vars.win,
		scene->main_camera->image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, (1L << 5), close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
