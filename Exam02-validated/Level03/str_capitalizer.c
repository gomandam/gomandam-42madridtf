/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:03:15 by gomandam          #+#    #+#             */
/*   Updated: 2025/05/21 17:31:21 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>
*/

#include <unistd.h>

void	str_cap(char *s)
{
	int	i = 0;
	int	new_word = 1;
	char	c;

	while (s[i])
	{
		c = s[i];
		if (c >= 65 && c <= 90)
			c += 32;
		if (c >= 97 && c <= 122 && new_word)
			c -= 32;
		new_word = (c == 32 || c == 9);
		write(1, &c, 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i = 1;

	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (i < ac)
	{
		str_cap(av[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
