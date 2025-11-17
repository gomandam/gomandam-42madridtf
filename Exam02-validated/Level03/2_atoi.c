/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:21:17 by gomandam          #+#    #+#             */
/*   Updated: 2025/05/19 20:51:03 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Short version of ATOI
// No negative, No whitespaces, No underflow/overflow, No validation

#include <unistd.h>

int	short_atoi(char *str)
{
	int	idx;
	int	res;

	idx = 0;
	res = 0;
	while (str[idx] != '\0')
	{
		res *= 10;
		res += str[idx] - '0';
		idx++;
	}
	return (res);
}
