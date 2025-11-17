/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 02:57:36 by gomandam          #+#    #+#             */
/*   Updated: 2025/04/13 03:26:37 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	int	i = 0;
	while (s[i++] != '\0');
	return (i);
}

int	main(void)
{
	char	*str = "string.";
	return (write(1, str, ft_strlen(str)));
}
