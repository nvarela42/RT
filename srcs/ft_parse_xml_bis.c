/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_xml_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 18:34:07 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/15 22:00:55 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		ft_create_scene_2(t_scene *tmp)
{
	tmp->scene = NULL;
	tmp->camera = NULL;
	tmp->objects = NULL;
	tmp->materials = NULL;
	tmp->textures = NULL;
	tmp->lights = NULL;
	tmp->ambiant = NULL;
	tmp->perlin_permutation = NULL;
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->sel_obj = NULL;
	tmp->pid_rec = 0;
}

void			ft_create_scene(t_rt *rt, xmlDocPtr doc)
{
	t_scene			*tmp;
	t_scene			*cur;

	if ((tmp = (t_scene*)malloc(sizeof(t_scene))) == NULL)
	{
		xmlFreeDoc(doc);
		ft_perror(NULL, TRUE);
	}
	ft_bzero(tmp, sizeof(t_scene));
	ft_create_scene_2(tmp);
	rt->progress.max = 0;
	rt->progress.current = 0;
	tmp->greyscale = 0;
	cur = rt->scenes;
	if (!cur)
		rt->scenes = tmp;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = tmp;
		tmp->prev = cur;
	}
}

void			ft_print_xml_progression(t_rt *rt, char *nodename)
{
	ft_putstr_fd("[", 1);
	ft_putnbr_fd(rt->progress.current, 1);
	ft_putstr_fd("/", 1);
	ft_putnbr_fd(rt->progress.max, 1);
	ft_putstr_fd("]", 1);
	ft_putchar_fd('\t', 1);
	ft_putendl_fd(nodename, 1);
}

int				ft_print_error_xml(t_rt *rt, const char *err)
{
	GtkWidget	*dialog;

	dialog = NULL;
	dialog = gtk_message_dialog_new(GTK_WINDOW(rt->home),
		GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "%s",
		err);
	gtk_window_set_title(GTK_WINDOW(dialog), "Error");
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
	return (-1);
}
