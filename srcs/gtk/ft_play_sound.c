/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_sound.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 14:14:07 by agoomany          #+#    #+#             */
/*   Updated: 2018/05/15 20:56:00 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			ft_play_sound(gpointer data)
{
	pid_t		pid;
	char		**file;

	(void)data;
	file = NULL;
	if (ft_glob()->musicpid != -1)
	{
		kill(ft_glob()->musicpid, SIGQUIT);
		ft_glob()->musicpid = -1;
	}
	else
	{
		if ((pid = fork()) < 0)
			ft_perror(NULL, FALSE);
		if (pid > 0)
			ft_glob()->musicpid = pid;
		else if (pid == 0)
		{
			execvp("afplay", ft_glob()->filemusic);
			ft_perror(NULL, TRUE);
		}
	}
}
