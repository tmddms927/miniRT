#include "structures.h"
#include "utils.h"
#include "trace.h"

/* 삼각형 판별 함수 */
double			hit_triangle(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_triangle	*triangle;

    triangle = (t_triangle *)world->element;
	rec->t = -vdot(vminus(ray->orig, triangle->point[0]), triangle->normal) / vdot(triangle->normal, ray->dir);
    rec->p = ray_at(*ray, rec->t);
    if (!(is_inside_tri(triangle->point[0], triangle->point[1], triangle->point[2], rec->p)))
        return (FALSE);
	rec->normal = triangle->normal;
	rec->albedo = world->albedo;
	set_face_normal(ray, rec);
    return (TRUE);
}

/* 좌표가 삼각형 안에 있나 확인 */
t_bool			is_inside_tri(t_point3 p1, t_point3 p2, t_point3 p3, t_point3 p)
{
	if (vdot(vcross(vminus(p3, p1), vminus(p2, p1)), vcross(vminus(p, p1), vminus(p2, p1))) < 0)
		return (FALSE);
	if (vdot(vcross(vminus(p2, p1), vminus(p3, p1)), vcross(vminus(p, p1), vminus(p3, p1))) < 0)
		return (FALSE);
	if (vdot(vcross(vminus(p3, p2), vminus(p1, p2)), vcross(vminus(p, p2), vminus(p1, p2))) < 0)
		return (FALSE);
	if (vdot(vcross(vminus(p1, p2), vminus(p3, p2)), vcross(vminus(p, p2), vminus(p3, p2))) < 0)
		return (FALSE);
	if (vdot(vcross(vminus(p2, p3), vminus(p1, p3)), vcross(vminus(p, p3), vminus(p1, p3))) < 0)
		return (FALSE);
	if (vdot(vcross(vminus(p1, p3), vminus(p2, p3)), vcross(vminus(p, p3), vminus(p2, p3))) < 0)
		return (FALSE);
	return (TRUE);
}