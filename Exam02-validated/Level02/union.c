/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 01:32:07 by gomandam          #+#    #+#             */
/*   Updated: 2025/05/09 01:33:22 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>
/*
int main(int ac, char **av)
{
    if (ac == 3)
    {
        unsigned char seen[256] = {0}; // Array to track seen characters
        int i = 0;

        // Process the first string
        while (av[1][i])
        {
            if (!seen[(unsigned char)av[1][i]])
            {
                write(1, &av[1][i], 1);
                seen[(unsigned char)av[1][i]] = 1; // Mark character as seen
            }
            i++;
        }

        // Process the second string
        i = 0; // Reset index for the second string
        while (av[2][i])
        {
            if (!seen[(unsigned char)av[2][i]])
            {
                write(1, &av[2][i], 1);
                seen[(unsigned char)av[2][i]] = 1; // Mark character as seen
            }
            i++;
        }
    }
    write(1, "\n", 1); // Print newline
    return (0);
}
*/
int main(int ac, char **av)
{
    unsigned char seen[256] = {0};
    int i = 0;

    if (ac == 3)
    {
        while (*av[1] || av[2][i]) 
        {
            if (*av[1] && !seen[(unsigned char)*av[1]])
                seen[(unsigned char)*av[1]] = write(1, av[1], 1);
            if (*av[1])	 av[1]++;
            else if (av[2][i] && !seen[(unsigned char)av[2][i]])
                seen[(unsigned char)av[2][i]] = write(1, &av[2][i], 1);
            if (av[2][i])  i++;
        }
    }
    write(1, "\n", 1);
}
