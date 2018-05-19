/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 23:12:59 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 11:03:25 by vmontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		ft_init_filemusic(t_rt *rt, char **array)
{
	int			i;
	int			err;

	i = 0;
	while (i < 3)
	{
		rt->filemusic[i] = NULL;
		i++;
	}
	if ((rt->filemusic[0] = ft_strdup(array[0])) == NULL)
	{
		err = errno;
		ft_free_darray(array);
		errno = err;
		ft_perror(NULL, TRUE);
	}
	if ((rt->filemusic[1] = ft_strjoin(rt->wd, array[1], 3)) == NULL)
	{
		err = errno;
		ft_free_darray(array);
		errno = err;
		ft_perror(NULL, TRUE);
	}
}

static void		ft_stock_dir2(t_rt *rt)
{
	if ((rt->dupico = ft_strjoin(rt->wd, DUPICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->greico = ft_strjoin(rt->wd, GREICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->antico = ft_strjoin(rt->wd, ANTICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->sepico = ft_strjoin(rt->wd, SEPICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->anaico = ft_strjoin(rt->wd, ANAICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->bluico = ft_strjoin(rt->wd, BLUICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->carico = ft_strjoin(rt->wd, CARICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->deuico = ft_strjoin(rt->wd, DEUICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
}

static void		ft_stock_dir3(t_rt *rt)
{
	char		**array;
	int			err;

	if ((rt->proico = ft_strjoin(rt->wd, PROICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->triico = ft_strjoin(rt->wd, TRIICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->offico = ft_strjoin(rt->wd, OFFICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->camico = ft_strjoin(rt->wd, CAMICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->zikico = ft_strjoin(rt->wd, ZIKICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((array = ft_strsplit(MUSICPARAM, ';')) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->filemusic = (char **)malloc(sizeof(char *) * 3)) == NULL)
	{
		err = errno;
		ft_free_darray(array);
		errno = err;
		ft_perror(NULL, TRUE);
	}
	ft_init_filemusic(rt, array);
	ft_free_darray(array);
}

static void		ft_stock_dir1(t_rt *rt)
{
	if ((rt->xsdfile = ft_strjoin(rt->wd, XSDFILE, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->savedir = ft_strjoin(rt->wd, SAVEDIR, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->newico = ft_strjoin(rt->wd, NEWICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->savico = ft_strjoin(rt->wd, SAVICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->colico = ft_strjoin(rt->wd, COLICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->recico = ft_strjoin(rt->wd, RECICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
}

void			ft_stock_dir(t_rt *rt)
{
	if ((rt->openico = ft_strjoin(rt->wd, OPENICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->quitico = ft_strjoin(rt->wd, QUITICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
	if ((rt->ftico = ft_strjoin(rt->wd, FTICO, 3)) == NULL)
		ft_perror(NULL, TRUE);
	ft_stock_dir1(rt);
	ft_stock_dir2(rt);
	ft_stock_dir3(rt);
}
