#include "scene.h"
#include "trace.h"
#include "parsing.h"

/*
** 색 trgb double 값으로 변환
*/
double		write_color(int t, t_color3 pixel_color)
{
	return (t << 24 | (int)(255.999 * pixel_color.x) << 16 | (int)(255.999 * pixel_color.y) << 8 | (int)(255.999 * pixel_color.z));
}

/*
** 화면의 최대 크기 확인
*/
void		check_window_size(t_vars vars)
{
	int	x;
	int	y;

	mlx_get_screen_size(vars.mlx, &x, &y);
	if (vars.scene->canvas.width > x)
		vars.scene->canvas.width = x;
	if (vars.scene->canvas.height > y)
		vars.scene->canvas.height = y;
}

/* 오브젝트가 제일 앞에 있나 확인하는 함수 */
void	set_face_normal(t_ray *ray, t_hit_record *rec)
{
	rec->front_face = vdot(ray->dir, rec->normal) < 0;
	rec->normal = (rec->front_face) ? rec->normal : vmult(rec->normal, -1);
}