#ifndef SCENE_H
# define SCENE_H

#include "structures.h"
#include "utils.h"

t_canvas	canvas(int width, int height);
t_camera	*camera(t_point3 orig);
t_object	*object(t_object_type type, void *element, t_color3 albedo);
t_sphere	*sphere(t_point3 center, double radius);
t_plane		*plane(t_point3 point, t_vec3 normal);
t_square	*square(t_point3 center, t_vec3 normal, double side_size);
t_triangle	*triangle(t_point3 a, t_point3 b, t_point3 c);
t_cylinder	*cylinder(t_point3 point, t_vec3 normal, double radius, double height);
t_light		*light_point(t_point3 light_origin, t_color3 ligth_color, double bright_ratio);
void		set_camera(t_canvas *canvas, t_camera *cam);
#endif