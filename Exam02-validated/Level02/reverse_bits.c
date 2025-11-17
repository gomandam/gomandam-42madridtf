/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:49:08 by gomandam          #+#    #+#             */
/*   Updated: 2025/05/20 19:13:25 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
*/

#include <unistd.h>
/*
unsigned char	reverse_bits(unsigned char octet)
{
	return ((octet & 1) << 7) |  ((octet & 2) << 5) |  ((octet & 4) << 3) | 
		((octet & 8) << 1) | ((octet & 16) >> 1) |  ((octet & 32) >> 3) |
		((octet & 64) >> 5) |  ((octet & 128) >> 7); 
}
*/

unsigned char   reverse_bits(unsigned char octet)
{
	int			i = 0;
	unsigned char	res = 0;

	while (i < 8)
	{
		res = (res << 1) | (octet & 1);
		octet >>= 1;
		i++;
	}
	return (res);
}

int	main(void)
{
	unsigned char	octet;
	unsigned char	reversed;

	octet = 2; 				// 00000010
	reversed = reverse_bits(octet);
	write(1, &reversed, 1); 		// Output: '\x40' (01000000)
	return (0);
}
