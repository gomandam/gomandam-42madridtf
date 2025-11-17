/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 00:52:10 by gomandam          #+#    #+#             */
/*   Updated: 2025/05/22 11:15:28 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/
#include <stdio.h>
#include <stdlib.h>

char    **ft_split(char *str)
{
        int     a = 0;
        int     b;
        int     c = 0;
        char    **split;

        split = (char **)malloc(sizeof(char *) * 256);
        if (!split)
                return (0);
        while (str[a] == ' ' || str[a] == '\t' || str[a] == '\n')
                a++;
        while (str[a])
        {
                b = 0;
                split[c] = (char *)malloc(4096);
                if (!split[c])
                        return (0);
                while (str[a] && str[a] != ' ' && str[a] != '\t' && str[a] != '\n')
                        split[c][b++] = str[a++];
                split[c][b] = 0;
                while (str[a] == ' ' || str[a] == '\t' || str[a] == '\n')
                        a++;
                if (b)
                        c++;
        }
        split[c] = 0;
        return (split);
}

/*
int main() {
    char str[] = "   Esto es  un    ejemplo   de   split. ";
    char **result;
    int i;

    result = ft_split(str);

    if (!result) {
        fprintf(stderr, "Error al dividir la cadena.\n");
        return (1);
    }

    i = 0;
    while (result[i]) {
        printf("Palabra %d: '%s'\n", i, result[i]);
        free(result[i]); // Libera cada palabra
        i++;
    }

    free(result); // Libera el array de punteros

    return (0);
}
*/
