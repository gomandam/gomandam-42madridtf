/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:03:02 by gomandam          #+#    #+#             */
/*   Updated: 2025/04/11 13:22:04 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : search_and_replace
Expected files   : search_and_replace.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program called search_and_replace that takes 3 arguments, the first 
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.

Examples:
$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre
$>./search_and_replace "zaz" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
ZaZ eT David aiME le METal.$
$>./search_and_replace "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" | cat -e
eNcOre Un ExEmPle Pas Facile a Ecrire $
*/

#include <unistd.h>

int	main(int ac, char *av[])
{
	int	i = 0;

	if (ac != 4)
	{
		write(1, "\n", 3);
		return(0);
	}
	if (!av[2][1] && av[3][1] == '\0')
	{
		while (av[1][i] != '\0')
		{
			if (av[1][i] == av[2][0])
			{
				av[1][i] = av[3][0];
				write(1, &av[1][i++], 1);
			}
			else
				write(1, &av[1][i++], 1);
		}
	}
	write(1, "\n", 2);
}

/*
Concepts:
	if the value is not zero, it is 1.
	but NULL can also be zero. 

Assuming:
	int value = 0;
	printf("value = %d", !value);
	value = 1

Alternative Solutions:
	1. You can use strlen in the exam. or
	2. Check if argv[i][1] == '\0', therefore, ensures that only one character
       		since index 0 = chracter1 and 1 = NULL or '\0'
	3. Review of (argv[i] = strlen - 1;)
*/

/* SHORT-ALTERNATIVE
#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;

    if (argc == 4 && !argv[2][1] && !argv[3][1])
    {
        while(argv[1][i])
        {
            if (argv[1][i] == argv[2][0])
                argv[1][i] = argv[3][0];
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}
*/

/* MAKING A FUNCTION
#include <unistd.h>
void    search_and_replace(char *str, char search, char replace)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == search)
            write(1, &replace, 1);
        else
            write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 4) 							// Ensure 3 arguments only
    {
        if (argv[2][1] == '\0' && argv[3][1] == '\0')			// 2nd && 3rd args == 1 character
            search_and_replace(argv[1], argv[2][0], argv[3][0]);
    }
    write(1, "\n", 1);
    return (0);
}
*/
