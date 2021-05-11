#ifndef STRUCTURES_H
# define STRUCTURES_H
# define FALSE 0
# define TRUE 1
# define SP 0
# define PLANE 1
# define SQUARE 2
# define TRIANGLE 3
# define CY 4
# define LIGHT_POINT 1
# define EPSILON 1e-6 // 0.000001 더블 데이터 근사값
# define LUMEN 3  // 기준광선속의 곱으로 빛의 세기 조절 이 값을 조절하여 장면의 밝기를 조절할 수 있다.

typedef struct s_vec3   t_point3;
typedef struct s_vec3   t_color3;
typedef int             t_bool;
typedef int             t_object_type;
typedef struct s_camera t_camera;


typedef struct      s_vec3{
    double          x;
    double          y;
    double          z;
}                   t_vec3;

typedef struct      s_ray{
    t_point3        orig;
    t_vec3          dir;
}                   t_ray;

typedef struct      s_camera{
    t_point3        orig;
    double          viewport_h;
    double          viewport_w;
    t_vec3          horizontal;
    t_vec3          vertical;
    double          focal_len;
    t_point3        left_bottom;
    t_camera        *next;
}                   t_camera;

typedef struct      s_canvas
{
    int             width;
    int             height;
    double          aspect_ratio;
}                   t_canvas;

/* 이미지의 정보를 나타내는 변수를 저장한 구조체 */
typedef struct      s_data
{
    void            *img;
    char            *addr;
    int             bits_per_pixel;
    int             line_length;
    int             endian;
}                   t_data;

/* mlx 구조체 mlx 포인터와 생성할 win 포인터를 가지고 있다 */
typedef struct      s_vars {
    void            *mlx;
    void            *win;
}                   t_vars;


/* hit 정보 구조체 */
typedef struct      s_hit_record
{
    /* 교점의 좌표 */
    t_point3        p;
    /* 교점에서의 법선 */
    t_vec3          normal;
    double          tmin;
    double          tmax;
    /* 광선의 원점과 교점 사이의 거리 */
    double          t;
    t_bool          front_face;
    t_color3        albedo;
}                   t_hit_record;

/* 오브젝트 구조체 */
typedef struct      s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
    t_color3        albedo;
}                   t_object;

/* 구 정보 구조체 */
typedef struct	    s_sphere
{
    t_point3	    center;
    double		    radius;
    double		    radius2;
}                   t_sphere;

/* 평면 구조체 */
typedef struct      s_plane
{
	t_point3		point;
	t_vec3		    normal;
}                   t_plane;

/* 사각형 구조체 */
typedef struct      s_square
{
    t_point3        center;
    t_vec3          normal;
    t_point3        min;
    t_point3        max;
    double          side_size;
}                   t_square;

/* 삼각형 구조체 */
typedef struct      s_triangle
{
    t_point3        point[3];
    t_vec3          normal;
}                   t_triangle;

/* 원기둥 구조체 */
typedef struct      s_cylinder
{
    t_point3        point;
    t_vec3          normal;
    double          radius;
    double          height;
}                   t_cylinder;

/* 원기둥 판별식 요소 */
typedef struct	s_cy_set
{
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		sqrtd;
	double		t;
	t_vec3		delp;
	t_point3	pa;
	t_point3	p;
	t_vec3		normal;
}				t_cy_set;

/* 원기둥 뚜껑 원 판별식 요소 */
typedef struct  s_disc_set
{
    double      t;
    double      denom;
    t_point3    to_hit;
    t_point3    p;
}               t_disc_set;

/* 점광원 구조체 */
typedef struct      s_light
{
    t_point3        origin;
    t_color3        light_color;
    double          bright_ratio;
}                   t_light;

/* 한 scene 안에 필요한 요소들을 묶어놓은 구조체 */
typedef struct      s_scene
{
    t_canvas        canvas;
    t_camera        *camera;
    t_object        *world;
    t_object        *light;
    t_color3        ambient;
    t_ray           ray;
    t_hit_record    rec;
}                   t_scene;

#endif