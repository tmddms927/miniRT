#include "structures.h"
#include "utils.h"
#include "trace.h"

/* 좌표가 사각형 안에 있나 확인하는 함수 */
double		hit_spuare(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_square	*square;
	t_vec3	u;
	t_vec3	v;
	double a;
	double b;

	if (hit_plane(world, ray, rec) == FALSE)
		return (FALSE);
	square = (t_square *)world->element;
	v = vec3(0, 1, 0);
	if (square->normal.x == 0 && square->normal.y == 1 && square->normal.z == 0)
		v = vec3(0, 0, 1);
	u = vunit(vcross(v, square->normal));
	a = vdot(vminus(rec->p, square->center), u);
	b = vdot(vminus(rec->p, square->center), v);
	if (!(a > square->side_size / -2.0 && a < square->side_size / 2.0) ||
			!(b > square->side_size / -2.0 && b < square->side_size / 2.0))
		return (FALSE);
	rec->normal = square->normal;
	rec->albedo = world->albedo;
	set_face_normal(ray, rec);
    return (TRUE);
}