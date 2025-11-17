/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:32:27 by gomandam          #+#    #+#             */
/*   Updated: 2025/05/20 00:50:46 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and
calculate as follows:

        LCM(x, y) = | x * y | / HCF(x, y)

  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b);
*/

#include <stdio.h>

unsigned int	  lcm(unsigned int a, unsigned int b)
{
	unsigned int  temp_a, temp_b, gcd;
	
	if (a == 0 || b == 0)
		return (0);
	temp_a = a;
	temp_b = b;
	while (temp_b != 0)
	{
		unsigned int temp = temp_b;
		temp_b = temp_a % temp_b;
		temp_a = temp;
	}
	gcd = temp_a;
	return ((a / gcd) * b);
}

int	main(void)
{
	unsigned int    num1 = 4;
        unsigned int    num2 = 7;
        unsigned int    result = lcm(num1, num2);

        printf ("LCM of %u and %u is %u\n", num1, num2, result);
        return (0);
}
