/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbc-compressed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 07:20:15 by gomandam          #+#    #+#             */
/*   Updated: 2026/03/03 23:48:03 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static int g_err;
static long	parse_expr(char **s);

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
		{
			**s ? printf("Unexpected token '%c'\n", **s)
			    : printf("Unexpected end of input\n");
			return (g_err = 1, 0);
		}
		(*s)++;
		return (val);
	}
	if (isdigit(**s))
		return (val = **s - '0', (*s)++, val);
	**s ? printf("Unexpected token '%c'\n", **s)
	    : printf("Unexpected end of input\n");
	return (g_err = 1, 0);
}

static long	parse_term(char **s)
{
	long	val;

	val = parse_factor(s);
	while (**s == '*' && !g_err)
	{
		(*s)++;
		val *= parse_factor(s);
	}
	return (val);
}

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
	g_err = 0;
	result = parse_expr(&s);
	if (g_err)
		return (1);
	if (*s)
		return (printf("Unexpected token '%c'\n", *s), 1);
	printf("%ld\n", result);
	return (0);
}
