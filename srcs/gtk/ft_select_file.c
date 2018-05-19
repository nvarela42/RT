/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 21:14:20 by nvarela           #+#    #+#             */
/*   Updated: 2018/05/14 11:40:33 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void					ft_select_file_3(t_rt *rt, GtkWidget *dialog)
{
	GtkFileChooser			*chooser;

	if ((gtk_dialog_run(GTK_DIALOG(dialog))) == GTK_RESPONSE_ACCEPT)
	{
		chooser = GTK_FILE_CHOOSER(dialog);
		rt->filename = gtk_file_chooser_get_filename(chooser);
	}
}

static void					ft_select_file_2(t_rt *rt)
{
	GtkFileFilter			*filter;
	GtkWidget				*dialog;

	filter = gtk_file_filter_new();
	gtk_file_filter_add_pattern(filter, "*.xml");
	dialog = gtk_file_chooser_dialog_new("Open File", GTK_WINDOW(rt->home),
		GTK_FILE_CHOOSER_ACTION_OPEN, "_Cancel", GTK_RESPONSE_CANCEL, "_Open",
		GTK_RESPONSE_ACCEPT, NULL);
	gtk_file_chooser_set_filter((GtkFileChooser*)dialog, filter);
	ft_select_file_3(rt, dialog);
	gtk_widget_destroy(dialog);
}

void						ft_select_file(gpointer data)
{
	t_rt					*rt;
	int						ret;

	rt = (t_rt*)data;
	if (ft_can_create_scene(rt) == FALSE)
	{
		ft_print_error_xml(rt, "Can't open another scene.");
		return ;
	}
	ft_select_file_2(rt);
	if (rt->filename)
	{
		ret = ft_parse_xml(rt, rt->filename);
		free(rt->filename);
		rt->filename = NULL;
		if (ret != -1)
			ft_run(rt);
	}
}
