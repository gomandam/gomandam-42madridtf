/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbc-v10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 07:20:15 by gomandam          #+#    #+#             */
/*   Updated: 2026/03/06 00:28:11 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =========================================================================== */
/*  Compressed direct evaluation parser                                        */
/*  Compile:  cc -Wall -Wextra -Werror vbc-final.c -o vbc                      */
/*  Changelog:                                                                 */
/*    1. Void function for unexpected()                                        */
/*    2. Merged unexpected() inline — eliminated standalone function           */
/*    3. Collapsed parse_factor if/else into ternary error prints              */
/*    4. Removed tmp variables in parse_term/parse_expr                        */
/*    5. Replaced exit(1) with return, and used a global variable              */
/*    6. Propagated error via return -1 		                       */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static int	g_err;
static long	parse_expr(char **s);

static void	unexpected(char c)
{
	c ? printf("Unexpected token '%c'\n", c)
	  : printf("Unexpected end of input\n");
	g_err = 1;
}

static long	parse_factor(char **s)
{
	long	val;

	if (**s == '(')
	{
		(*s)++;
		val = parse_expr(s);
		if (g_err)
			return (0);
		if (**s != ')')
			return (unexpected(**s), 0);   // set flag, return
		(*s)++;
		return (val);
	}
	if (isdigit(**s))
		return (val = **s - '0', (*s)++, val);
	return (unexpected(**s), 0);
}

static long	parse_term(char **s)
{
	long	val;

	val = parse_factor(s);
	while (**s == '*' && !g_err)		// ADDED: stop on error
	{
		(*s)++;
		val *= parse_factor(s);		// COMPRESSED: no tmp
	}
	return (val);
}

/* removed tmp variable, add directly */
static long	parse_expr(char **s)
{
	long	val;

	val = parse_term(s);
	while (**s == '+' && !g_err)
	{
		(*s)++;
		val += parse_term(s);
	}
	return (val);
}

int	main(int ac, char *av[])
{
	long	result;
	char	*s;

	if (ac != 2)
		return (1);
	s = av[1];
	g_err = 0;                              /* ADDED: init error flag */
	result = parse_expr(&s);
	if (g_err)                              /* ADDED: check parse error */
		return (1);
	if (*s)                                 /* KEPT: reject trailing chars */
		return (unexpected(*s), 1);
	printf("%ld\n", result);                /* COMPRESSED: merged return */
	return (0);
}

/*
Expression = Term + Term + Term ...
Term       = Factor * Factor * Factor ...
Factor     = digit | (Expression)

expr  parses + (sum of terms)
term  parses * (product of factors)
Factor parses digits and ()

Deeper in call chain = higher precedence:
(lowest) parse_expr -> parse_term -> parse_factor (highest)
*/
