/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:49:51 by gomandam          #+#    #+#             */
/*   Updated: 2025/04/24 13:17:17 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

#include <unistd.h>

int	main(int ac, char *av[])
{
	if (ac != 2)
		write(1, "\n", 1);
	int	i = 0;
	int	nbr_repeat;
	while (av[1][i] && ac == 2)
	{
		if (av[1][i] >= 'a' && av[1][i] <= 'z')
			nbr_repeat = av[1][i] - 'a' + 1;
		else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			nbr_repeat = av[1][i] - 'A' + 1;
		else
			nbr_repeat = 1;		//else non-alphabet, write once.
		while(nbr_repeat--)		//starts at last count, then backwards until zero.
			write(1, &av[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
}
