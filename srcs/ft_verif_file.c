/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cstroh <cstroh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 11:14:35 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/14 23:56:19 by cstroh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void				ft_verif_file1(t_rt *rt)
{
	t_stat		sb;

	if (stat(rt->xsdfile, &sb) != 0)
		ft_perror(NULL, TRUE);
	if (stat(rt->savedir, &sb) != 0)
	{
		if (mkdir(ft_glob()->savedir, 0700) == -1)
			ft_perror(NULL, TRUE);
	}
	if (stat(rt->newico, &sb) != 0)
		ft_perror(NULL, TRUE);
	if (stat(rt->colico, &sb) != 0)
		ft_perror(NULL, TRUE);
	if (stat(rt->savico, &sb) != 0)
		ft_perror(NULL, TRUE);
}

static void				ft_verif_file2(t_rt *rt)
{
	t_stat		sb;

	if (stat(rt->recico, &sb) != 0)
		ft_perror(NULL, TRUE);
	if (stat(rt->antico, &sb) != 0)
		ft_perror(NULL, TRUE);
	if (stat(rt->greico, &sb) != 0)
		ft_perror(NULL, TRUE);
	if (stat(rt->sepico, &sb) != 0)
		ft_perror(NULL, TRUE);
	if (stat(rt->anaico, &sb) != 0)
		ft_perror(NULL, TRUE);
	if (stat(rt->bluico, &sb) != 0)
		ft_perror(NULL, TRUE);
	if (stat(rt->offico, &sb) != 0)
		ft_perror(NULL, TRUE);
}

static void				ft_verif_file3(t_rt *rt)
{
	t_stat		sb;

	if (stat(rt->carico, &sb) != 0)
		ft_perror(NULL, TRUE);
	if (stat(rt->deuico, &sb) != 0)
		ft_perror(NULL, TRUE);
	if (stat(rt->proico, &sb) != 0)
		ft_perror(NULL, TRUE);
	if (stat(rt->triico, &sb) != 0)
		ft_perror(NULL, TRUE);
	if (stat(rt->camico, &sb) != 0)
		ft_perror(NULL, TRUE);
	if (stat(rt->zikico, &sb) != 0)
		ft_perror(NULL, TRUE);
	if (stat(rt->filemusic[1], &sb) != 0)
		ft_perror(NULL, TRUE);
	if (stat(rt->openico, &sb) != 0)
		ft_perror(NULL, TRUE);
	if (stat(rt->quitico, &sb) != 0)
		ft_perror(NULL, TRUE);
	if (stat(rt->ftico, &sb) != 0)
		ft_perror(NULL, TRUE);
}

void					ft_verif_file(t_rt *rt)
{
	ft_verif_file1(rt);
	ft_verif_file2(rt);
	ft_verif_file3(rt);
}
