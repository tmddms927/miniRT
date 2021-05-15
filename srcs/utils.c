/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:19:45 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/15 17:20:26 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"
#include "scene.h"
#include "trace.h"
#include "utils.h"

/*
** 색 trgb double 값으로 변환
*/

double			wc(int t, t_color3 pixel_color)
{
	return (t << 24 | (int)(255.999 * pixel_color.x) << 16 |
			(int)(255.999 * pixel_color.y) << 8 |
			(int)(255.999 * pixel_color.z));
}

/*
** 화면의 최대 크기 확인
*/

void			check_window_size(t_vars vars)
{
	int			x;
	int			y;

	mlx_get_screen_size(vars.mlx, &x, &y);
	if (vars.scene->canvas.width > x)
		vars.scene->canvas.width = x;
	if (vars.scene->canvas.height > y)
		vars.scene->canvas.height = y;
}

/*
** 오브젝트가 제일 앞에 있나 확인하는 함수
*/

void			set_face_normal(t_ray *ray, t_hit_record *rec)
{
	rec->front_face = vdot(ray->dir, rec->normal) < 0;
	rec->normal = (rec->front_face) ? rec->normal : vmult(rec->normal, -1);
}

/*
** escape 키로 윈도우 창 종료
*/

int				key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		printf("close window\n");
		exit(0);
	}
	if (keycode == 8)
	{
		next_camera(*vars);
		mlx_put_image_to_window(
			vars->mlx, vars->win, vars->scene->main_camera->image.img, 0, 0);
	}
	return (0);
}

/*
** 윈도우 X버튼 누르면 프로그램 종료
*/

int				close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	printf("close window\n");
	exit(0);
}
