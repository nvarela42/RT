/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 10:52:28 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 11:15:56 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void						ft_init_file_bis(t_rt *rt)
{
	rt->anaico = NULL;
	rt->bluico = NULL;
	rt->carico = NULL;
	rt->deuico = NULL;
	rt->proico = NULL;
	rt->triico = NULL;
	rt->offico = NULL;
	rt->camico = NULL;
	rt->zikico = NULL;
	rt->musicon = 0;
	rt->filemusic = NULL;
	rt->musicpid = -1;
	rt->prevmusic = 0;
}

static void						ft_init_file(t_rt *rt)
{
	rt->openico = NULL;
	rt->quitico = NULL;
	rt->ftico = NULL;
	rt->xsdfile = NULL;
	rt->savedir = NULL;
	rt->newico = NULL;
	rt->colico = NULL;
	rt->savico = NULL;
	rt->dupico = NULL;
	rt->recico = NULL;
	rt->antico = NULL;
	rt->greico = NULL;
	rt->sepico = NULL;
	ft_init_file_bis(rt);
}

t_rt							*ft_glob(void)
{
	static t_rt					*rt = NULL;
	static int					count = 0;

	if (!count)
	{
		count++;
		if ((rt = (t_rt*)malloc(sizeof(t_rt))) == NULL)
			ft_perror(NULL, TRUE);
		rt->app = NULL;
		rt->error = NULL;
		rt->filename = NULL;
		rt->home = NULL;
		rt->scenes = NULL;
		rt->object = NULL;
		rt->object_create = NULL;
		rt->object_init = NULL;
		rt->object_calc = NULL;
		rt->object_calc_lum = NULL;
		ft_init_file(rt);
	}
	return (rt);
}
