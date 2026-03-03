/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vbc8.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 03:57:00 by gomandam          #+#    #+#             */
/*   Updated: 2026/02/26 03:57:07 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h> // MODIFIED: from <malloc.h>
#include <ctype.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

// REMOVED: node *n(**s);

node    *new_node(node n)
{
    node *ret = calloc(1, sizeof(node)); // MODIFIED: sizeof(node) instead of sizeof(n)
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void    destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of file\n"); // MODIFIED: "end of file" instead of "end of input"
}

int accept(char **s, char c)
{
    if (**s == c) // MODIFIED: check if **s == c, not just **s
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}

// ADDED: forward declaration
node *parse_expr(char **s); // MODIFIED: changed signature to char **s

// ADDED: parse_factor function
node *parse_factor(char **s)
{
    node *e;

    if (**s == '+' || **s == '*')
        return (new_node((node){VAL, 0, NULL, NULL}));
    if (isdigit(**s))
    {
        e = new_node((node){VAL, **s - '0', NULL, NULL});
        (*s)++;
        if (isdigit(**s))
            return (unexpected(**s), destroy_tree(e), NULL);
        return (e);
    }
    if (**s == '(')
    {
        (*s)++;
        e = parse_expr(s);
        if (!e)
            return (NULL);
        if (**s != ')')
            return (unexpected(**s ? **s : '('), destroy_tree(e), NULL);
        (*s)++;
        return (e);
    }
    if (**s == '\0')
        return (unexpected('\0'), NULL);
    unexpected(**s);
    return (NULL);
}

// ADDED: parse_term function
node *parse_term(char **s)
{
    node *l = parse_factor(s);
    if (!l)
        return (NULL);
    while (**s == '*')
    {
        (*s)++;
        node *r = parse_factor(s);
        if (!r)
            return (destroy_tree(l), NULL);
        node *tmp = new_node((node){MULTI, 0, l, r});
        if (!tmp)
            return (destroy_tree(l), destroy_tree(r), NULL);
        l = tmp;
    }
    return (l);
}

// MODIFIED: completed parse_expr implementation
node    *parse_expr(char **s) // MODIFIED: changed from char *s to char **s
{
    node *l = parse_term(s); // ADDED: parse first term
    if (!l) // ADDED: error check
        return (NULL);
    while (**s == '+') // ADDED: loop for additions
    {
        (*s)++;
        node *r = parse_term(s);
        if (!r)
            return (destroy_tree(l), NULL);
        node *tmp = new_node((node){ADD, 0, l, r});
        if (!tmp)
            return (destroy_tree(l), destroy_tree(r), NULL);
        l = tmp;
    }
    return (l); // MODIFIED: return l instead of ret
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
    return (0); // ADDED: default return
}

int main(int argc, char **argv)
{
    char *s; // ADDED: local pointer variable
    node *tree; // ADDED: declaration moved here
    
    if (argc != 2)
        return (1);
    s = argv[1]; // ADDED: initialize pointer
    if (*s == '\0') // ADDED: handle empty input
        return (printf("0\n"), 0);
    tree = parse_expr(&s); // MODIFIED: pass &s instead of argv[1]
    if (!tree)
        return (1);
    if (*s && !(*s == ')' && s[1] == '(')) // ADDED: check for trailing characters (except ")(" pattern)
        return (unexpected(*s), destroy_tree(tree), 1);
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
    return (0); // ADDED: explicit return
}
