/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbc-annotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 07:20:15 by gomandam          #+#    #+#             */
/*   Updated: 2026/03/05 23:55:13 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* =========================================================================== */
/*  Compressed direct evaluation parser                                        */
/*  Compile:  cc -Wall -Wextra -Werror vbc-final.c -o vbc                      */
/*  Results: 15/15                                                             */
/*  CHANGELOG v3:                                                              */
/*    1. Removed <unistd.h> — unused                                           */
/*    2. Merged unexpected() inline — eliminated standalone function           */
/*    3. Collapsed parse_factor if/else into ternary error prints              */
/*    4. Removed tmp variables in parse_term/parse_expr                        */
/*    5. Replaced exit(1) with return — avoids disallowed function             */
/*    6. Propagated error via return -1 sentinel + check                       */
/* ========================================================================== */

/*  This version replaces exit() with a global error flag + returns,           */
/*  making it fully compliant with allowed functions list.                     */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static int g_err; /* ADDED: global error flag, replaces exit(1) */

static long	parse_expr(char **s); /* KEPT: forward declaration */

/* COMPRESSED: merged unexpected() into parse_factor directly */
/* COMPRESSED: removed else-if chain, used early returns */
static long	parse_factor(char **s)
{
	long	val;

	if (**s == '(')
	{
		(*s)++;
		val = parse_expr(s);
		if (g_err)                          /* ADDED: propagate error */
			return (0);
		if (**s != ')')                     /* KEPT: check closing paren */
		{
			/* COMPRESSED: ternary replaces if/else for error message */
			**s ? printf("Unexpected token '%c'\n", **s)
				: printf("Unexpected end of input\n");
			return (g_err = 1, 0);          /* CHANGED: set flag, return */
		}
		(*s)++;
		return (val);
	}
	if (isdigit(**s))                       /* COMPRESSED: removed else */
		return (val = **s - '0', (*s)++, val);
	/* COMPRESSED: ternary for error, flag instead of exit */
	**s ? printf("Unexpected token '%c'\n", **s)
		: printf("Unexpected end of input\n");
	return (g_err = 1, 0);
}

/* COMPRESSED: removed tmp variable, multiply directly */
static long	parse_term(char **s)
{
	long	val;

	val = parse_factor(s);
	while (**s == '*' && !g_err)            /* ADDED: stop on error */
	{
		(*s)++;
		val *= parse_factor(s);             /* COMPRESSED: no tmp */
	}
	return (val);
}

/* COMPRESSED: removed tmp variable, add directly */
static long	parse_expr(char **s)
{
	long	val;

	val = parse_term(s);
	while (**s == '+' && !g_err)            /* ADDED: stop on error */
	{
		(*s)++;
		val += parse_term(s);               /* COMPRESSED: no tmp */
	}
	return (val);
}

/* COMPRESSED: merged trailing-char check with ternary error */
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
		return (printf("Unexpected token '%c'\n", *s), 1);
	printf("%ld\n", result);                /* COMPRESSED: merged return */
	return (0);
}

/*
Expression = Term + Term + Term ...
Term       = Factor * Factor * Factor ...
Factor     = digit | (Expression)

expr  parses +  (sum of terms)
term  parses *  (product of factors)
Factor parses digits and ()

Deeper in call chain = higher precedence:
  parse_expr → parse_term → parse_factor
  (lowest)                   (highest)
*/
