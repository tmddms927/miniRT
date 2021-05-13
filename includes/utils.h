#ifndef UTILS_H
# define UTILS_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "structures.h"
# include "mlx.h"

t_vec3          vec3(double x, double y, double z);
t_point3        point3(double x, double y, double z);
t_color3        color3(double r, double g, double b);
void            v_set(t_vec3 *vec, double x, double y, double z);
double          vlength2(t_vec3 vec);
double          vlength(t_vec3 vec);
t_vec3          vplus(t_vec3 vec1, t_vec3 vec2);
t_vec3          vplus_(t_vec3 vec, double x, double y, double z);
t_vec3          vminus(t_vec3 vec1, t_vec3 vec2);
t_vec3          vminus_(t_vec3 vec, double x, double y, double z);
t_vec3          vmult(t_vec3 vec, double t);
t_vec3          vmult_(t_vec3 vec1, t_vec3 vec2);
t_vec3          vdivide(t_vec3 vec, double t);
double          vdot(t_vec3 vec1, t_vec3 vec2);
t_vec3          vcross(t_vec3 vec1, t_vec3 vec2);
t_vec3          vunit(t_vec3 vec);
t_vec3          vmin(t_vec3 vec1, t_vec3 vec2);
t_object            *oadd(t_object **list, t_object *new);
t_object        *olast(t_object *list);
t_camera        *cam_oadd(t_camera **list, t_camera *new);
t_camera        *cam_olast(t_camera *list);
t_camera        *cam_onext(t_camera *list);

void		    camera_input_image(t_vars vars, t_scene *scene);
void			next_camera(t_vars vars);
void            my_mlx_pixel_put(t_data *data, int x, int y, int color);
int             key_hook(int keycode, t_vars *vars);
void		scene_init(t_scene *scene, char *argv);


double		write_color(int t, t_color3 pixel_color);
void		check_window_size(t_vars vars);
void	set_face_normal(t_ray *ray, t_hit_record *rec);
#endif