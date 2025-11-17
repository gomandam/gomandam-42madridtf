/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 03:03:36 by gomandam          #+#    #+#             */
/*   Updated: 2025/05/10 04:22:43 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		int end = 0;
		int start = 0;
		
		while (av[1][i])
			i++;
        	while (i > 0 && (av[1][i - 1] == ' ' || av[1][i - 1] == '\t'))
            		i--;
		end = i - 1;
		while (i > 0 && av[1][i - 1] != ' ' && av[1][i - 1] != '\t')
			i--;
		start = i;
		if (start <= end)
		{
			while (start <= end)
				write(1, &av[1][start++], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
