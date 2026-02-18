/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_popen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:06:51 by gomandam          #+#    #+#             */
/*   Updated: 2026/02/18 16:10:13 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int ft_popen(char *f, char *const v[], char t) {
	int p[2], r = t == 'r', i = 0;
	if (!f || !v || (t ^ 'r' && t ^ 'w') || pipe(p) || (i = fork()) < 0)
		return (close(p[0]), close(p[1]), -1);
	if (!i)	{
		dup2(p[r], r);
		close(p[0]);	close(p[1]);
		execvp(f, v);	exit(1);	}
    return (close(p[r]), p[!r]);
}
