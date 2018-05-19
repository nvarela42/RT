# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 14:37:40 by nvarela           #+#    #+#              #
#    Updated: 2018/05/15 17:00:52 by nvarela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang

NAME		=	rt

LNAME		=	ft

DIR			=	lib$(LNAME)

HDR			=	$(DIR)/$(DIR).a

HEADER 		=	./includes/rt.h								\
				./includes/rt_includes.h					\
				./includes/rt_structs.h

SRC			=	main.c										\
				ft_glob.c									\
				ft_perror.c									\
				ft_init.c									\
				ft_init_bis.c								\
				ft_free_rt.c								\
				ft_parse_xml.c								\
				ft_parse_xml_bis.c							\
				ft_validate_schema.c						\
				ft_atof.c									\
				ft_stock_dir.c								\
				ft_verif_file.c								\
				ft_run.c									\
				ft_calc_scene.c								\
				ft_calc_scene_bis.c							\
				ft_launch_effects.c							\
				ft_can_create_scene.c						\

# CAMERA PART
SRC			+=	camera/ft_create_camera.c					\
				camera/ft_free_camera.c						\
				camera/ft_init_camera.c						\
				camera/ft_copy_camera.c						\

# LIGHT PART
SRC			+=	lights/ft_create_light.c					\
				lights/ft_free_light.c						\
				lights/ft_init_light.c						\
				lights/ft_copy_light.c						\


# AMBIANT - PART
SRC			+=	ambiant/ft_create_ambiant.c					\
				ambiant/ft_init_ambiant.c					\
				ambiant/ft_free_ambiant.c					\
				ambiant/ft_copy_ambiant.c					\

# MATERIA PART
SRC			+=	materias/ft_create_materia.c				\
				materias/ft_free_materia.c					\
				materias/ft_init_materia.c					\
				materias/ft_link_mat.c						\
				materias/ft_copy_materia.c					\

# OBJECT PART
SRC			+=	objects/ft_create_object.c					\
				objects/ft_free_object.c					\
				objects/ft_no_hit.c							\
				objects/ft_no_lum_object.c					\
				objects/ft_copy_object.c					\
				objects/ft_no_add.c							\


# SPHERE PART
SRC			+=	objects/sphere/ft_init_sphere.c				\
				objects/sphere/ft_search_sphere_hit.c		\
				objects/sphere/ft_calc_discrimant_sphere.c	\
				objects/sphere/ft_sphere_add.c				\


# CONE PART
SRC			+=	objects/cone/ft_init_cone.c					\
				objects/cone/ft_search_cone_hit.c			\
				objects/cone/ft_calc_discrimant_cone.c		\
				objects/cone/ft_cone_add.c					\

# CYLINDER PART
SRC			+=	objects/cylinder/ft_init_cylinder.c			\
				objects/cylinder/ft_search_cylinder_hit.c	\
				objects/cylinder/ft_calc_discrimant_cyl.c	\
				objects/cylinder/ft_cylinder_add.c			\

# PLANE PART
SRC			+=	objects/plane/ft_init_plane.c				\
				objects/plane/ft_search_plane_hit.c			\
				objects/plane/ft_calc_discrimant_plane.c	\
				objects/plane/ft_plane_add.c				\

# TRIANGLE PART
SRC			+=	objects/triangle/ft_init_triangle.c			\
				objects/triangle/ft_search_triangle_hit.c	\
				objects/triangle/ft_calc_discrimant_triangle.c	\

# CUBE PART
SRC			+=	objects/cube/ft_init_cube.c					\
				objects/cube/ft_init_cube_bis.c				\

# VECTOR PART
SRC			+=	vector/ft_vector_init.c						\
				vector/ft_calc_on_vector.c					\
				vector/ft_create_vector.c					\
				vector/ft_vector_misc.c						\
				vector/ft_rotation.c						\
				vector/ft_copy_vector.c						\

# MATH PART
SRC			+=	math/ft_math.c								\

# COLOR PART
SRC			+=	color/ft_color_init.c						\
				color/ft_create_color.c						\
				color/ft_object_color.c						\
				color/ft_copy_color.c						\

# TEXTURE PART
SRC			+=	texture/ft_bump.c							\
				texture/ft_perlin.c							\
				texture/ft_init_perlin.c					\
				texture/ft_create_texture.c					\
				texture/ft_init_texture.c					\
				texture/ft_free_texture.c					\
				texture/ft_texture_utils.c					\
				texture/ft_load_texture.c					\
				texture/ft_copy_texture.c					\


# EFFECTS PART
SRC 		+=  effects/ft_greyscale.c						\
				effects/ft_sepia.c							\
				effects/ft_cartoon.c						\
				effects/ft_anaglyph.c						\
				effects/ft_anaglyph_bis.c					\
				effects/ft_deuteranopia.c					\
				effects/ft_protanopia.c						\
				effects/ft_tritanopia.c						\
				effects/ft_text_effects.c					\
				effects/ft_default_colors.c					\
				effects/ft_motion_blur.c					\
				effects/ft_antialiasing.c					\
				effects/ft_init_effects.c					\

# CORE PART
SRC			+=	core/ft_search_hit.c						\
				core/ft_raytrace.c							\
				core/ft_calc_lum.c							\
				core/ft_copy_hit.c							\
				core/ft_reflect.c							\
				core/ft_refract.c							\
				core/ft_type_light.c						\

# GTK PART
SRC			+=	gtk/ft_init_home.c							\
				gtk/ft_select_file.c						\
				gtk/ft_launch_scene.c						\
				gtk/ft_quit_scene.c							\
				gtk/ft_dup_scn.c							\
				gtk/ft_add_obj.c							\
				gtk/ft_add_button.c							\
				gtk/ft_add_button_bis.c						\
				gtk/ft_save_img.c							\
				gtk/ft_play_sound.c							\
				gtk/ft_key_press.c							\
				gtk/ft_sel_object.c							\
				gtk/ft_film.c								\
				gtk/ft_change_color.c						\

OBJ			=	$(patsubst %.c,srcs/%.o,$(SRC))

LFLAGS		=	-L$(DIR) -l$(LNAME) -lm $(shell pkg-config --libs gtk+-3.0) -lpthread

LFLAGS		+=	 -lxml2

WFLAGS 		=	-Wall -Wextra -Werror -O

CFLAGS1		=	$(WFLAGS) -I./includes/ -I$(DIR)/includes -I/usr/include/libxml2/ $(shell pkg-config --cflags gtk+-3.0)

OFLAGS		=	 -g #-fsanitize=address

CFLAGS		= 	$(CFLAGS1) $(OFLAGS)

all:		$(HDR) $(NAME)

$(NAME):	$(HDR) $(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)
			@echo "[\033[32m✔\033[0m] $@"

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c -o $@ $<
		@echo "[\033[32m✔\033[0m] $@"

$(DIR): $(HDR)

$(HDR):
		make -C $(DIR)

clean:
		make -C $(DIR) clean
		rm -f $(OBJ)

fclean:		clean
		make -C $(DIR) fclean
		rm -f $(NAME) $(HDR)

re:		fclean all

.PHONY: all clean fclean re
