/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 10:50:43 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 15:32:39 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			ft_get_pwd(t_rt *rt, char *str)
{
	int				len;

	len = ft_strlen(str) - 1;
	while (len <= 0 || str[len] != '/')
		len--;
	if (str[len] != '/')
		ft_perror("Can't estabitch working directory.", TRUE);
	if ((rt->wd = ft_strndup(str, len + 1)) == NULL)
		ft_perror(NULL, TRUE);
}

static void			ft_usage(void)
{
	ft_putendl_fd("Usage:\n./rt", 2);
	exit(EXIT_FAILURE);
}

static void			ft_init_object_2(t_rt *rt)
{
	int				len;

	len = ft_size_darray(rt->object);
	if ((rt->object_create =
		(t_obj_new**)malloc(sizeof(t_obj_new*) * len)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->object_init =
		(t_obj_ini**)malloc(sizeof(t_obj_ini*) * len)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->object_calc =
		(t_obj_calc**)malloc(sizeof(t_obj_calc*) * len)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->object_calc_lum =
		(t_obj_calc_lum**)malloc(sizeof(t_obj_calc_lum*) * len)) == NULL)
		ft_perror(NULL, TRUE);
}

static void			ft_init_object(t_rt *rt)
{
	char			**tmp;
	int				i;

	if ((rt->object = ft_strsplit_trim(OBJ, ';')) == NULL)
		ft_perror(NULL, TRUE);
	if ((tmp = ft_strsplit_trim(OBJ2, ';')) == NULL)
		ft_perror(NULL, TRUE);
	i = 0;
	while (tmp[i] != NULL)
	{
		if ((rt->object = ft_add_in_darray(rt->object, tmp[i])) == NULL)
		{
			ft_free_darray(tmp);
			ft_perror(NULL, TRUE);
		}
		i++;
	}
	ft_free_darray(tmp);
	ft_init_object_2(rt);
}

void				ft_init(int argc, char *str, t_rt *rt)
{
	if (argc != 1)
		ft_usage();
	ft_get_pwd(rt, str);
	ft_stock_dir(rt);
	ft_verif_file(rt);
	ft_init_object(rt);
	ft_init_create(rt);
	ft_fill_object(rt);
	ft_init_calc_lum(rt);
	rt->app = gtk_application_new(NULL, G_APPLICATION_FLAGS_NONE);
	g_signal_connect(rt->app, "activate", G_CALLBACK(ft_init_home), rt);
}
