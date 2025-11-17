/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 23:32:07 by gomandam          #+#    #+#             */
/*   Updated: 2025/04/03 00:39:59 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_putstr
Expected files   : ft_putstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that displays a string on the standard output.

The pointer passed to the function contains the address of the string's first
character.

Your function must be declared as follows:

void	ft_putstr(char *str);
*/

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	fd;	//file descriptor, standard output in terminal = 1. 
	int	i;

	fd = 1;
	i = 0;
	while (str[i] != '\0')
		write(fd, &str[i++], 1);
}
/*
int	main(void)
{
	char	*s1;

	s1 = "print in the terminal.\n";
	ft_putstr(s1);
	return (0);
}
*/
