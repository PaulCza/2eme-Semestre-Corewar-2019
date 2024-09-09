/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** réussis
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

typedef struct print
{
    char nm;
    char *nv;
    int i;
    va_list a;
    int j;
} print;

print init_printf(print res, char *s)
{
    res.nv = malloc(sizeof(char) * my_strlen(s));
    res.i = 0;
    res.j = 0;
    return res;
}

void my_printf_suite(print *f, char *s)
{
    if (s[f->i] == '%') {
        f->i = f->i + 1;
        f -> nm = s[f->i];
        if (is_a_nbr(f->nm) == -1)
            parcour(f->nm, f->a);
        else if (is_a_nbr(f->nm) != -1) {
            while (is_a_nbr(f->nm) != -1) {
            f->nm = s[f->i];
            f->i = f->i + 1;
            f->nv[f->j] = f->nm;
            f->j = f->j + 1;
        }
        f->nv[f->j += 1] = s[f->i+1];
        parcour_with_number(f->nm, f->a, f->nv);
        }
    }
}

int my_printf(char *s, ...)
{
    print f;

    f = init_printf(f, s);
    va_start(f.a, s);
    for (; s[f.i] != '\0'; f.i++) {
        if (s[f.i] != '%')
            my_putchar(s[f.i]);
        my_printf_suite(&f, s);
    }
    va_end(f.a);
    return 0;
}