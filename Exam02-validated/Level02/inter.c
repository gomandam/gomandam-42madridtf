/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 02:46:52 by gomandam          #+#    #+#             */
/*   Updated: 2025/05/10 03:00:27 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	unsigned char seen[256] = {0};

	if (ac == 3)
	{
		for (int a = 0; av[1][a]; a++)
		{
			if (!seen[(unsigned char)av[1][a]])
			{
				for (int b = 0; av[2][b]; b++)
				{
					if (av[1][a] == av[2][b])
					{
						write(1,&av[1][a],1);
						seen[(unsigned char) av[1][a]] = 1;
						break;
					}
				}
			}
		}
	}
	write(1,"\n",1);
	return(0);
}
