/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 23:50:15 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 20:20:47 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "rt_structs.h"

/*
** PROTOTYPES
*/

/*
** PROTOTYPES - RT
*/
void		begin(void) __attribute__((constructor));
void		end(void) __attribute__((destructor));
t_rt		*ft_glob();
void		ft_perror(char *str, t_bool exit_flag);
void		ft_init(int argc, char *str, t_rt *rt);
void		ft_free_rt(t_rt *rt);
int			ft_parse_xml(t_rt *rt, char *filename);
int			ft_print_error_xml(t_rt *rt, const char *err);
void		ft_print_xml_progression(t_rt *rt, char *nodename);
void		ft_create_scene(t_rt *rt, xmlDocPtr doc);
int			ft_validate_schema(xmlDocPtr doc, const char *xsd);
float		ft_atof(char *str);
void		ft_stock_dir(t_rt *rt);
void		ft_verif_file(t_rt *rt);
void		ft_run(t_rt *rt);
void		ft_calc_scene(gpointer data);
void		*ft_run_calc_scene(void *obj);
void		ft_launch_effects(t_thread *th, t_color *color);
void		ft_print_color(t_color *col);
void		ft_print_vector(t_vector *vec);
void		ft_init_dir(t_rt *rt, char *wd);
void		ft_spotlight(t_thread *th, t_lights *light, t_color *col,
			float dot);
void		ft_shiness(t_thread *th, t_lights *light, t_color *col, float dot);
void		ft_init_create(t_rt *rt);
void		ft_fill_object(t_rt *rt);
void		ft_init_calc_lum(t_rt *rt);
t_scene		*ft_get_last_scene(t_scene *scn);
int			ft_can_create_scene(t_rt *rt);
void		ft_create_thread(t_scene *scn);

/*
** PROTOTYPES - CORE
*/
void		ft_raytrace(t_thread *th, int x, t_ray *ray, t_color *col);
void		ft_calc_lum(t_thread *th, t_color *col);
void		ft_search_hit(t_thread *th, t_ray *ray);
void		ft_copy_hit(t_thread *th, t_hit tmp);
void		ft_reflect(t_thread *th, t_ray *ray, t_color *col, int x);
t_vector	ft_refl_for_refract(t_thread *th, t_ray *ray);
void		ft_refr_and_refl(t_thread *th, t_ray *ray, t_color *col,
			int x);
void		ft_fresnel(t_thread *th, t_ray *ray, t_refract *refr);
t_vector	ft_refract(t_thread *th, t_ray *ray, t_refract *refr);
void		ft_init_ray(t_scene *scn, t_ray *ray, int x, int y);
void		ft_ambiante_light(t_thread *th, t_color *col);
void		ft_diffuse_light(t_thread *th, t_lights *light, t_color *col,
			float dot);

/*
** PROTOTYPES - GTK
*/
void		ft_init_home(GtkApplication *app, gpointer data);
void		ft_select_file(gpointer data);
void		ft_launch_scene(t_rt *rt);
void		ft_quit_scene(gpointer data);
void		ft_dup_scn(gpointer data);
void		ft_add_obj(gpointer data);
void		ft_add_button(t_scene *scn);
void		ft_add_button_6(t_scene *scn);
void		ft_save_img(gpointer data);
void		ft_play_sound(gpointer data);
gboolean	ft_key_press(GtkWidget *event_box, GdkEventKey *event,
			gpointer data);
void		put_pixel(t_scene *scn, int x, int y, t_color color);
int			ft_print_error_xml(t_rt *rt, const char *err);
gboolean	ft_sel_object(GtkWidget *event_box, GdkEventButton *event,
			gpointer data);
void		ft_film(gpointer data);
void		ft_change_color(gpointer data);

/*
** PROTOTYPES - CAMERA
*/
void		*ft_create_camera(t_scene *scene);
void		ft_free_camera(t_scene *scene);
void		ft_init_camera(void *obj, xmlNodePtr node, t_scene *scn);
void		ft_copy_camera(t_scene *tmp, t_scene *act);

/*
** PROTOTYPES - LIGHT
*/
void		*ft_create_light(t_scene *scene);
void		ft_free_light(t_scene *scene);
void		ft_init_light(void *obj, xmlNodePtr node, t_scene *scn);
void		ft_copy_light(t_scene *tmp, t_scene *act);

/*
** PROTOTYPES - ANBIANT
*/
void		*ft_create_ambiant(t_scene *scene);
void		ft_init_ambiant(void *obj, xmlNodePtr node, t_scene *scn);
void		ft_free_ambiant(t_scene *scene);
void		ft_copy_ambiant(t_scene *tmp, t_scene *act);

/*
** PROTOTYPES - MATERIA
*/
void		*ft_create_materia(t_scene *scene);
void		ft_free_materia(t_scene *scene);
void		ft_link_mat(t_texture *t, t_materials *mat, t_objects *obj);
t_materials	*ft_get_material(t_materials *material, int i);
void		ft_init_materia(void *obj, xmlNodePtr node, t_scene *scn);
void		ft_copy_materia(t_scene *tmp, t_scene *act);

/*
** PROTOTYPES - OBJECT
*/
void		*ft_create_object(t_scene *scene);
void		ft_free_object(t_scene *scene);
void		ft_no_hit_lum(t_thread *a, t_objects *b, t_ray *c, int *d);
void		ft_no_hit(t_thread *a, t_objects *b, t_ray *c);
void		ft_copy_object(t_scene *tmp, t_scene *act);
void		ft_no_add(t_scene *scn);

/*
** PROTOTYPES - SPHERE
*/
void		ft_init_sphere(void *obj, xmlNodePtr node, t_scene *scn);
void		ft_search_sphere_hit(t_thread *th, t_objects *obj, t_ray *ray);
void		ft_lum_hit_sphere(t_thread *a, t_objects *obj, t_ray *ray,
			int *block);
