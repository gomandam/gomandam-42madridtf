/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_popen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 00:17:28 by gomandam          #+#    #+#             */
/*   Updated: 2026/02/26 00:22:38 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const argv[], char type)
{
	int	fd[2];
	int	r = type == 'r';
	int	pid = 0;

	if (!file || !argv || (type ^ 'r' && type ^ 'w') || pipe(fd) || (pid = fork()) < 0)
		return (close(fd[0]), close(fd[1]), -1);
	if (!pid)
	{
		dup2(fd[r], r);
		close(fd[0]);
		close(fd[1]);
		execvp(file, argv);
		exit(1);
	}
	close(fd[r]);
	return (fd[!r]);
}
