/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:07:20 by gomandam          #+#    #+#             */
/*   Updated: 2025/05/21 21:30:38 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>

int     ft_atoi(char *s)
{
	int	n = 0;
	while (*s >= '0' && *s <= '9')
		n = n * 10 + (*s++ - '0');
	return (n);
}

void	putnbr(int n)
{
	char nbr[] ="0123456789";
	
	if (n >= 10)
		putnbr(n / 10);
	write(1, &nbr[n % 10], 1);
}

int	prime(int nbr)
{
	int	check = 2;

	if (nbr <= 1)
		return (0);
	while (check < nbr)
	{
		if ((nbr % check) == 0)
			return (0);
		check++;
	}
	return (1);
}

int	add_prime(int nbr)
{
	int	idx = 2;
	int	sum = 0;

	if (nbr <= 0)
		return (0);
	while (idx <= nbr)
	{
		if (prime(idx))
			sum += idx;
		idx++;
	}
	return (sum);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		putnbr(add_prime(ft_atoi((av[1]))));
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
