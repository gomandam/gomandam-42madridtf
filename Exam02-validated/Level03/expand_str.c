/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:04:13 by gomandam          #+#    #+#             */
/*   Updated: 2025/05/21 19:24:00 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
$>
*/

/*
#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	word = 0;

	if (ac == 2)
	{
		while (av[1][i] == 32 || av[1][i] == 9)
			i++;
		while (av[1][i])
		{
			if (av[1][i] != 32 && av[1][i] != 9)
			{
				if (word)
					write(1, "   ", 3);
				while (av[1][i] && av[1][i] != 32 && av[1][i] != 9)
					write(1, &av[1][i++], 1);
				word = 1;
			}
			else	i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

*/

#include <unistd.h>

int	main(int ac, char **av)
{
	char	*s = av[1];
	int	word = 0;

	if (ac == 2)
	{
		while (*s == 32 || *s == 9)
			s++;
		while (*s)
		{
			if (*s != 32 && *s != 9)
			{
				if (word)
					write(1, "   ", 3);
				while (*s && *s != 32 && *s != 9)
					write(1, s++, 1);
				word = 1;
			}
			else
				s++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
