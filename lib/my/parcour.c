/*
** EPITECH PROJECT, 2019
** my_transformnbr.c.c
** File description:
** réussis
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void first(char nm, va_list a)
{
    int n;
    char *nl;
    char nc;

    switch (nm) {
        case 'i':
            n = va_arg(a, int);
            my_put_nbr(n);
            break;
        case 'c':
            nc = va_arg(a, int);
            my_putchar(nc);
            break;
        case 's':
            nl = va_arg(a, char *);
            my_putstr(nl);
            break;
    }
}

void sec(char nm, va_list a)
{
    int n;
    char *nl;

    switch (nm) {
        case 'X':
            n = va_arg(a, int);
            nl = malloc(sizeof(char) * n);
            nl = my_convhexa_maj(n);
            my_putstr(nl);
            break;
        case 'b':
            n = va_arg(a, int);
            nl = malloc(sizeof(char) * n);
            nl = my_to_binary(n);
            my_putstr(nl);
            break;
    }
}

void parcour(char nm, va_list a)
{
    first(nm, a);
    sec(nm, a);
    three(nm, a);
    four(nm, a);
}

void parcour_with_number(char nm, va_list a, char *nv)
{
    int n;
    char *nl = malloc(sizeof(char) * my_strlen(nv));
    int i = 0;
    int j = 0;
    while (is_a_nbr(nv[j]) != -1) {
        nl[j] = nv[j];
        j++;
    }
    i = my_getnbr(nl);
    n = j;
    for (j = 0; j < i; j++)
        my_putchar(' ');
    parcour(nv[n], a);
}