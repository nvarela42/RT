/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 23:46:55 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 21:59:27 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCTS_H
# define RT_STRUCTS_H

# include "rt_includes.h"

/*
** TYPEDEF
*/

/*
** TYPEDEF - RT
*/
typedef struct s_vector				t_vector;
typedef struct s_color				t_color;
typedef struct s_camera				t_camera;
typedef struct s_objects			t_objects;
typedef struct s_materials			t_materials;
typedef struct s_lights				t_lights;
typedef struct s_ambiant			t_ambiant;
typedef struct s_scene_win			t_scene_win;
typedef struct s_scene				t_scene;
typedef struct s_rt					t_rt;
typedef struct s_ray				t_ray;
typedef struct s_hit				t_hit;
typedef struct s_tmp_obj			t_tmp_obj;
typedef struct stat					t_stat;
typedef struct rlimit				t_rlimit;
typedef struct s_refract			t_refract;
typedef struct s_thread				t_thread;
typedef struct s_vects				t_vects;
typedef struct s_texture			t_texture;
typedef struct s_progress			t_progress;
typedef void						*(t_obj_new)(t_scene*);
typedef void						(t_obj_ini)(void*, xmlNodePtr, t_scene*);
typedef void						(t_obj_calc)(t_thread*, t_objects*,
									t_ray*);
typedef void						(t_obj_calc_lum)(t_thread*, t_objects*,
									t_ray*, int*);

/*
** STRUCT
*/
struct								s_progress
{
	float							max;
	float							current;
};

struct								s_texture
{
	int								id;
	int								type;
	int								w;
	int								h;
	int								sw;
	int								sh;
	int								ow;
	int								oh;
	GdkPixbuf						*data;
	struct s_texture				*next;
};

struct								s_vector
{
	float							x;
	float							y;
	float							z;
};

struct								s_vects
{
	t_vector						a;
	t_vector						b;
	t_vector						c;
};

struct								s_color
{
	float							r;
	float							g;
	float							b;
};

struct								s_ray
{
	t_vector						start_pos;
	t_vector						dir;
	float							dist;
};

struct								s_tmp_obj
{
	float							a;
	float							b;
	float							c;
	float							dot_dir;
	t_vector						ab;
	t_vector						ac;
	t_vector						dir;
	t_vector						cross;
	float							u;
	float							v;
	float							delta;
	t_vector						normal;
	t_objects						*obj;
	t_ray							*ray;
	t_hit							*hit;
};

struct								s_objects
{
	int								type;
	t_vector						pos;
	float							radius;
	float							size;
	t_objects						*tri_cube;
	float							limit_pos;
	float							limit_neg;
	t_vector						rotation;
	t_vector						normal;
	t_vector						translation;
	t_vector						edge_a;
	t_vector						edge_b;
	t_vector						edge_c;
	t_vector						edge_d;
	t_vector						edge_e;
	t_vector						edge_f;
	t_vector						edge_g;
	t_vector						edge_h;
	t_vector						pos_edge1;
	t_vector						pos_edge2;
	t_vector						pos_edge3;
	int								material_id;
	int								material_id1;
	int								material_id2;
	int								material_id3;
	int								material_id4;
	int								material_id5;
	int								texture_id;
	t_materials						*material;
	t_objects						*next;
};

struct								s_lights
{
	t_vector						pos;
	t_color							light_color;
	float							radius;
	int								spot;
	float							rad_spot;
	float							intensity;
	t_lights						*next;
};

struct								s_materials
{
	int								material_id;
	t_color							material_color;
	int								texture_id;
	int								normal_id;
	float							shiness;
	float							reflect;
	float							refract;
	t_texture						*texture;
	t_texture						*normal;
	float							bump;
	t_materials						*next;
};

struct								s_camera
{
	t_vector						pos;
	t_vector						lookat;
	t_vector						up;
	t_vector						sav_up;
	t_vector						dir;
	t_vector						right;
	t_vector						up_left;
	float							dist;
	float							viewport_w;
	float							viewport_h;
	int								size_x;
	int								size_y;
};

struct								s_scene_win
{
	int								recalc;
	GtkWidget						*win;
	GtkWidget						*vbox;
	GtkWidget						*toolbar;
	GtkWidget						*event_box;
	GtkWidget						*view;
	GdkPixbuf						*pixbuf;
	GtkWidget						*window_add;
	int								n_channels;
	int								rowstride;
	guchar							*pixels;
	GtkWidget						*status;
	char							*status_mess;
	GdkPixbuf						*red_pixbuf;
	int								n_channels_2;
	int								rowstride_2;
	guchar							*pixels_2;
};

struct								s_hit
{
	int								touch;
	int								is_light;
	t_objects						*object;
	t_vector						inter;
	t_vector						normal;
	t_materials						*material;
};

struct								s_thread
{
	pthread_t						id;
	t_scene							*scn;
	int								keep_hit;
	int								y1;
	int								iter;
	t_hit							hit;
	int								debug;
	int								has_aliasing;
	int								has_blur;
};

struct								s_scene
{
	t_scene_win						*scene;
	t_camera						*camera;
	t_objects						*objects;
	t_materials						*materials;
	t_texture						*textures;
	int								antialiasing;
	int								greyscale;
	int								sepia;
	int								anaglyph;
	int								cartoon;
	int								motionblur;
	int								deuteranopia;
	int								protanopia;
	int								tritanopia;
	int								defcolors;
	pthread_t						pid_rec;
	t_lights						*lights;
	t_ambiant						*ambiant;
	t_thread						thread[MAXTHREAD];
	t_objects						*sel_obj;
	char							*vid_dir;
	int								vid;
	int								order;
	char							**listfile;
	t_scene							*prev;
	t_scene							*next;
	int								*perlin_permutation;
	GtkWidget						*radio1;
	GtkWidget						*radio2;
	GtkWidget						*radio3;
	GtkWidget						*radio4;
	GtkWidget						*radio5;
	GtkWidget						*radio6;
};

struct								s_refract
{
	t_ray							*ray_refr;
	t_ray							*ray_refl;
	t_color							color;
	t_color							*final_col;
	float							r_sin;
	float							t_sin;
	float							r_cos;
	float							t_cos;
	float							r_eta;
	float							t_eta;
	float							eta;
	float							ret;
	int								out;
	t_vector						*bias;
};

struct								s_rt
{
	GtkApplication					*app;
	t_progress						progress;
	GError							*error;
	char							*filename;
	GtkWidget						*home;
	t_scene							*scenes;
	char							**object;
	t_obj_new						**object_create;
	t_obj_ini						**object_init;
	t_obj_calc						**object_calc;
	t_obj_calc_lum					**object_calc_lum;
	char							*openico;
	char							*quitico;
	char							*ftico;
	char							*xsdfile;
	char							*savedir;
	char							*newico;
	char							*colico;
	char							*savico;
	char							*recico;
	char							*antico;
	char							*greico;
	char							*sepico;
	char							*anaico;
	char							*bluico;
	char							*carico;
	char							*deuico;
	char							*proico;
	char							*triico;
	char							*offico;
	char							*dupico;
	char							*camico;
	char							*zikico;
	char							**filemusic;
	char							*wd;
	int								musicon;
	int								musicpid;
	int								prevmusic;
};

struct								s_ambiant
{
	t_color							color;
};
/*
** GLOBALES
*/

#endif
