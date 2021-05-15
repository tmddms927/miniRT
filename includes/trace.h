/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungoh <seungoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:21:49 by seungoh           #+#    #+#             */
/*   Updated: 2021/05/14 17:51:06 by seungoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H
# include "minirt.h"
# include "structures.h"
# include "utils.h"

t_ray			ray(t_point3 orig, t_vec3 dir);
t_point3		ray_at(t_ray ray, double t);
t_ray			ray_primary(t_camera *cam, double u, double v);
t_color3		ray_color(t_scene *scene);
t_bool			hit(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool			hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec);
double			hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);
t_hit_record	record_init(void);
t_color3		phong_lighting(t_scene *scene);
t_vec3			reflect(t_vec3 v, t_vec3 n);
t_color3		diffuse_light(t_scene *scene, t_light *light);
t_color3		specular_light(t_scene *scene, t_light *light);
t_bool			in_shadow(t_light *light, t_scene *scene);
void			set_face_normal(t_ray *ray, t_hit_record *rec);
t_color3        diffuse_light(t_scene *scene, t_light *light);
t_color3        specular_light(t_scene *scene, t_light *light);

/*
** plane 관련
*/
double			hit_plane(t_object *world, t_ray *ray, t_hit_record *rec);

/*
** square 관련
*/
double			hit_sq(t_object *world, t_ray *ray, t_hit_record *rec);
double			hit_spuare(t_object *world, t_ray *ray, t_hit_record *rec);
int				is_inside_square(t_square *square, t_point3 point);

/*
** triangle 관련
*/
double			hit_triangle(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool			is_inside_tri(t_point3 p1, t_point3 p2,
							t_point3 p3, t_point3 p);
t_bool			check_tr(t_vec3 a, t_vec3 b, t_vec3 c, t_vec3 h);

/*
** cylinder 관련
*/
double			hit_cylinder(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool			cylinder_discriminant(t_cylinder *cylinder,
							t_ray *ray, t_hit_record *rec);
t_bool			cylinder_height_check(t_cylinder *cylinder,
							t_ray *ray, t_hit_record *rec);

#endif
