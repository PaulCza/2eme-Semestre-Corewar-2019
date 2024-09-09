/*
** EPITECH PROJECT, 2019
** sum_stdarg.c
** File description:
** réussis
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void switch_one(char nc, char *nl, va_list a)
{
    int n;
    switch (nc){
        case 'i':
            n = va_arg(a, int);
            my_put_nbr(n);
            my_putchar('\n');
            break;
        case 'c':
            nc = va_arg(a, int);
            my_putchar(nc);
            my_putchar('\n');
            break;
        case 's':
            nl = va_arg(a, char *);
            my_putstr(nl);
            my_putchar('\n');
            break;
        }
}

int disp_stdarg(char *s, ...)
{
    char *nl = malloc(sizeof(char) * 5);
    char nc;
    int i = 0;
    va_list a;

    va_start(a, s);
    for (; s[i] != '\0'; i++) {
        nc = s[i];
        switch_one(nc, nl, a);
    }
    va_end(a);
    return 0;
}