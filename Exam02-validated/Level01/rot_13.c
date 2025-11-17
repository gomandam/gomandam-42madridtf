/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:36:42 by gomandam          #+#    #+#             */
/*   Updated: 2025/04/11 13:12:19 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$
$>./rot_13 "" | cat -e
$
$>
*/

#include <unistd.h>

int	main(int ac, char *av[])
{
	int	i = 0;
	if (ac != 2) {	write(1, "\n", 2);	return(0); }
	while (av[1][i] != '\0')					//Check ASCII to have fun
	{
		if (av[1][i] >= 'a' && av[1][i] <= 'm' || av[1][i] >= 'A' && av[1][i] <= 'M')
			av[1][i] += 13;
		else if (av[1][i] > 'm' && av[1][i] < '{' || av[1][i] > 'M' && av[1][i] < '[')
			av[1][i] -= 13;
		write(1, &av[1][i++], 1);
	}	
	write(1, "\n", 1);	return (0);	
}
