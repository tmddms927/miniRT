#include "structures.h"
#include "utils.h"
#include "trace.h"

/* 좌표가 원 안에 있나 확인하는 함수 */
double		hit_plane(t_object *world, t_ray *ray, t_hit_record *rec)
{
    double	denom;
	t_plane	*plane;

	plane = (t_plane *)world->element;
	denom = vdot(plane->normal, ray->dir);
	if (fabs(denom) < EPSILON)
		return (FALSE);
    rec->t = vdot(vminus(plane->point, ray->orig), plane->normal) / denom;
	if (rec->t < rec->tmin || rec->t > rec->tmax)
		return (FALSE);
    rec->p = ray_at(*ray, rec->t);
	rec->normal = plane->normal;
	rec->albedo = world->albedo;
	set_face_normal(ray, rec);
	return (TRUE);
}