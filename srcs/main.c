/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 23:39:36 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 20:53:48 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				begin(void)
{
	ft_glob();
}

int					main(int argc, char **argv)
{
	ft_init(argc, argv[0], ft_glob());
	g_application_run(G_APPLICATION(ft_glob()->app), argc, argv);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void				end(void)
{
	t_rt			*rt;

	if ((rt = ft_glob()) != NULL)
	{
		if (rt->musicpid != -1)
		{
			kill(rt->musicpid, SIGQUIT);
			rt->musicpid = -1;
		}
		ft_free_rt(rt);
	}
}
