/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 23:04:23 by gomandam          #+#    #+#             */
/*   Updated: 2025/05/22 09:45:01 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/

#include <unistd.h>

void	ft_putstr(char *start, char *end)
{
	while (start < end)
		write(1, start++, 1);
}

int	main(int ac, char **av)
{
	char	*str;
	char	*start;
	char	*end;
	int		has_printed = 0;

	if (ac > 1)
	{
		str = av[1];
		while (*str == 32 || *str == 9)
			str++;
		start = str;
		while (*str && *str != 32 && *str != 9)
			str++;
		end = str;
		while (*str == 32 || *str == 9)
			str++;
		while (*str)
		{
			if (*str == 32 || *str == 9)
			{
				while (*str == 32 || *str == 9)
					str++;
				if (*str)
					write(1, " ", 1);
			}
			else
			{
				has_printed = 1;
				write(1, str++, 1);
			}
		}
		if (start < end)
		{
			if (has_printed)
				write(1, " ", 1);
			ft_putstr(start, end);
		}
	}
	write(1, "\n", 1);
	return (0);
}