int			ft_calc_discri_sphere(t_objects *obj, t_ray *ray, t_hit *tmp);
void		ft_sphere_add(t_scene *scn);

/*
** PROTOTYPES - CONE
*/
void		ft_init_cone(void *obj, xmlNodePtr node, t_scene *scn);
void		ft_lum_hit_cone(t_thread *th, t_objects *obj, t_ray *ray,
			int *block);
void		ft_search_cone_hit(t_thread *a, t_objects *obj, t_ray *ray);
int			ft_calc_discri_cone(t_objects *obj, t_ray *ray, t_hit *tmp);
void		ft_cone_add(t_scene *scn);

/*
** PROTOTYPES - CYLINDER
*/
void		ft_init_cylinder(void *obj, xmlNodePtr node, t_scene *scn);
void		ft_search_cylinder_hit(t_thread *th, t_objects *obj, t_ray *ray);
int			ft_calc_discri_cyl(t_objects *obj, t_ray *ray, t_hit *tmp);
void		ft_lum_hit_cyl(t_thread *a, t_objects *obj, t_ray *ray, int *block);
void		ft_cylinder_add(t_scene *scn);
/*
** PROTOTYPES - PLANE
*/
void		ft_init_plane(void *obj, xmlNodePtr node, t_scene *scn);
void		ft_search_plane_hit(t_thread *th, t_objects *obj, t_ray *ray);
void		ft_lum_hit_plane(t_thread *a, t_objects *obj, t_ray *ray,
			int *block);
int			ft_calc_discri_plane(t_objects *obj, t_ray *ray, t_hit *tmp);
void		ft_plane_add(t_scene *scn);

/*
** PROTOTYPES - TRIANGLE
*/
void		ft_search_triangle_hit(t_thread *th, t_objects *obj, t_ray *ray);
void		ft_lum_hit_tri(t_thread *th, t_objects *obj, t_ray *ray,
			int *block);
void		ft_init_triangle(void *obj, xmlNodePtr node, t_scene *scn);
int			ft_calc_discri_tri(t_objects *obj, t_ray *ray, t_hit *tmp);

/*
** PROTOTYPES - CUBE
*/
void		ft_init_cube(void *obj, xmlNodePtr node, t_scene *scn);
void		ft_add_edges(t_objects *cube, t_scene *scn);

/*
** PROTOTYPES - VECTOR
*/
void		ft_create_vector(t_vector *vec, xmlAttrPtr attr);
void		ft_div_vector(t_vector *dest, t_vector *vector, float val);
void		ft_mult_num_vector(t_vector *dest, t_vector *a, int i);
void		ft_plus_vector(t_vector *dest, t_vector *a, t_vector *b);
void		ft_mult_vector(t_vector *dest, t_vector *a, t_vector *b);
void		ft_moins_vector(t_vector *dest, t_vector *a, t_vector *b);
void		ft_vector_normalize(t_vector *vector);
float		ft_vector_magnitude(t_vector *vector);
float		ft_vector_square_len(t_vector *vector);
float		ft_vector_dot_mult(t_vector *a, t_vector *b);
void		ft_vector_init(t_vector *vec);
void		ft_rotation(t_vector *vec, t_vector rot);
t_vector	ft_rotation_cylinder_init(void);
float		ft_calc_angle(float rot);
void		ft_copy_vector(t_vector *src, t_vector *dest);

/*
** PROTOTYPES - MATH
*/
void		ft_swap(float *t1, float *t2);
float		ft_clamp(float min, float max, float value);
float		ft_max(float v1, float v2);

/*
** PROTOTYPES - COLOR
*/
void		ft_create_color(t_color *color, xmlAttrPtr attr);
void		ft_color_init(t_color *color);
t_color		ft_get_object_color(t_thread *th);
void		ft_copy_color(t_color *src, t_color *dest);

/*
** PROTOTYPES - TEXTURE
*/
void		ft_bump_mapping(t_thread *th);
int			*ft_init_perlin(void);
void		ft_free_perlin(t_scene *scn);
float		ft_noise(t_thread *th, t_vector pos);
t_color		get_pixel_color(GdkPixbuf *pixbuf, int x, int y);
void		*ft_create_texture(t_scene *scene);
void		ft_init_texture(void *obj, xmlNodePtr node, t_scene *scene);
void		ft_load_texture(t_texture *t, char *name);
t_color		ft_get_pixel_texture(t_thread *th, t_texture *t);
void		ft_free_texture(t_scene *scn);
void		ft_copy_texture(t_scene *tmp, t_scene *act);

/*
** PROTOTYPES - EFFECTS
*/
void		ft_init_effects(t_scene *scn);
void		ft_greyscale(gpointer data);
void		ft_set_greyscale(t_color *color);
void		ft_sepia(gpointer data);
void		ft_set_sepia(t_color *color);
void		ft_cartoon(gpointer data);
void		ft_set_cartoon(t_color *color);
void		ft_reset_effects(t_color *color);
void		ft_anaglyph(gpointer data);
void		ft_mix_color(t_color *red, t_color *cyan, t_color *mix);
void		ft_deuteranopia(gpointer data);
void		ft_set_deuteranopia(t_color *color);
void		ft_protanopia(gpointer data);
void		ft_set_protanopia(t_color *color);
void		ft_tritanopia(gpointer data);
void		ft_set_tritanopia(t_color *color);
void		ft_text_effects(t_scene *scn);
void		ft_default_colors(gpointer data);
void		ft_motion_blur(gpointer data);
void		ft_antialiasing(gpointer data);

#endif
