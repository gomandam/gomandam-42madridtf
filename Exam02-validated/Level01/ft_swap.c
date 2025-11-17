/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:49:14 by gomandam          #+#    #+#             */
/*   Updated: 2025/06/01 00:06:30 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(int argc, char *argv[])
{
	int	xvalue;
	int	yvalue;

	printf("Initial valuesn %d\n", argc);
	usleep(10000000);
	if (argc != 3)
		return (printf("\nUtilization: 	./ft_swap.out [x] [y]\n\n"), 1);
	xvalue = atoi(argv[1]);
	yvalue = atoi(argv[2]);
	printf("Initial values of x and y are your input.\n");
	printf("Input x = %d and Input y = %d\n", xvalue, yvalue);
	ft_swap(&xvalue, &yvalue);
	printf("---------------------------\n");
	printf("Values of [x] and [y] are now interchanged.\n");
	printf(">> xvalue = %d\n>> yvalue = %d\n", xvalue, yvalue);
	return (0);
}
/*
int	main(void)
{
	int	x;
	int	y;

	x = 40;
	y = 60;
	ft_swap(&x,&y);
	printf("x was 40, and now it is %d.\n", x);
	printf("y was 60, and now it is %d.\n", y);
	return (0);
}
*/
