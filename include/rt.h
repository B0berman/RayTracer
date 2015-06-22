/*
** rt.h for include in /home/zack/Projects/MUL_2014_rtracer/include
** 
** Made by Antoine Favarel
** Login   <favare_a@epitech.net>
** 
** Started on  mer. avril 01 15:13:54 2015 Antoine Favarel
** Last update Sat Jun  6 16:30:40 2015 walbec_h
*/

#ifndef		RT_H_
# define	RT_H_

# define	ABS(value)	((value) < 0 ? - (value) : (value))
# define	RAD(a)		(a * M_PI / 180)
# define	TAN(x)		(pow(tan(RAD(x)), 2))
# define	X2(x)		(x * x)
# define	M_PI		(3.1415926535)
# define	AMBIANCE	(0.2)

# include	<math.h>

# include	"neptune/list.h"
# include	"minilibx/mlx.h"
# include	"neptune/clust/dispatcher.h"

typedef unsigned char	uchar;
typedef	unsigned int	uint;

typedef enum	e_type
  {
    T_SPHERE,
    T_PLAN,
    T_CONE,
    T_CYLINDER
  }		t_type;

typedef	struct	s_color
{
  uchar		r;
  uchar		g;
  uchar		b;
  uchar		a;
}		t_color;

typedef	union	u_union
{
  uint		color;
  t_color	rgb;
}		t_union;

typedef struct	s_camera
{
  double	xo;
  double	yo;
  double	zo;
  double	vx;
  double	vy;
  double	vz;
}		t_camera;

typedef	struct	s_calc
{
  double	a;
  double	b;
  double	c;
  double	d;
  double	k1;
  double	k2;
}		t_calc;

typedef	struct	s_coord
{
  double	xo;
  double	yo;
  double	zo;
  double	vx;
  double	vy;
  double	vz;
  double	k;
}		t_coord;

typedef	struct	s_spot
{
  uint		color;
  double	brill;
  double	power; /* NB: /!\ */
  t_coord	spot;
}		t_spot;

typedef struct	s_ruban
{
  double	a;
  double	b;
  double	c;
  double	d;
  uint		color;
  double	angle;
}		t_ruban;

typedef	struct	s_obj
{
  t_type	type;
  uint		len;
  uint		color;
  double	reflex;
  double	trans;
  double	x;
  double	y;
  double	z;
  int		rx;
  int		ry;
  int		rz;
}		t_obj;

typedef	struct	s_rt
{
  t_coord	coord;
  t_coord	inter;
  t_obj		*obj;
  t_list	*objects;
  t_list	*spots;
  uint		color;
  int		bpp;
  int		size_line;
  int		endian;
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  uchar		*data;
  char		*title;
  uint		size_x;
  uint		size_y;
  uint		aliasing;
}		t_rt;

/* TEST */

void		rt_init_test(t_rt *rt);
/* MK */
t_obj		*rt_mkobj();
t_spot		*rt_mkspot(uint color, double brill, double power);

/* INIT */
t_rt		*rt_init(char *title, uint size_x, uint size_y);
void		rt_init_ray(t_coord *coord, double x, double y);
void		rt_init_reflex(t_coord *inter, t_coord *coord, t_obj *obj);
void		rt_init_trans(t_coord *inter, t_coord *coord, t_obj *obj);
void		rt_init_normal(t_obj *obj, t_coord *coord);

/* LOAD */
/* END_LOAD */
/* MAIN */
void		rt_loop(t_rt *rt);
void		rt_init_loop(t_rt *rt, t_coord *coord, double x, double y);
void		rt_image_loop(t_rt *rt);
/* TOOL */
t_calc		rt_check_obj(t_coord *coord, t_obj *obj);
void		rt_aliasing(t_rt *rt, double x, double y);
void		rt_exit(char *msg);
void		rt_translate(t_coord *coord, t_obj *obj, int i);
void		rt_rotate(t_coord *coord, t_obj *obj, int i);
void		rt_rotate_eyes(t_coord *coord, t_obj *obj);
uint		rt_average(uint *color, int nb);
double		*rt_getnorme(t_obj *obj, t_coord *inter);
double		rt_delta(t_rt *rt, t_calc calc, t_obj *obj);
double		rt_delta_shadow(t_calc calc);
int		rt_ptr_key(int key, t_rt *rt);
int		rt_ptr_mouse(int key, int x, int y, t_rt *rt);
int		rt_ptr_expose(t_rt *rt);
int		rt_pixel_put_to_image(t_rt *rt, int x, int y);
void		putimage(t_rt *rt, t_dispatcher *dispatcher);
/* INTER */
t_calc		rt_inter_sphere(t_obj *obj, t_coord *coord);
t_calc		rt_inter_plan(t_obj *obj, t_coord *coord);
t_calc		rt_inter_cone(t_obj *obj, t_coord *coord);
t_calc		rt_inter_cylinder(t_obj *obj, t_coord *coord);
t_calc		rt_inter_triangle(t_rt *rt, t_obj *obj, t_coord *coord);

/* LIGHT */
uint		rt_light(t_rt *rt, t_spot *spot, double *n);
void		rt_lights(t_rt *rt, t_list *spots);

/* SHADOW */
void		rt_shadow(t_rt *rt, t_coord *inter, t_color *rgb);
void		rt_shadows(t_rt *rt, t_list *spots);

/* REFLEXION */
void		rt_reflex(t_rt *rt, uint color, t_coord *inter, double reflex);

/* TRANSPARENCE */
void		rt_trans(t_rt *rt, uint color, t_coord *inter);

#endif		/* !RT_H_ */
