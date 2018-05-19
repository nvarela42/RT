/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_rt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 10:51:43 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 21:42:48 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			ft_free_dir(t_rt *rt)
{
	free(rt->xsdfile);
	free(rt->savedir);
	free(rt->newico);
	free(rt->colico);
	free(rt->savico);
	free(rt->dupico);
	free(rt->recico);
	free(rt->antico);
	free(rt->greico);
	free(rt->sepico);
	free(rt->anaico);
	free(rt->bluico);
	free(rt->carico);
	free(rt->deuico);
	free(rt->proico);
	free(rt->triico);
	free(rt->camico);
	free(rt->zikico);
	free(rt->offico);
	free(rt->wd);
	free(rt->openico);
	free(rt->quitico);
	free(rt->ftico);
	ft_free_darray(rt->filemusic);
}

void				ft_free_rt(t_rt *rt)
{
	if (!rt)
		return ;
	if (rt->app)
		g_object_unref(rt->app);
	ft_free_darray(rt->object);
	free(rt->filename);
	free(rt->object_create);
	free(rt->object_init);
	free(rt->object_calc);
	free(rt->object_calc_lum);
	ft_free_dir(rt);
}
