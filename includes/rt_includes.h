/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_includes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 23:44:45 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 17:31:20 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_INCLUDES_H
# define RT_INCLUDES_H

/*
** INCLUDES
*/
# include <sys/types.h>
# include <sys/resource.h>
# include <sys/stat.h>
# include <errno.h>
# include <pthread.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <float.h>
# include <gtk/gtk.h>
# include <libxml/xmlreader.h>
# include <gdk-pixbuf/gdk-pixbuf.h>
# include "libft.h"

/*
** DEFINE
*/
# define XSDFILE "./scenes/xsd/validator.xsd"
# define OBJ "camera;sphere;plane;cylinder;cone;triangle;cube;materia;light"
# define OBJ2 "ambiant;texture"
# define SAVEDIR "./save/"
# define VIDDIR "./videos/"
# define DEFAULT_DISTANCE 999999
# define MAXTHREAD 960
# define OPENICO "./misc/img/open.png"
# define QUITICO "./misc/img/quit.png"
# define FTICO "./misc/img/icon.png"
# define BLUR 20
# define MULT 2
# define NEWICO "./misc/img/document-new.png"
# define COLICO "./misc/img/drop.png"
# define SAVICO "./misc/img/document-save.png"
# define DUPICO "./misc/img/edit-copy.png"
# define RECICO "./misc/img/record.png"
# define ANTICO "./misc/img/effect/antialia.png"
# define GREICO "./misc/img/effect/greyscale.png"
# define SEPICO "./misc/img/effect/sepia.png"
# define ANAICO "./misc/img/effect/anaglyph.png"
# define BLUICO "./misc/img/effect/motionblur.png"
# define CARICO "./misc/img/effect/cartoon.png"
# define DEUICO "./misc/img/colors/deuteranopia.png"
# define PROICO "./misc/img/colors/protanopia.png"
# define TRIICO "./misc/img/colors/tritanopia.png"
# define OFFICO "./misc/img/colors/normal.png"
# define CAMICO "./misc/img/camera.png"
# define ZIKICO "./misc/img/music.png"
# define MUSICPARAM "afplay;./misc/sound/sound.mp3"
# define EPSILON 0.0000001
# define MAXSCENE 5
# define DEFAULTMOUV 0.05

#endif
