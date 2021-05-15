/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:54:37 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 17:10:55 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "structures.h"

int				init_image(int *j, t_vars vars, t_scene *scene, t_camera *cam)
{
	cam->image.img = mlx_new_image(vars.mlx, scene->canvas.width,
						scene->canvas.height);
	cam->image.addr = mlx_get_data_addr(cam->image.img,
						&cam->image.bits_per_pixel, &cam->image.line_length,
						&cam->image.endian);
	*j = scene->canvas.height;
	return (1);
}
