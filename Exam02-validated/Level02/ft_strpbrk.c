/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:48:47 by gomandam          #+#    #+#             */
/*   Updated: 2025/05/09 23:49:56 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);
*/

#include <stdio.h>
#include <unistd.h>

char    *ft_strpbrk(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (NULL);
	while (*s1)
	{
		size_t	i = 0;
		while (s2[i])
		{
			if (*s1 == s2[i])
				return (char *) s1;
			i++;
		}
		s1++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	scan[] = "ABC";
	char	*str = "CDE";

	printf("ft_strpbrk: %s", ft_strpbrk(scan, str));
	printf("\n");
	return (0);
}
*/
