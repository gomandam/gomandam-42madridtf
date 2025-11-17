/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 01:32:33 by gomandam          #+#    #+#             */
/*   Updated: 2025/05/22 11:47:11 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

/*
#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int		n = nbr;
	int		len = (nbr <= 0) ? 1 : 0;
	char	*result;

	if (nbr == -2147483648)
	{
		result = (char *)malloc(12);
		if (!result)
			return (NULL);
		result[0] = '-';
		result[1] = '2';
		result[2] = '1';
		result[3] = '4';
		result[4] = '7';
		result[5] = '4';
		result[6] = '8';
		result[7] = '3';
		result[8] = '6';
		result[9] = '4';
		result[10] = '8';
		result[11] = '\0';
		return (result);
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nbr == 0)
		result[0] = '0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		result[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (result);
}
*/

#include <stdlib.h>
#include <stdio.h>

void ft_itoa_re(int n, char *str, int *i)
{
    if (n == -2147483648)
    {
        str[(*i)++] = '-';
        str[(*i)++] = '2';
        ft_itoa_re(147483648, str, i);
    }
    else
    {
        if (n < 0)
        {
            str[(*i)++] = '-';
            n = -n;
        }
        if (n > 9)
            ft_itoa_re(n / 10, str, i);
        str[(*i)++] = (n % 10) + '0';
    }
}
char *ft_itoa(int n)
{
    int i = 0;
    char *str;
    str = malloc(12);
    if (!str)
        return (NULL);
    ft_itoa_re(n, str, &i);
    str[i] = '\0';
    return (str);
}
/*
int     main(void)
{
    char *str;

    str = ft_itoa(0);
    printf("0 -> %s\n", str);
    free(str);

    str = ft_itoa(1);
    printf("1 -> %s\n", str);
    free(str);

    str = ft_itoa(42);
    printf("42 -> %s\n", str);
    free(str);

    str = ft_itoa(1001);
    printf("1001 -> %s\n", str);
    free(str);

    str = ft_itoa(-0);
    printf("0-> %s\n", str);
    free(str);

    str = ft_itoa(-2);
    printf("-2-> %s\n", str);
    free(str);

    str = ft_itoa(-24);
    printf("-24-> %s\n", str);
    free(str);

    str = ft_itoa(-2147483648);
    printf("-2147483648-> %s\n", str);
    free(str);

    str = ft_itoa(2147483647);
    printf("2147483647-> %s\n", str);
    free(str);

    return (0);
}
*/
